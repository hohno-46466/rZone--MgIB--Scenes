
# Makefile

# Prev update: Mon Dec  9 09:15:28 JST 2024
# Last update: Sun Dec 15 05:51:30 JST 2024

# Examples:
# $ make --debug 00v
# $ make --debug 00u ARDPORT=/dev/cu.usbmodem1101
# $ export ARDPORT=/dev/cu.usbmodem2101
# $ make 00show
# $ make 00verify
# $ make 00upload
# $ make 00run

ARDPORT ?= /dev/cu.usbmodem2101

FQBN = arduino:avr:uno

TARGET = sketch_xx_20241208a_dummy

# ----------------------------------------------------------

targets:
	awk -F':' '/^[a-zA-Z0-9_.-]+:/ { print $1 }' Makefile | sed -e 's/:.*$$//' | egrep -v '^[0-9]' | cat -n
	awk -F':' '/^[a-zA-Z0-9_.-]+:/ { print $1 }' Makefile | sed -e 's/:.*$$//' | egrep '^[0-9]' | egrep -v '^[0-9][0-9]$$|^[0-9][0-9][a-z]$$'| cat -n

all:	show

# ----------------------------------------------------------

TARGET_00 = sketch_00_20241206a_Blink

00build:	00b

00upload:	00u

00verity:	00v

00show:		00s

00run:		00r

00:	00u

00b:	00v

00u:
	$(MAKE) build TARGET=$(TARGET_00)

00v:
	$(MAKE) verify TARGET=$(TARGET_00)

00s:
	$(MAKE) show TARGET=$(TARGET_00)

00r:
	(cat -u | su cu -s 57600 -l $(TARGET_00)) | sed -u -e 's/\\r//g'

# ----------------------------------------------------------

TARGET_01 = sketch_01_20241101a_BlinkOverI2C

01build:	01b

01upload:	01u

01verity:	01v

01show:		01s

01run:		01r

01:	01u

01b:	01v

01u:
	$(MAKE) upload TARGET=$(TARGET_01)

01v:
	$(MAKE) verify TARGET=$(TARGET_01)

01s:
	$(MAKE) show TARGET=$(TARGET_01)

01r:
	(cat -u | su cu -s 57600 -l $(TARGET_01)) | sed -u -e 's/\\r//g'

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

