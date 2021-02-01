# Arduino makefile
# original Makefile has been got from https://playground.arduino.cc/uploads/Learning/Makefile
#
#
# "make build"to compile/verify your program.
#
# "make upload" to upload your program to the Arduino board.

SKETCH_DIR = src
SKETCH_CXXSRC = $(wildcard $(SKETCH_DIR)/*.cpp)

# name of main Arduino sketch file
TARGET = src/blink

# git clone git@github.com:arduino/ArduinoCore-avr.git
ARDUINO = dep/ArduinoCore-avr/cores/arduino
ARDUINO_MEGA = dep/ArduinoCore-avr/variants/mega
#STL = dep/ArduinoSTL/src
SRC = $(wildcard $(ARDUINO)/*.c)
ASRC = $(wildcard $(ARDUINO)/*.S)
CXXSRC = $(wildcard $(ARDUINO)/*.cpp) #$(wildcard $(STL)/*.cpp)

PORT = /dev/ttyUSB0
MCU = atmega2560
F_CPU = 16000000L
FORMAT = ihex
UPLOAD_RATE = 115200

# Debugging format.
# Native formats for AVR-GCC's -g are stabs [default], or dwarf-2.
# AVR (extended) COFF requires stabs, plus an avr-objcopy run.
DEBUG = stabs

OPT = s

# Place -D or -U options here
CDEFS = -DF_CPU=$(F_CPU)
CXXDEFS = -DF_CPU=$(F_CPU)

# Place -I options here
CINCS = -I$(ARDUINO) -I$(ARDUINO_MEGA) -I$(STL)
CXXINCS = -I$(ARDUINO) -I$(ARDUINO_MEGA) -I$(STL)

# Compiler flag to set the C Standard level.
CSTANDARD = -std=gnu11
CPPSTANDARD = -std=gnu++11
CDEBUG = -g$(DEBUG)
CWARN = -Wall -Wstrict-prototypes
CTUNING = -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
#CEXTRA = -Wa,-adhlns=$(<:.c=.lst)

CXX_FROM_IDE = -g -Wall -fno-exceptions -ffunction-sections -fdata-sections -MMD -DUSB_VID=null -DUSB_PID=null -DARDUINO=105 -D__PROG_TYPES_COMPAT_

CFLAGS = $(CDEBUG) $(CDEFS) $(CINCS) -O$(OPT) $(CWARN) $(CSTANDARD) $(CEXTRA)
CXXFLAGS = $(CPPSTANDARD) $(CDEFS) $(CINCS) -O$(OPT) $(CXX_FROM_IDE)
#ASFLAGS = -Wa,-adhlns=$(<:.S=.lst),-gstabs
LDFLAGS = 


# Programming support using avrdude. Settings and variables.
AVRDUDE_PROGRAMMER = wiring
AVRDUDE_PORT = $(PORT)
AVRDUDE_WRITE_FLASH = -U flash:w:$(TARGET).hex
AVRDUDE_FLAGS = -F -p $(MCU) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER) \
  -b $(UPLOAD_RATE)
AVRDUDE_FROM_IDE = -C/usr/share/arduino/hardware/tools/avrdude.conf -v  -D

# Program settings
CC = /usr/share/arduino/hardware/tools/avr/bin/avr-gcc
CXX = /usr/share/arduino/hardware/tools/avr/bin/avr-g++
OBJCOPY = /usr/share/arduino/hardware/tools/avr/bin/avr-objcopy
OBJDUMP = /usr/share/arduino/hardware/tools/avr/bin/avr-objdump
SIZE = /usr/share/arduino/hardware/tools/avr/bin/avr-size
NM = /usr/share/arduino/hardware/tools/avr/bin/avr-nm
AVRDUDE = /usr/share/arduino/hardware/tools/avr/bin/avrdude
REMOVE = rm -f
MV = mv -f

# Define all object files.
OBJ = $(SRC:.c=.o) $(CXXSRC:.cpp=.o) $(ASRC:.S=.o) $(SKETCH_CXXSRC:.cpp=.o)

# Define all listing files.
LST = $(ASRC:.S=.lst) $(CXXSRC:.cpp=.lst) $(SRC:.c=.lst)

# Combine all necessary flags and optional flags.
# Add target processor to flags.
ALL_CFLAGS = -mmcu=$(MCU) -I. $(CFLAGS)
ALL_CXXFLAGS = -mmcu=$(MCU) -I. $(CXXFLAGS)
ALL_ASFLAGS = -mmcu=$(MCU) -I. -x assembler-with-cpp $(ASFLAGS)


# Default target.
all: build upload

build: elf hex eep

elf: $(TARGET).elf
hex: $(TARGET).hex
eep: $(TARGET).eep
lss: $(TARGET).lss 
sym: $(TARGET).sym

# Program the device.  
upload: $(TARGET).hex $(TARGET).eep
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_FROM_IDE) $(AVRDUDE_WRITE_FLASH)




# Convert ELF to COFF for use in debugging / simulating in AVR Studio or VMLAB.
COFFCONVERT=$(OBJCOPY) --debugging \
--change-section-address .data-0x800000 \
--change-section-address .bss-0x800000 \
--change-section-address .noinit-0x800000 \
--change-section-address .eeprom-0x810000 


coff: $(TARGET).elf
	$(COFFCONVERT) -O coff-avr $(TARGET).elf $(TARGET).cof


extcoff: $(TARGET).elf
	$(COFFCONVERT) -O coff-ext-avr $(TARGET).elf $(TARGET).cof


.SUFFIXES: .elf .hex .eep .lss .sym

.elf.hex:
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@

.elf.eep:
	-$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 -O $(FORMAT) $< $@

# Create extended listing file from ELF output file.
.elf.lss:
	$(OBJDUMP) -h -S $< > $@

# Create a symbol table from ELF output file.
.elf.sym:
	$(NM) -n $< > $@



# Link: create ELF output file from object files.
$(TARGET).elf: $(OBJ)
	$(CC) $(ALL_CFLAGS) $(OBJ) --output $@ $(LDFLAGS)


# Compile: create object files from C++ source files.
.cpp.o:
	$(CXX) -c $(ALL_CXXFLAGS) $< -o $@ 

# Compile: create object files from C source files.
.c.o:
	$(CC) -c $(ALL_CFLAGS) $< -o $@ 


# Compile: create assembler files from C source files.
.c.s:
	$(CC) -S $(ALL_CFLAGS) $< -o $@


# Assemble: create object files from assembler source files.
.S.o:
	$(CC) -c $(ALL_ASFLAGS) $< -o $@



# Target: clean project.
clean:
	$(REMOVE) $(TARGET).hex $(TARGET).eep $(TARGET).cof $(TARGET).elf \
	$(TARGET).map $(TARGET).sym $(TARGET).lss \
	$(OBJ) $(LST) $(SRC:.c=.s) $(SRC:.c=.d) $(CXXSRC:.cpp=.s) $(CXXSRC:.cpp=.d)

.PHONY:	all build elf hex eep lss sym program coff extcoff clean depend
