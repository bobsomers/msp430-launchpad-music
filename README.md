# MSP430 LaunchPad Music

A simple example of how you can generate music with the
[super-cheap LaunchPad development board](http://ti.com/launchpadwiki) from TI.

It uses two compare registers in the timers to keep track of both the frequency
of the output square wave (for the sound signal) as well as the number of
milliseconds that have elapsed for each note to time its duration. Since notes
are defined in "ticks" (the finest rhythmic resolution set in the define), you
can speed up or slow down everything by just setting a new tempo with
`set_bpm()`. You could even simulate an accelerando or ritardano if you're
clever.

Just plug in a cheap speaker across ground and P1.7 and you're good to go!
Press the button to start playing the music.

The code has the Bob-omb Battlefield Theme (from Super Mario 64), the Princess
Slide Theme (also from Super Mario 64), and the Super Mario Theme (contributed
by Sergio Campama) available for your listening pleasure. Just uncomment the
desired `#include` in `player.c`.

You can have one song uncommented at a time because there's not enough code
space on the chips that come with the LaunchPad (unless you bought some other
MSP430s with more than 2k of instruction memory).

I'm pretty sure I used some MSPGCC-only defines in this code, so free internet
cookies to the first person who submits a patch that makes this work in TI's
Windows software, too.

***As of 2011-10-23, this has been updated for MSPGCC's new "Uniarch", and
has been tested with version 4.5.3. If you're using an older version, you may
need to replace `<msp430.h>` with `<io.h>` and `<signal.h>`. I'm really not
100% sure, because I don't have an older version around to test with. As above,
patches are appreciated and receive free internet cookies.***

Released under the [Beerware License](http://en.wikipedia.org/wiki/Beerware).
That means you can do whatever the heck you want with it. If you find it useful
and you run into me someday, you're welcome to buy me a beer if you'd like.
