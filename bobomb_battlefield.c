// Bob Somers 2011
//     http://bobsomers.com
//
// Made for the TI MSP430 LaunchPad
//     http://ti.com/launchpadwiki
//
// Released under the Beerware License
//     http://en.wikipedia.org/wiki/Beerware
//

// bob-omb battlefield theme from super mario 64

void song_setup()
{
	set_bpm(110);
}

void song_play() {
	// measure 1
	play(C5, 2);
	play(A4, 2);
	play(C5, 2);
	play(D5, 1);
	play(C5, 1);
	rest(1);
	play(E4, 3);
	play(F4, 2);
	play(Fs4, 2);
	
	// measure 2
	play(G4, 3);
	rest(1);
	play(G4, 1);
	play(G3, 2);
	play(G4, 2);
	rest(5);
	play(D5, 1);
	play(Eb5, 1);
	
	// measure 3
	play(E5, 1);
	play(Eb5, 1);
	play(E5, 1);
	play(G5, 2);
	play(A5, 1);
	play(G5, 2);
	play(C5, 4);
	rest(2);
	play(G4, 1);
	play(Ab4, 1);
	
	// measure 4
	play(A4, 1);
	play(Ab4, 1);
	play(A4, 1);
	play(C5, 2);
	play(D5, 1);
	play(C5, 2);
	play(A4, 4);
	rest(2);
	play(A4, 2);
	
	// measure 5
	play(G4, 1);
	play(E4, 1);
	play(G4, 1);
	play(G5, 1);
	rest(2);
	play(G4, 1);
	play(E4, 1);
	play(G4, 1);
	play(G5, 1);
	rest(2);
	play(G4, 1);
	play(E4, 1);
	play(G4, 1);
	play(G5, 1);
	
	// measure 6
	rest(2);
	play(G5, 2);
	play(A5, 1);
	play(G5, 2);
	play(D5, 5);
	rest(2);
	play(D4, 1);
	play(Eb4, 1);
	
	// measure 7
	play(E4, 1);
	play(Eb4, 1);
	play(E4, 1);
	play(G4, 2);
	play(A4, 1);
	play(G4, 2);
	play(Bb4, 4);
	rest(2);
	play(Ab4, 2);
	
	// measure 8
	play(A4, 1);
	play(Ab4, 1);
	play(A4, 1);
	play(C5, 2);
	play(D5, 1);
	play(C5, 2);
	play(A4, 4);
	rest(2);
	play(A4, 2);
	
	// measure 9
	play(G4, 1);
	play(Fs4, 1);
	play(G4, 1);
	play(G3, 1);
	rest(2);
	play(G4, 1);
	play(Fs4, 1);
	play(G4, 1);
	play(G3, 1);
	rest(1);
	play(Eb4, 1);
	play(E4, 2);
	play(E4, 2);
	
	// measure 10
	play(C4, 12);
	rest(4);
}
