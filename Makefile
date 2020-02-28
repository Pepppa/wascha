
#Контроллер, установленный на плате. Может быть другим, например atmega328 
DEVICE     = atmega2560

#Тактовая частота 16 МГц 
CLOCK      = 16000000

#Команда запуска avrdude. Ее нужно скопировать из Arduino IDE.
AVRDUDE = /usr/share/arduino/hardware/tools/avrdude -C/usr/share/arduino/hardware/tools/avrdude.conf -v -v -v -v -p$(DEVICE) -cwiring -P/dev/ttyACM0 -b115200 -D -Uflash:w:wascha.hex:i

OBJECTS    = wascha_mega/wascha_mega.o

COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)

all:	wascha.hex

%.o: %.ino
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@

.c.s:
	$(COMPILE) -S $< -o $@

flash:	all
	$(AVRDUDE) -U flash:w:wascha.hex:i

clean:
	rm -f wascha.hex wascha.elf $(OBJECTS)

wascha.elf: $(OBJECTS)
	$(COMPILE) -o wascha.elf $(OBJECTS)

wascha.hex: wascha.elf
	rm -f wascha.hex
	avr-objcopy -j .text -j .data -O ihex wascha.elf wascha.hex
	avr-size --format=avr --mcu=$(DEVICE) wascha.elf
