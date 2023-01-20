PROPGCC = /opt/parallax
CC = $(PROPGCC)/bin/propeller-elf-gcc
LOAD = $(PROPGCC)/bin/propeller-load
OBJCOPY = $(PROPGCC)/bin/propeller-elf-objcopy

MMODEL = cmm
BOARD = QUICKSTART

TARGET = example5-1

PORT = /dev/cu.usbserial-*
OBJDIR = ../../build/$(TARGET)

LOAD_MODE = load

INCLUDES = 
LFLAGS =

PROP_DEFINES = -DCLKFREQ=80000000
CFLAGS = -Os -n -m32bit-doubles -mfcache -std=c99 $(PROP_DEFINES)
LIBS =

LOADFLAGS = -Dreset=dtr -S50 -t

.PHONY: all setup load load_eeprom clean

all: setup $(OBJDIR)/$(TARGET).elf $(LOAD_MODE)

setup: 
	$(shell pkill propeller-load)
	mkdir -p $(OBJDIR)

$(OBJDIR)/$(TARGET).elf: $(OBJDIR)/pwm.cog $(OBJDIR)/$(TARGET).o
		$(CC) $(INCLUDES) $(LFLAGS) -o $@ -m$(MMODEL) $(CFLAGS) $^ $(LIBS)
		$(PROPGCC)/bin/propeller-elf-size $(OBJDIR)/$(TARGET).elf

$(OBJDIR)/$(TARGET).o: main.c
		$(CC) -c $(INCLUDES) -o $@ -m$(MMODEL) $(CFLAGS) $(DEADCODESTRIP) $<

$(OBJDIR)/pwm.cog: pwm.c pwm.h
		$(CC) -r $(INCLUDES) $(LFLAGS) $(CFLAGS) -mcog -o $@ $< 
		$(OBJCOPY) --localize-text --rename-section .text=pwm.cog $@

load: $(OBJDIR)/$(TARGET).elf
		$(LOAD) $(LOADFLAGS) -b $(BOARD) -p $(PORT) -I $(PROPGCC)/propeller-load -r -v $<

load_eeprom: $(OBJDIR)/$(TARGET).elf
		$(LOAD) $(LOADFLAGS) -b $(BOARD) -p $(PORT) -I $(PROPGCC)/propeller-load -e -r -v $<

clean:
	rm -rf $(OBJDIR)/*
