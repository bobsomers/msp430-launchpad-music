/*
 * Bob Somers 2011 
 *   http://bobsomers.com
 *
 * Released under the Beerware License
 *   http://en.wikipedia.org/wiki/Beerware
 */

#ifndef PLAYER_H_
#define PLAYER_H_

/* Define led port connections. */
#define LED_RED BIT0
#define LED_GREEN BIT6
#define LED_DIR P1DIR
#define LED_OUT P1OUT

/* Define button connections. */
#define BUTTON BIT3
#define BUTTON_DIR P1DIR
#define BUTTON_IN P1IN

/* Define speaker connections. */
#define SPEAKER BIT7
#define SPEAKER_DIR P1DIR
#define SPEAKER_OUT P1OUT

/* The number of milliseconds to kill the note before the duration expires.
 * This leaves a nice gap between back-to-back notes. */
#define DEAD_TIME_MS 20

/* Assuming 4/4 time, this is how many ticks we subdivide the beat into. So
 * in other words, 4 ticks per beat gives us 16th note resolution. We then
 * define all note durations in lengths of these 16th note "ticks". */
#define TICKS_PER_BEAT 4

/* Note definitions, calculated with 1,000,000 Hz / note frequency / 2. */
#define E3 3033
#define Fs3 2703
#define G3 2551
#define Gs3 2408
#define A3 2273
#define As3 2145
#define B3 2025
/* TODO: More notes as necessary. */
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
