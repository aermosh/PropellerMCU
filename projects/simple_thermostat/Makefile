PROPGCC = /opt/parallax
CC = $(PROPGCC)/bin/propeller-elf-gcc
LOAD = $(PROPGCC)/bin/propeller-load

MMODEL = cmm
CLKFREQ = 80000000
CLKMODE = xtal1+pll16x

TARGET = simple_thermostat

PORT = /dev/cu.usbserial-*
OBJDIR = ../build/$(TARGET)

LOAD_MODE = load_eeprom

INCLUDES = -I"/opt/PropellerLibraries/include"
LFLAGS = -L"/opt/PropellerLibraries/lib/$(MMODEL)"

CFLAGS = -Os -n -m32bit-doubles -mfcache -fno-exceptions -std=c99
#-Wl,-static -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,-s
LIBS = -lm -ldht11

LOADFLAGS = -Dreset=dtr -S50 -t -Dclkfreq=$(CLKFREQ) -Dclkmode=$(CLKMODE)

.PHONY: all setup load load_eeprom clean

all: setup $(OBJDIR)/$(TARGET).elf $(LOAD_MODE)

setup:
	$(shell pkill propeller-load)
	mkdir -p $(OBJDIR)

$(OBJDIR)/$(TARGET).elf: $(OBJDIR)/$(TARGET).o
		$(CC) $(INCLUDES) $(LFLAGS) -o $@ -m$(MMODEL) $(CFLAGS) $^ $(LIBS)
		$(PROPGCC)/bin/propeller-elf-size $(OBJDIR)/$(TARGET).elf

$(OBJDIR)/$(TARGET).o: main.cpp
		$(CC) -c $(INCLUDES) -o $@ -m$(MMODEL) $(CFLAGS) $(DEADCODESTRIP) $<

load: $(OBJDIR)/$(TARGET).elf
		$(LOAD) $(LOADFLAGS) -p $(PORT) -I $(PROPGCC)/propeller-load -r -v $<

load_eeprom: $(OBJDIR)/$(TARGET).elf
		$(LOAD) $(LOADFLAGS) -p $(PORT) -I $(PROPGCC)/propeller-load -e -r -v $<

clean:
	rm -rf $(OBJDIR)/*
