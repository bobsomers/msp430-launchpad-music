CC = msp430-gcc
CFLAGS = -Os -Wall -g -mmcu=msp430x2012

BLINK_BIN = blink.elf
BLINK_OBJS = blink.o

TEMP_BIN = temp.elf
TEMP_OBJS = temp.o

SOUND_BIN = sound.elf
SOUND_OBJS = sound.o

all: blink temp sound

blink: $(BLINK_OBJS)
	$(CC) $(CFLAGS) -o $(BLINK_BIN) $(BLINK_OBJS)

temp: $(TEMP_OBJS)
	$(CC) $(CFLAGS) -o $(TEMP_BIN) $(TEMP_OBJS)

sound: $(SOUND_OBJS)
	$(CC) $(CFLAGS) -o $(SOUND_BIN) $(SOUND_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(BLINK_BIN) $(TEMP_BIN) $(SOUND_BIN) $(BLINK_OBJS) $(TEMP_OBJS) $(SOUND_OBJS)
