// Sergio Campama 2011
//     http://kaipi.me
//
// Made for the TI MSP430 LaunchPad
//     http://ti.com/launchpadwiki
//
// Released under the Beerware License
//     http://en.wikipedia.org/wiki/Beerware
//


void song_setup()
{
	set_bpm(150);
}

void mario_theme_measure_1()
{
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

void mario_theme_measure_2()
{
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

void mario_theme_measure_3()
{
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

void mario_theme_measure_4()
{
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

void mario_theme_measure_5()
{
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

void mario_theme_measure_6()
{
	rest(2);
	play(Eb4, 1);
	rest(2);
	play(D4, 1);
	rest(2);
	play(C4, 1);
	rest(7);
}

void mario_theme_measure_7()
{
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

void mario_theme_measure_8()
{
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

/*void mario_theme_measure_9()
{
	play(E4, 1);
	play(C4, 1);
	rest(1);
	play(G3, 1);
	rest(2);
	play(Gs3, 1);
	rest(1);
	play(A3, 1);
	play(F4, 1);
	rest(1);
	play(F4, 1);
	play(A3, 1);
	rest(3);
}

void mario_theme_measure_10()
{
	play(B3, 1);
	play(A4, 1);
	rest(1);
	play(A4, 1);
	play(A4, 1);
	play(G4, 1);
	rest(1);
	play(F4, 1);
	play(E4, 1);
	play(C4, 1);
	rest(1);
	play(A3, 1);
	play(G3, 1);
	rest(3);
}

void mario_theme_measure_11()
{
	play(B3, 1);
	play(F4, 1);
	rest(1);
	play(F4, 1);
	play(F4, 1);
	play(E4, 1);
	rest(1);
	play(D4, 1);
	play(C4, 1);
	rest(7);
	
}*/

void song_play()
{
	
	mario_theme_measure_1();
	mario_theme_measure_2();
	mario_theme_measure_3();
	mario_theme_measure_2();
	mario_theme_measure_3();
	mario_theme_measure_4();
	mario_theme_measure_5();
	mario_theme_measure_4();
	mario_theme_measure_6();
	mario_theme_measure_4();
	mario_theme_measure_5();
	mario_theme_measure_4();
	mario_theme_measure_6();
	mario_theme_measure_7();
	mario_theme_measure_8();
	mario_theme_measure_7();
	/*mario_theme_measure_1();
	mario_theme_measure_2();
	mario_theme_measure_3();
	mario_theme_measure_2();
	mario_theme_measure_3();*/
	/*mario_theme_measure_9();
	 mario_theme_measure_10();
	 mario_theme_measure_9();
	 mario_theme_measure_11();
	 mario_theme_measure_9();
	 mario_theme_measure_10();
	 mario_theme_measure_9();
	 mario_theme_measure_11();*/
	
}
