PROPGCC = /opt/parallax
CC = $(PROPGCC)/bin/propeller-elf-gcc
LOAD = $(PROPGCC)/bin/propeller-load

MMODEL = cmm

TARGET = example2-3

PORT = /dev/cu.usbserial-*
OBJDIR = ../../build/$(TARGET)

LOAD_MODE = load

SIMPLELIB = "$(PROPGCC)/Workspace/Learn/Simple\ Libraries"

CFLAGS = -Os -n -m32bit-doubles -mfcache -fno-exceptions -std=c99 -Dprintf=__simple_printf

LOADFLAGS = -Dreset=dtr -S50 -t

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
		$(LOAD) $(LOADFLAGS) -p $(PORT) -I $(PROPGCC)/propeller-load -r -v $<

load_eeprom: $(OBJDIR)/$(TARGET).elf
		$(LOAD) $(LOADFLAGS) -p $(PORT) -I $(PROPGCC)/propeller-load -e -r -v $<

clean:
	rm -rf $(OBJDIR)/*
