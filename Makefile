CC = msp430-gcc
CFLAGS = -Os -Wall -g -mmcu=msp430x2012

BIN = launchpad-music.elf
OBJS = launchpad-music.o

all: launchpad-music 

launchpad-music: $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(BIN) $(OBJS)
