CC = msp430-gcc
CFLAGS = -Os -Wall -g -mmcu=msp430x2012

BIN = player.elf
OBJS = player.o

all: launchpad-player 

launchpad-player: $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(BIN) $(OBJS)
