PROPGCC = ../../propgcc/Linux

CC = $(PROPGCC)/bin/propeller-elf-gcc
LOAD = $(PROPGCC)/bin/propeller-load

MMODEL = cmm
BOARD = QUICKSTART

TARGET = example1-1

PORT = /dev/ttyUSB0 
OBJDIR = ../../build/$(TARGET)

LOAD_MODE = load

CFLAGS = -Os -n -m32bit-doubles -mfcache -fno-exceptions -std=c99

LOADFLAGS = -Dreset=dtr -S50

.PHONY: all setup load load_eeprom clean

all: setup $(OBJDIR)/$(TARGET).elf $(LOAD_MODE)

setup: 
	mkdir -p $(OBJDIR)

$(OBJDIR)/$(TARGET).elf: $(OBJDIR)/$(TARGET).o
		$(CC) $(INCLUDES) $(LFLAGS) -o $@ -m$(MMODEL) $(CFLAGS) $^ $(LIBS)
		$(PROPGCC)/bin/propeller-elf-size $(OBJDIR)/$(TARGET).elf

$(OBJDIR)/$(TARGET).o: main.c
		$(CC) -c $(INCLUDES) -o $@ -m$(MMODEL) $(CFLAGS) $(DEADCODESTRIP) $< 	

load: $(OBJDIR)/$(TARGET).elf
		$(LOAD) $(LOADFLAGS) -b $(BOARD) -p $(PORT) -I $(PROPGCC)/propeller-load -r -v $<

load_eeprom: $(OBJDIR)/$(TARGET).elf
		$(LOAD) $(LOADFLAGS) -b $(BOARD) -p $(PORT) -I $(PROPGCC)/propeller-load -e -r -v $<

clean:
	rm -rf $(OBJDIR)/*
