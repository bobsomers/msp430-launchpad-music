# MSP430 LaunchPad Music

A simple example of how you can generate music with the [super-cheap LaunchPad development
board](http://ti.com/launchpadwiki) from TI.

It uses two compare registers in the timers to keep track of both the frequency of the output square
wave (for the sound signal) as well as the number of milliseconds that have elapsed for each note to
time its duration. Since notes are defined in "ticks" (the finest rhythmic resolution set in the
define), you can speed up or slow down everything by just setting a new tempo with `set_bpm()`. You
could even simulate an accelerando or ritardano if you're clever.

Just plug in a cheap speaker across ground and P1.7 and you're good to go! Press the button to start
playing the music.

The code has both the Bob-omb Battlefield Theme or the Princess Slide Theme from Super Mario 64. You
can't have both uncommented at the same time because there's not enough space on the chips that come
with the LaunchPad (unless you bought some other MSP430s with more than 2k of code space).

I'm pretty sure I used some MSPGCC-only defines in this code, so free internet cookies to the first
person who submits a patch that makes this work in TI's Windows software, too.

Released under the [Beerware License](http://en.wikipedia.org/wiki/Beerware). That means you can
do whatever the heck you want with it. If you find it useful and you run into me someday, you're
welcome to buy me a beer if you'd like.
