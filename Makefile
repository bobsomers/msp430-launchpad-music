CC = msp430-gcc
CFLAGS = -Os -Wall -g -mmcu=msp430x2012

BIN = msp430-music.elf
OBJS = music.o player.o

all: msp430-music 

msp430-music: $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(BIN) $(OBJS)
