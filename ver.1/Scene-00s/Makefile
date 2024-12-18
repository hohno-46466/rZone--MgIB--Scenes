
# Makefile

# Prev update: Mon Dec  9 09:15:28 JST 2024
# Last update: Sun Dec 15 05:51:30 JST 2024
# Last update: Mon Dec 16 18:25:25 JST 2024

# ----------------------------------------------------------

# Examples:
# $ make --debug S00v
# $ make --debug S00u ARDPORT=/dev/cu.usbmodem1100
# $ export ARDPORT=/dev/cu.usbmodem2101
# $ make S00show
# $ make S00verify
# $ make S00upload
# $ make S00run

# ----------------------------------------------------------

ARDPORT ?= /dev/cu.usbmodem2101

FQBN = arduino:avr:uno

TARGET = sketch_xx_20241208a_dummy

# ----------------------------------------------------------

default: targets

targets:
	@(awk -F':' '/^[a-zA-Z0-9_.-]+:/ { print $1 }' Makefile | sed -e 's/:.*$$//' | egrep -v '^S[0-9]'; awk -F':' '/^[a-zA-Z0-9_.-]+:/ { print $1 }' Makefile | sed -e 's/:.*$$//' | egrep '^S[0-9]' | egrep -v '^S[0-9][0-9]$$|^S[0-9][0-9][a-z]$$')

# ----------------------------------------------------------

TARGET_00 = sketch_00_20241206a_Blink

S00targets:	S00t

S00show:	S00s

S00edit:	S00e

S00info:	S00i

S00readme:	S00i

S00build:	S00v

S00verify:	S00v

S00upload:	S00u

S00run:		S00r

S00:	S00s S00v S00u S00r

S00t:
	@/bin/echo -n "$$ "
	make targets | grep '^S00' | cat -n

S00s:
	$(MAKE) _show TARGET=$(TARGET_00)

S00e:
	$(MAKE) _edit TARGET=$(TARGET_00)

S00i:
	$(MAKE) _readme TARGET=$(TARGET_00)

S00v:
	$(MAKE) _verify TARGET=$(TARGET_00)

S00u:
	$(MAKE) _upload TARGET=$(TARGET_00)

S00r:
	$(MAKE) _run TARGET=$(TARGET_00)

# ----------------------------------------------------------

TARGET_01 = sketch_01_20241101a_BlinkOverI2C

S01targets:	S01t

S01show:	S01s

S01edit:	S01e

S01info:	S01i

S01readme:	S01i

S01build:	S01v

S01verify:	S01v

S01upload:	S01u

S01run:		S01r

S01:	S01s S01v S01u S01r

S01t:
	@/bin/echo -n "$$ "
	$(MAKE) targets | grep '^S01' | cat -n

S01s:
	$(MAKE) _show TARGET=$(TARGET_01)

S01e:
	$(MAKE) _edit TARGET=$(TARGET_01)

S01i:
	$(MAKE) _readme TARGET=$(TARGET_01)

S01v:
	$(MAKE) _verify TARGET=$(TARGET_01)

S01u:
	$(MAKE) _upload TARGET=$(TARGET_01)

S01r:
	$(MAKE) _run TARGET=$(TARGET_01)

# ----------------------------------------------------------


_show:
	(cd $(TARGET) \
	&& cat -n $(TARGET).ino)
	@echo "Note: To extract the sketch from this result, execute the following command:"
	@echo "      $$ make ... | sed -n 's/^[[:space:]]*[0-9][0-9]*[[:space:]]//p'"

_edit:
	(cd $(TARGET) && code $(TARGET).ino)

_readme:
	(cd $(TARGET) && code README.md)

_verify:
	( cd $(TARGET) \
	&& arduino-cli compile --fqbn $(FQBN) $(TARGET).ino )

_upload:
	( cd $(TARGET) \
	&& arduino-cli upload --fqbn $(FQBN) -p $(ARDPORT) )

_run:
	sudo date
	(cat -u | sudo cu -s 57600 -l $(ARDPORT)) | sed -u -e 's/\\r//g'

# ----------------------------------------------------------

