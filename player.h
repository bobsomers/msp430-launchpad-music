// Bob Somers 2011
//     http://bobsomers.com
//
// Made for the TI MSP430 LaunchPad
//     http://ti.com/launchpadwiki
//
// Released under the Beerware License
//     http://en.wikipedia.org/wiki/Beerware
//
// NOTE: I wrote this using MSPGCC on Linux. I'm pretty sure I used some
// defines that are MSPGCC-only (i.e. not defined in the TI Windows
// software tools). I don't really want to bother with installing it and
// figuring out what needs to change, so free internet cookies to the
// first person who submits a patch that makes it work in both.


#ifndef _PLAYER
#define _PLAYER

// define led port connections
#define LED_RED BIT0
#define LED_GREEN BIT6
#define LED_DIR P1DIR
#define LED_OUT P1OUT

// define button connections
#define BUTTON BIT3
#define BUTTON_DIR P1DIR
#define BUTTON_IN P1IN

// define speaker connections
#define SPEAKER BIT7
#define SPEAKER_DIR P1DIR
#define SPEAKER_OUT P1OUT

// the number of milliseconds to kill the note before the duration expires
// (leaves a nice gap between back-to-back notes)
#define DEAD_TIME_MS 20

// assuming 4/4 time, this is how many ticks we subdivide the beat into, so
// in other words, 4 ticks per beat gives us 16th note resolution
// we then define all note duration in lengths of 16th note "ticks"
#define TICKS_PER_BEAT 4

// note definitions
// (1,000,000 Hz / note frequency / 2)
#define E3 3033
#define Fs3 2703
#define G3 2551
#define Gs3 2408
#define A3 2273
#define As3 2145
#define B3 2025
// TODO
#define Cb4 
#define C4 1911
#define Cs4 1804
#define Db4 1804
#define D4 1703
#define Ds4 1607
#define Eb4 1607
#define E4 1517
#define F4 1432
#define Fs4 1351
#define Gb4 1351
#define G4 1276
#define Gs4 1204
#define Ab4 1204
#define A4 1136
#define As4 1073
#define Bb4 1073
#define B4 1012
#define C5 956
#define Cs5 902
#define Db5 902
#define D5 851
#define Ds5 804
#define Eb5 804
#define E5 758
#define F5 716
#define Fs5 676
#define Gb5 676
#define G5 638
#define Gs5 602
#define Ab5 602
#define A5 568

#endif
