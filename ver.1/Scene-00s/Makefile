
# Makefile

# Prev update: Mon Dec  9 09:15:28 JST 2024
# Prev update: Sun Dec 15 05:51:30 JST 2024
# Prev update: Mon Dec 16 18:25:25 JST 2024
# Prev update: Tue Dec 17 09:02:38 JST 2024
# Last update: Mon Dec 23 11:36:52 JST 2024

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

# ----------------------------------------------------------

TARGET_XX = sketch_xx_20241208a_dummy
TARGET_00 = sketch_00_20241221a_Blank
TARGET_01 = sketch_01_20241206a_Blink
TARGET_02 = sketch_02_20241101a_BlinkOverI2C
TARGET_03 = sketch_03_20241219a_I2Cscanner

TARGET = $(TARGET_XX)

# ----------------------------------------------------------

default: help

help:
	@(awk -F':' '/^[a-zA-Z0-9_.-]+:/ { print $1 }' Makefile | sed -e 's/:.*$$//' | egrep -v '^S[0-9]'; awk -F':' '/^[a-zA-Z0-9_.-]+:/ { print $1 }' Makefile | sed -e 's/:.*$$//' | egrep '^S[0-9]' | egrep -v '^S[0-9][0-9]$$|^S[0-9][0-9][a-z]$$')

new:
	@echo ""
	@echo "TARGET_XX = sketch_XX_2024MMDDa"
	@echo ""
	@awk ' /^S00:/ {x1=1} /^# --------/ && x1 && x2 {print; x1=0; next} /pat2/ {x2=1} x1' Makefile | sed 's/00/XX/g'

# ----------------------------------------------------------

_info:
	(cd $(TARGET) && code README.md)

_show:
	(cd $(TARGET) && cat -n $(TARGET).ino)
	@echo "Note: To extract the sketch from this result, execute the following command:"
	@echo "      $$ make ... | sed -n 's/^[[:space:]]*[0-9][0-9]*[[:space:]]//p'"

_edit:
	(cd $(TARGET) && code $(TARGET).ino)

_verify:
	( cd $(TARGET) && arduino-cli compile --fqbn $(FQBN) $(TARGET).ino )

_upload:
	( cd $(TARGET) && arduino-cli upload --fqbn $(FQBN) -p $(ARDPORT) )

_run:
	sudo date
	(cat -u | sudo cu -s 57600 -l $(ARDPORT)) | sed -u -e 's/\\r//g'

# ----------------------------------------------------------
# ----------------------------------------------------------

S00:	S00s 00v 00u 00r

S00h:	S00help
S00i:	S00info
S00s:	S00show
S00e:	S00edit
S00b:	S00build
S00v:	S00verify
S00u:	S00upload
S00r:	S00run

S00help:
	@/bin/echo -n "$$ "
	$(MAKE) help | grep '^S00' | cat -n
S00info:
	$(MAKE) TARGET=$(TARGET_00) _info
S00show:
	$(MAKE) TARGET=$(TARGET_00) _show
S00edit:	
	$(MAKE) TARGET=$(TARGET_00) _edit
S00build:	S00verify
S00verify:	
	$(MAKE) TARGET=$(TARGET_00) _verify
S00upload:
	$(MAKE) TARGET=$(TARGET_00) _upload
S00run:	
	$(MAKE)	TARGET=$(TARGET_00) _run

# ----------------------------------------------------------

S01:	S01s 01v 01u 01r

S01h:	S01help
S01i:	S01info
S01s:	S01show
S01e:	S01edit
S01b:	S01build
S01v:	S01verify
S01u:	S01upload
S01r:	S01run

S01help:
	@/bin/echo -n "$$ "
	$(MAKE) help | grep '^S01' | cat -n
S01info:
	$(MAKE) TARGET=$(TARGET_01) _info
S01show:
	$(MAKE) TARGET=$(TARGET_01) _show
S01edit:	
	$(MAKE) TARGET=$(TARGET_01) _edit
S01build:	S01verify
S01verify:	
	$(MAKE) TARGET=$(TARGET_01) _verify
S01upload:
	$(MAKE) TARGET=$(TARGET_01) _upload
S01run:	
	$(MAKE)	TARGET=$(TARGET_01) _run

# ----------------------------------------------------------

S02:	S02s 02v 02u 02r

S02h:	S02help
S02i:	S02info
S02s:	S02show
S02e:	S02edit
S02b:	S02build
S02v:	S02verify
S02u:	S02upload
S02r:	S02run

S02help:
	@/bin/echo -n "$$ "
	$(MAKE) help | grep '^S02' | cat -n
S02info:
	$(MAKE) TARGET=$(TARGET_02) _info
S02show:
	$(MAKE) TARGET=$(TARGET_02) _show
S02edit:	
	$(MAKE) TARGET=$(TARGET_02) _edit
S02build:	S02verify
S02verify:	
	$(MAKE) TARGET=$(TARGET_02) _verify
S02upload:
	$(MAKE) TARGET=$(TARGET_02) _upload
S02run:	
	$(MAKE)	TARGET=$(TARGET_02) _run

# ----------------------------------------------------------

S03:	S03s 03v 03u 03r

S03h:	S03help
S03i:	S03info
S03s:	S03show
S03e:	S03edit
S03b:	S03build
S03v:	S03verify
S03u:	S03upload
S03r:	S03run

S03help:
	@/bin/echo -n "$$ "
	$(MAKE) help | grep '^S03' | cat -n
S03info:
	$(MAKE) TARGET=$(TARGET_03) _info
S03show:
	$(MAKE) TARGET=$(TARGET_03) _show
S03edit:	
	$(MAKE) TARGET=$(TARGET_03) _edit
S03build:	S03verify
S03verify:	
	$(MAKE) TARGET=$(TARGET_03) _verify
S03upload:
	$(MAKE) TARGET=$(TARGET_03) _upload
S03run:	
	$(MAKE)	TARGET=$(TARGET_03) _run

# ----------------------------------------------------------
