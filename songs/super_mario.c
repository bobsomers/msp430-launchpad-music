/*
 * Sergio Campama 2011 
 *   http://kaipi.me
 *
 * Released under the Beerware License
 *   http://en.wikipedia.org/wiki/Beerware
 *
 * Super Mario Theme
 */

/*
 * ALL SONGS MUST IMPLEMENT song_setup() AND song_play()!
 */

void song_setup() {
    set_bpm(150);
}

void song_measure_1() {
    play(E4, 1);
    play(E4, 1);
    rest(1);
    play(E4, 1);
    rest(1);
    play(C4, 1);
    play(E4, 1);
    rest(1);
    play(G4, 1);
    rest(3);
    play(G3, 1);
    rest(3);
}

void song_measure_2() {
    play(C4, 1);
    rest(2);
    play(G3, 1);
    rest(2);
    play(E3, 1);
    rest(2);
    play(A3, 1);
    rest(1);
    play(B3, 1);
    rest(1);
    play(As3, 1);
    play(A3, 1);
    rest(1);
}

void song_measure_3() {
    play(G3, 1);
    play(E4, 1);
    rest(1);
    play(G4, 1);
    play(A4, 1);
    rest(1);
    play(F4, 1);
    play(G4, 1);
    rest(1);
    play(E4, 1);
    rest(1);
    play(C4, 1);
    play(D4, 1);
    play(B3, 1);
    rest(2);
}

void song_measure_4() {
    rest(2);
    play(G4, 1);
    play(Fs4, 1);
    play(F4,1);
    play(Ds4, 1);
    rest(1);
    play(E4, 1);
    rest(1);
    play(Gs3, 1);
    play(A3, 1);
    play(C4, 1);
    rest(1);
    play(A3, 1);
    play(C4, 1);
    play(D4, 1);
}

void song_measure_5() {
    rest(2);
    play(G4, 1);
    play(Fs4, 1);
    play(F4,1);
    play(Ds4, 1);
    rest(1);
    play(E4, 1);
    rest(1);
    play(C5, 1);
    rest(1);
    play(C5, 1);
    play(C5, 1);
    rest(3);
}

void song_measure_6() {
    rest(2);
    play(Eb4, 1);
    rest(2);
    play(D4, 1);
    rest(2);
    play(C4, 1);
    rest(7);
}

void song_measure_7() {
    play(C4, 1);
    play(C4, 1);
    rest(1);
    play(C4, 1);
    rest(1);
    play(C4, 1);
    play(D4, 1);
    rest(1);
    play(E4, 1);
    play(C4, 1);
    rest(1);
    play(A3, 1);
    play(G3, 1);
    rest(3);
}

void song_measure_8() {
    play(C4, 1);
    play(C4, 1);
    rest(1);
    play(C4, 1);
    rest(1);
    play(C4, 1);
    play(D4, 1);
    play(E4,1);
    rest(7);
}

void song_play() {
    song_measure_1();
    song_measure_2();
    song_measure_3();
    song_measure_2();
    song_measure_3();
    song_measure_4();
    song_measure_5();
    song_measure_4();
    song_measure_6();
    song_measure_4();
    song_measure_5();
    song_measure_4();
    song_measure_6();
    song_measure_7();
    song_measure_8();
    song_measure_7();
}
