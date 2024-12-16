
# Makefile

# Prev update: Mon Dec  9 09:15:28 JST 2024
# Last update: Sun Dec 15 05:51:30 JST 2024

# Examples:
# $ make --debug 00v
# $ make --debug 00u ARDPORT=/dev/cu.usbmodem1100
# $ export ARDPORT=/dev/cu.usbmodem2101
# $ make 00show
# $ make 00verify
# $ make 00upload
# $ make 00run

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

S00build:	S00b

S00verity:	S00v

S00upload:	S00u

S00run:		S00r

S00:	S00s 00v 00u 00r

S00t:
	@/bin/echo -n "$$ "
	make targets | grep '^S00' | cat -n

S00s:
	$(MAKE) show TARGET=$(TARGET_00)

S00e:
	$(MAKE) edit TARGET=$(TARGET_00)

S00b:	S00v

S00v:
	$(MAKE) verify TARGET=$(TARGET_00)

S00u:
	$(MAKE) upload TARGET=$(TARGET_00)

S00r:
	$(MAKE) run TARGET=$(TARGET_00)

# ----------------------------------------------------------

TARGET_01 = sketch_01_20241101a_BlinkOverI2C

S01targets:	S01t

S01show:	S01s

S01edit:	S01e

S01build:	S01b

S01verity:	S01v

S01upload:	S01u

S01run:		S01r

S01:	S01s 01v 01u 01r

S01t:
	@/bin/echo -n "$$ "
	$(MAKE) targets | grep '^S01' | cat -n

S01s:
	$(MAKE) show TARGET=$(TARGET_01)

S01e:
	$(MAKE) edit TARGET=$(TARGET_01)

S01b:	S01v

S01v:
	$(MAKE) verify TARGET=$(TARGET_01)

S01u:
	$(MAKE) upload TARGET=$(TARGET_01)

S01r:
	$(MAKE) run TARGET=$(TARGET_01)

# ----------------------------------------------------------


build:	verify

show:
	(cd $(TARGET) \
	&& cat -n $(TARGET).ino)
	@echo "Note: To extract the sketch from this result, execute the following command:"
	@echo "      $$ make ... | sed -n 's/^[[:space:]]*[0-9][0-9]*[[:space:]]//p'"

edit:
	(cd $(TARGET) \
	&& code $(TARGET).ino)

verify:
	( cd $(TARGET) \
	&& arduino-cli compile --fqbn $(FQBN) $(TARGET).ino )

upload:
	( cd $(TARGET) \
	&& arduino-cli upload --fqbn $(FQBN) -p $(ARDPORT) )

run:
	sudo date
	(cat -u | sudo cu -s 57600 -l $(ARDPORT)) | sed -u -e 's/\\r//g'

# ----------------------------------------------------------

