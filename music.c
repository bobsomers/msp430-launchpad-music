/*
 * Bob Somers 2011 
 *   http://bobsomers.com
 *
 * Released under the Beerware License
 *   http://en.wikipedia.org/wiki/Beerware
 */

#include "music.h"

/* Some resonable defaults. */
volatile unsigned int sound_enabled = 0;
volatile unsigned int current_note = A4;
volatile unsigned int ms_elapsed = 0;

/* The number of milliseconds per "tick" in the music (see TICKS_PER_BEAT). */
static unsigned int ms_per_tick = 0;

void set_bpm(unsigned int bpm) {
    /* Compute the number of ms per tick from the beats per minute. */
    ms_per_tick = 60000 / (TICKS_PER_BEAT * bpm);
}

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

    /* Wait for the note duration to expire. */
    while (ms_elapsed < duration_ms - DEAD_TIME_MS);

    /* Disable sound output. */
    sound_enabled = 0;

    /* Wait for the full duration to expire. */
    while (ms_elapsed < duration_ms);
}

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
