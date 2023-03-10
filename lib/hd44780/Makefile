PROPGCC = /opt/parallax
CC = $(PROPGCC)/bin/propeller-elf-gcc
LOAD = $(PROPGCC)/bin/propeller-load
AR = $(PROPGCC)/bin/propeller-elf-ar

MMODEL = cmm
BOARD = QUICKSTART

TARGET = hd44780-example
LIBDIR = $(MMODEL)
LIBTARGET = libhd44780

OBJDIR = build

CFLAGS = -Os -n -m32bit-doubles -mfcache -fno-exceptions

LIBS = -lhd44780
LFLAGS = -L./$(MMODEL)/

PORT = /dev/cu.usbserial-*
LOAD_MODE = load_eeprom
LOADFLAGS = -Dreset=dtr -S5

.PHONY: all setup load load_eeprom clean

all: setup $(LIBDIR)/$(LIBTARGET).a $(OBJDIR)/$(TARGET).elf $(LOAD_MODE)

setup: 
	mkdir -p $(OBJDIR)
	mkdir -p $(LIBDIR)

$(LIBDIR)/$(LIBTARGET).a: $(OBJDIR)/hd44780.o
		$(AR) rcs $@ $<

$(OBJDIR)/$(TARGET).elf: $(OBJDIR)/$(TARGET).o
		$(CC) $(INCLUDES) $(LFLAGS) -o $@ -m$(MMODEL) $(CFLAGS) $^ $(LIBS)
		$(PROPGCC)/bin/propeller-elf-size $(OBJDIR)/$(TARGET).elf

$(OBJDIR)/$(TARGET).o: demo.cpp global.h
		$(CC) -c $(INCLUDES) -o $@ -m$(MMODEL) $(CFLAGS) $(DEADCODESTRIP) $< 	

$(OBJDIR)/hd44780.o: hd44780.cpp hd44780.h
		$(CC) -c $(INCLUDES) -o $@ -m$(MMODEL) $(CFLAGS) $(DEADCODESTRIP) $< 

load: $(OBJDIR)/$(TARGET).elf
		$(LOAD) $(LOADFLAGS) -b $(BOARD) -p $(PORT) -I $(PROPGCC)/propeller-load -r -v $<

load_eeprom: $(OBJDIR)/$(TARGET).elf
		$(LOAD) $(LOADFLAGS) -b $(BOARD) -p $(PORT) -I $(PROPGCC)/propeller-load -e -r -v $<

clean:
	rm -rf $(OBJDIR)/
	rm -rf $(LIBDIR)/