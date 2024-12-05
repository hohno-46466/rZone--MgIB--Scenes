
# Makefile

# try like:
# $ make --debug 00
# $ make --debug 00 PORT=/dev/cu.usbmodem1101
# $ export PORT=/dev/cu.usbmodem2101
# $ make --debug 00

PORT ?= /dev/cu.usbmodem2101

FQBN = arduino:avr:uno
# TARGET = sketch_00_20241206a_Blink

00:
	$(MAKE) build TARGET=sketch_00_20241206a_Blink

00v:
	$(MAKE) verify TARGET=sketch_00_20241206a_Blink

01:
	$(MAKE) build TARGET=sketch_01_20241101a_BlinkOverI2C

01v:
	$(MAKE) verify TARGET=sketch_01_20241101a_BlinkOverI2C

verify:
	( cd $(TARGET) \
	&& arduino-cli compile --fqbn $(FQBN) $(TARGET).ino )

build: upload

upload:
	( cd $(TARGET) \
	&& arduino-cli compile --fqbn $(FQBN) $(TARGET).ino \
	&& arduino-cli upload --fqbn $(FQBN) -p $(PORT) )

