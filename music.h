/*
 * Bob Somers 2011 
 *   http://bobsomers.com
 *
 * Released under the Beerware License
 *   http://en.wikipedia.org/wiki/Beerware
 */

#ifndef MUSIC_H_
#define MUSIC_H_

/* The number of milliseconds to kill the note before the duration expires.
 * This leaves a nice gap between back-to-back notes. */
#define DEAD_TIME_MS 20

/* Assuming 4/4 time, this is how many ticks we subdivide the beat into. So
 * in other words, 4 ticks per beat gives us 16th note resolution. We then
 * define all note durations in lengths of these 16th note "ticks". */
#define TICKS_PER_BEAT 4

/* Note definitions, calculated with 1,000,000 Hz / note frequency / 2.
 * TODO: Add more notes as necessary. */
#define E3 3033
#define Fs3 2703
#define G3 2551
#define Gs3 2408
#define A3 2273
#define As3 2145
#define B3 2025
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

/* Turns the sound output on or off. */
extern volatile unsigned int sound_enabled;

/* Keeps track of the current note we're playing. */
extern volatile unsigned int current_note;

/* Keeps track of the number of ms elapsed. */
extern volatile unsigned int ms_elapsed;

/*
 * Sets the tempo in BPM (beats per minute) at which the music will play back.
 */
void set_bpm(unsigned int bpm);

/*
 * Plays the passed note for the given duration (in ticks, see TICKS PER BEAT).
 * Blocks until the note is over.
 */
void play(unsigned int note, unsigned int duration_ticks);

/*
 * Rests for the given duration. Exactly the same as playing, except we just
 * don't play a note for the duration.
 */
void rest(unsigned int duration_ticks);

#endif //  MUSIC_H_
