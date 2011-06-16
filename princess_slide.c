// Bob Somers 2011
//     http://bobsomers.com
//
// Made for the TI MSP430 LaunchPad
//     http://ti.com/launchpadwiki
//
// Released under the Beerware License
//     http://en.wikipedia.org/wiki/Beerware
//


// theme from the princess slide in super mario 64
void song_setup()
{
	set_bpm(180);
}

void play_song() {
    // measure 1
    play(A5, 4);
    play(A3, 4);
    play(A5, 4);
    play(A3, 4);
	
    // measure 2
    play(A5, 4);
    play(Fs5, 4);
    play(E5, 4);
    play(Ds5, 4);
	
    // measure 3
    play(D5, 2);
    play(G3, 2);
    play(B3, 2);
    play(G3, 2);
    play(D5, 2);
    play(G3, 2);
    play(B3, 2);
    play(G3, 2);
	
    // measure 4
    play(D5, 2);
    play(G3, 2);
    play(B3, 2);
    play(G4, 1);
    play(B4, 1);
    play(D5, 2);
    play(G3, 2);
    play(E5, 2);
    play(G3, 2);
	
    // measure 5
    play(D5, 2);
    play(Fs3, 2);
    play(A3, 2);
    play(A4, 2);
    play(Fs5, 2);
    play(Fs3, 2);
    play(A5, 2);
    play(Fs3, 2);
	
    // measure 6
    play(Gs5, 2);
    play(Fs3, 2);
    play(A5, 2);
    play(Fs3, 2);
    play(Gs5, 1);
    play(A5, 1);
    play(Gs5, 1);
    play(Fs5, 1);
    play(D5, 2);
    play(A4, 2);
	
    // measure 7
    play(B4, 2);
    play(G3, 1);
    play(Cs5, 1);
    play(D5, 2);
    play(G3, 1);
    play(E5, 1);
    play(Fs5, 1);
    play(F5, 1);
    play(Fs5, 1);
    play(G5, 1);
    play(A5, 1);
    play(G5, 1);
    play(Fs5, 1);
    play(E5, 1);
	
    // measure 8
    play(D5, 1);
    play(Cs5, 1);
    play(D5, 1);
    play(A5, 1);
    play(Cs5, 1);
    play(C5, 1);
    play(Cs5, 1);
    play(A5, 1);
    play(Cs5, 1);
    play(C5, 1);
    play(B4, 1);
    play(Bb4, 1);
    play(A4, 1);
    play(Gs4, 1);
    play(G4, 1);
    play(E4, 1);
	
    // measure 9
    play(A4, 2);
    play(A3, 2);
    play(D4, 2);
    play(A3, 2);
    play(B4, 2);
    play(A3, 2);
    play(A4, 2);
    play(A3, 2);
	
    // measure 10
    play(D4, 2);
    play(D5, 2);
    play(Cs5, 2);
    play(D5, 2);
    play(Fs5, 2);
    play(A3, 2);
    play(E5, 2);
    play(D5, 2);
	
    // measure 11
    play(B4, 2);
    play(G3, 2); 
    play(B4, 2);
    play(G3, 2);
    play(E5, 2);
    play(G3, 2);
    play(D5, 2);
    play(G3, 2);
	
    // measure 12
    play(B4, 2);
    play(B4, 2);
    play(Bb4, 2);
    play(B4, 2);
    play(D5, 2);
    play(G3, 2);
    play(Cs5, 2);
    play(B4, 2);
	
	
    // measure 13
    play(A4, 2);
    play(Fs3, 2);
    play(Fs3, 2);
    play(A4, 2);
    play(Fs3, 2);
    play(Fs3, 2);
    play(A5, 2);
    play(Fs3, 2);
}
