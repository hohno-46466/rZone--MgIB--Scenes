
# Makefile

# try like:
# $ make --debug 00
# $ make --debug 00 ARDPORT=/dev/cu.usbmodem1101
# $ export ARDPORT=/dev/cu.usbmodem2101
# $ make --debug 00

ARDPORT ?= /dev/cu.usbmodem2101

FQBN = arduino:avr:uno

TARGET = sketch_xx_20241208a_dummy

# ----------------------------------------------------------

all:	show

# ----------------------------------------------------------

TARGET_00 = sketch_00_20241206a_Blink

00build:	00b

00upload:	00u

00verity	00v

00show:		00s

00:	00u

00b:	00u

00u:
	$(MAKE) build TARGET=$(TARGET_00)

00v:
	$(MAKE) verify TARGET=$(TARGET_00)

00s:
	$(MAKE) show TARGET=$(TARGET_00)

# ----------------------------------------------------------

TARGET_01 = sketch_01_20241101a_BlinkOverI2C

01build:	01b

01upload:	01u

01verity	01v

01show:		01s

01:	01u

01b:	01u

01u:
	$(MAKE) upload TARGET=$(TARGET_01)

01v:
	$(MAKE) verify TARGET=$(TARGET_01)

01s:
	$(MAKE) show TARGET=$(TARGET_01)

# ----------------------------------------------------------

build: upload

upload:
	( cd $(TARGET) \
	&& arduino-cli compile --fqbn $(FQBN) $(TARGET).ino \
	&& arduino-cli upload --fqbn $(FQBN) -p $(ARDPORT) )

verify:
	( cd $(TARGET) \
	&& arduino-cli compile --fqbn $(FQBN) $(TARGET).ino )

show:
	(cd $(TARGET) && cat -n $(TARGET).ino)
	@echo "Note: use sed -n 's/^[[:space:]]*[0-9][0-9]*[[:space:]]//p' to pick up sketch from the result above."

# ----------------------------------------------------------

