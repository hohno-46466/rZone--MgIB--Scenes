#
# Makefile
#

default:
	@date

S%:
	@(dir=`case $* in \
	0[0-9]*) echo "Scene-00s" ;;\
	1[0-9]*) echo "Scene-10s" ;;\
	2[0-9]*) echo "Scene-20s" ;;\
	esac`;\
	echo "Changing directory to $$dir"; cd $$dir; make S$*)

