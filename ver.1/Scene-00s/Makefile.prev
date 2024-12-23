
# Makefile

# Prev update: Mon Dec  9 09:15:28 JST 2024
# Prev update: Sun Dec 15 05:51:30 JST 2024
# Prev update: Mon Dec 16 18:25:25 JST 2024
# Last update: Tue Dec 17 09:02:38 JST 2024

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

S00:	S00s 00v 00u 00r

S00t:	S00targets
S00i:	S00info
S00s:	S00show
S00e:	S00edit
S00b:	S00build
S00v:	S00verify
S00u:	S00upload
S00r:	S00run

S00targets:
	@/bin/echo -n "$$ "
	make targets | grep '^S00' | cat -n
S00info:
	$(MAKE) _readme TARGET=$(TARGET_00)
S00show:
	$(MAKE) _show TARGET=$(TARGET_00)
S00edit:
	$(MAKE) _edit TARGET=$(TARGET_00)
S00build:	S00verify
S00verify:
	$(MAKE) _verify TARGET=$(TARGET_00)
S00upload:
	$(MAKE) _upload TARGET=$(TARGET_00)
S00run:
	$(MAKE) _run TARGET=$(TARGET_00)

# ----------------------------------------------------------

TARGET_01 = sketch_01_20241101a_BlinkOverI2C

S01:	S01s 01v 01u 01r

S01t:	S01targets
S01i:	S01info
S01s:	S01show
S01e:	S01edit
S01b:	S01build
S01v:	S01verify
S01u:	S01upload
S01r:	S01run

S01targets:
	@/bin/echo -n "$$ "
	make targets | grep '^S01' | cat -n
S01readme:	S01info
S01info:
	$(MAKE) _readme TARGET=$(TARGET_01)
S01show:
	$(MAKE) _show TARGET=$(TARGET_01)
S01edit:
	$(MAKE) _edit TARGET=$(TARGET_01)
S01build:	S01verify
S01verify:
	$(MAKE) _verify TARGET=$(TARGET_01)
S01upload:
	$(MAKE) _upload TARGET=$(TARGET_01)
S01run:
	$(MAKE) _run TARGET=$(TARGET_01)

# ----------------------------------------------------------

TARGET_02 = sketch_02_20241219a_I2Cscanner

S02:	S02s 02v 02u 02r

S02t:	S02targets
S02i:	S02info
S02s:	S02show
S02e:	S02edit
S02b:	S02build
S02v:	S02verify
S02u:	S02upload
S02r:	S02run

S02targets:
	@/bin/echo -n "$$ "
	make targets | grep '^S02' | cat -n
S02readme:	S02info
S02info:
	$(MAKE) _readme TARGET=$(TARGET_02)
S02show:
	$(MAKE) _show TARGET=$(TARGET_02)
S02edit:
	$(MAKE) _edit TARGET=$(TARGET_02)
S02build:	S02verify
S02verify:
	$(MAKE) _verify TARGET=$(TARGET_02)
S02upload:
	$(MAKE) _upload TARGET=$(TARGET_02)
S02run:
	$(MAKE) _run TARGET=$(TARGET_02)

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

