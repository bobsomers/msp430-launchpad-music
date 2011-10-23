/*
 * Bob Somers 2011 
 *   http://bobsomers.com
 *
 * Released under the Beerware License
 *   http://en.wikipedia.org/wiki/Beerware
 *
 * Made for the TI MSP430 LaunchPad
 *   http://ti.com/launchpadwiki
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

/*
 * ============================ SELECT YOUR SONG ============================
 * Uncomment ONE (1) of the lines below to select which song you would like
 * to load onto your MSP 430. The reason you can only select ONE (1) is due
 * to the limited amount of code space available on the chips that come with
 * the LaunchPad kit. If you have a beefier chip and want to load longer songs,
 * by all means go for it!
 */

#include "songs/princess_slide.c"
/* #include "songs/bobomb_battlefield.c" */
/* #include "songs/super_mario.c" */

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

void __attribute__((interrupt (TIMERA0_VECTOR))) timer_sound_isr() {
    /* Push the timer forward by one note cycle. */
    TACCR0 += current_note;

    /* Output to the speaker if sound is enabled. */
    if (sound_enabled) {
        SPEAKER_OUT ^= SPEAKER;
    }
}

void __attribute__((interrupt (TIMERA1_VECTOR))) timer_elapsed_isr() {
    switch (TAIV) {
        case 2: /* CCR1 */
            TACCR1 += 1000; /* 1 ms */
            ms_elapsed++;
            break;
    }
}

int main() {
    /* Initialize the system. */
    init();

    while (1) {
        /* Red LED on. Green LED off. */
        LED_OUT |= LED_RED;
        LED_OUT &= ~LED_GREEN;
        
        /* Wait for button press. */
        while (BUTTON_IN & BUTTON);
        
        /* Red LED off. Green LED on. */
        LED_OUT &= ~LED_RED;
        LED_OUT |= LED_GREEN;
        
        /* These functions must be implemented by the selected song. */
        song_setup();
        song_play();
    }
    
    return 0;
}
