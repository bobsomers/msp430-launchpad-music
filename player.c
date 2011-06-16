// Bob Somers 2011
//     http://bobsomers.com
//
// Made for the TI MSP430 LaunchPad
//     http://ti.com/launchpadwiki
//
// Released under the Beerware License
//     http://en.wikipedia.org/wiki/Beerware
//

#include <io.h>
#include <signal.h>
#include "player.h"


// turns the sound output on or off
volatile unsigned int sound_enabled = 0;

// keeps track of the current note we're playing
volatile unsigned int current_note = A4;

// keeps track of the number of ms elapsed
volatile unsigned int ms_elapsed = 0;

// the number of milliseconds per "tick" in the music (see TICKS_PER_BEAT)
unsigned int ms_per_tick = 0;

// initializes the various peripherals
void init() {
    // stop the watchdog
    WDTCTL = WDTPW | WDTHOLD; 

    // set the system clock to 1 MHz
    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;

    // initialize leds (output) and button (input)
    LED_DIR |= LED_RED;
    LED_DIR |= LED_GREEN;
    BUTTON_DIR &= ~BUTTON;

    // initialize speaker (output)
    SPEAKER_DIR |= SPEAKER;
    
    // initialize the timer
    TACTL |= TASSEL_SMCLK | ID_DIV1 | MC_CONT | TAIE;
    TACCTL0 |= CCIE;
    TACCTL1 |= CCIE;

    // enable interrupts globally
    WRITE_SR(GIE);
}

void set_bpm(unsigned int bpm) {
    // compute the number of ms per tick from the beats per minute
    ms_per_tick = 60000 / (TICKS_PER_BEAT * bpm);
}

// plays the passed note for the given duration (in ticks, see TICKS_PER_BEAT)
// blocks until the note is over 
void play(unsigned int note, unsigned int duration_ticks) {
    unsigned int duration_ms = 0;

    // compute the duration (in ms)
    duration_ms = duration_ticks * ms_per_tick;

    // set the current note
    current_note = note;

    // enable the sound ouput
    sound_enabled = 1;

    // reset the elapsed counter
    ms_elapsed = 0;

    // green led on
    LED_OUT |= LED_GREEN;

    // wait for the note duration to expire
    while (ms_elapsed < duration_ms - DEAD_TIME_MS);

    // disable sound output
    sound_enabled = 0;

    // green led off
    LED_OUT &= ~LED_GREEN;

    // wait for the full duration to expire
    while (ms_elapsed < duration_ms);
}

// rests for the given duration
// exactly the same as playing, except we just leave sound disabled the whole time
void rest(unsigned int duration_ticks) {
    unsigned int duration_ms = 0;

    // compute the duration (in ms)
    duration_ms = duration_ticks * ms_per_tick;

    // no sound! we're resting...
    sound_enabled = 0;

    // reset the elapsed counter
    ms_elapsed = 0;

    // wait for the rest duration to expire
    while(ms_elapsed < duration_ms);
}

// CCR0 timer interrupt handler (note signal)
interrupt(TIMERA0_VECTOR) timer_sound_isr() {
    // push the timer forward by one note cycle 
    TACCR0 += current_note;

    // output to the speaker if sound is enabled
    if (sound_enabled) {
        SPEAKER_OUT ^= SPEAKER;
    }
}

// TAIV timer interrupt handler (elapsed time counting)
interrupt(TIMERA1_VECTOR) timer_elapsed_isr() {
    switch (TAIV) {
        case 2: // CCR1
            TACCR1 += 1000; // 1 ms
            ms_elapsed++;
            break;
    }
}

//select the song here. Be sure to only call 1 song at a time
//This source include in the middle of nowhere will be fixed.
#include "mario_theme.c"

int main() {
    // initialize the system
    init();

    while (1) {
        // red led on
        LED_OUT |= LED_RED;
        
        // wait for button press
        while (BUTTON_IN & BUTTON);
        
        // red led off
        LED_OUT &= ~LED_RED;
		
		//Both of these functions have to be implemented in the song source,
		//which is loaded just before the main. 
		song_setup();
		song_play();
    }
    
    return 0;
}
