/*
 * Bob Somers 2011 
 *   http://bobsomers.com
 *
 * Made for the TI MSP430 LaunchPad
 *   http://ti.com/launchpadwiki
 *
 * Released under the Beerware License
 *   http://en.wikipedia.org/wiki/Beerware
 *
 * NOTE: I wrote this using MSPGCC on Linux. I'm pretty sure I used some
 * defines that are MSPGCC-only (i.e. not defined in the TI Windows software
 * tools). I don't really want to bother with installing it and figuring out
 * what needs to change, so free internet cookies to the first person who
 * submits a patch that makes it work in both.
 *
 * NOTE: As of 2011-10-23, this has been updated for MSPGCC's new "Uniarch",
 * and has been tested with version 4.5.3. If you're using an older version,
 * you may need to replace <msp430.h> with <io.h> and <signal.h>. I'm really
 * not 100% sure, because I don't have an older version around to test with. As
 * above, patches are appreciated.
 * 
 * More info about the Uniarch transition here:
 *   http://sourceforge.net/apps/mediawiki/mspgcc/index.php?title=Devel:Uniarch
 */

#include <msp430.h>

#include "player.h"

/* Turns the sound output on or off. */
volatile unsigned int sound_enabled = 0;

/* Keeps track of the current note we're playing. */
volatile unsigned int current_note = A4;

/* Keeps track of the number of ms elapsed. */
volatile unsigned int ms_elapsed = 0;

/* The number of milliseconds per "tick" in the music (see TICKS_PER_BEAT). */
unsigned int ms_per_tick = 0;

/* Initializes the various peripherals. */
void init() {
    /* Stop the watchdog. */
    WDTCTL = WDTPW | WDTHOLD; 

    /* Set the system clock to 1 MHz. */
    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;

    /* Initialize LEDs (output) and button (input). */
    LED_DIR |= LED_RED;
    LED_DIR |= LED_GREEN;
    BUTTON_DIR &= ~BUTTON;

    /* Initialize speaker (output). */
    SPEAKER_DIR |= SPEAKER;
    
    /* Initialize the timer. */
    TACTL |= TASSEL_2 | ID_0 | MC_2 | TAIE;
    TACCTL0 |= CCIE;
    TACCTL1 |= CCIE;

    /* Enable interrupts globally. */
    WRITE_SR(GIE);
}

void set_bpm(unsigned int bpm) {
    /* Compute the number of ms per tick from the beats per minute. */
    ms_per_tick = 60000 / (TICKS_PER_BEAT * bpm);
}

/* Plays the passed note for the given duration (in ticks, see TICKS_PER_BEAT)
 * blocks until the note is over. */
void play(unsigned int note, unsigned int duration_ticks) {
    unsigned int duration_ms = 0;

    /* Compute the duration (in ms). */
    duration_ms = duration_ticks * ms_per_tick;

    /* Set the current note. */
    current_note = note;

    /* Enable the sound ouput. */
    sound_enabled = 1;

    /* Reset the elapsed counter. */
    ms_elapsed = 0;

    /* Green LED on. */
    LED_OUT |= LED_GREEN;

    /* Wait for the note duration to expire. */
    while (ms_elapsed < duration_ms - DEAD_TIME_MS);

    /* Disable sound output. */
    sound_enabled = 0;

    /* Green LED off. */
    LED_OUT &= ~LED_GREEN;

    /* Wait for the full duration to expire. */
    while (ms_elapsed < duration_ms);
}

/* Rests for the given duration. Exactly the same as playing, except we just
 * leave sound disabled the whole time */
void rest(unsigned int duration_ticks) {
    unsigned int duration_ms = 0;

    /* Compute the duration (in ms). */
    duration_ms = duration_ticks * ms_per_tick;

    /* No sound! We're resting... */
    sound_enabled = 0;

    /* Reset the elapsed counter. */
    ms_elapsed = 0;

    /* Wait for the rest duration to expire. */
    while(ms_elapsed < duration_ms);
}

/* CCR0 timer interrupt handler (note signal). */
void __attribute__((interrupt (TIMERA0_VECTOR))) timer_sound_isr() {
    /* Push the timer forward by one note cycle. */
    TACCR0 += current_note;

    /* Output to the speaker if sound is enabled. */
    if (sound_enabled) {
        SPEAKER_OUT ^= SPEAKER;
    }
}

/* TAIV timer interrupt handler (elapsed time counting). */
void __attribute__((interrupt (TIMERA1_VECTOR))) timer_elapsed_isr() {
    switch (TAIV) {
        case 2: /* CCR1 */
            TACCR1 += 1000; /* 1 ms */
            ms_elapsed++;
            break;
    }
}

/* Select the song here (be sure to only call 1 song at a time). */
/* TODO: Clean this up. */
#include "songs/mario_theme.c"

int main() {
    /* Initialize the system. */
    init();

    while (1) {
        /* Red LED on. */
        LED_OUT |= LED_RED;
        
        /* Wait for button press. */
        while (BUTTON_IN & BUTTON);
        
        /* Red LED off. */
        LED_OUT &= ~LED_RED;
        
        /* Both of these functions have to be implemented in the song source,
         * which is loaded just before the main. */
        song_setup();
        song_play();
    }
    
    return 0;
}
