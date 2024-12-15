#!/bin/sh
x=$1

echo 

dir=`case "$x" in 0[0-9]) echo "scene-00s" ;; 1[0-9]) echo "scene-10s" ;; 2[0-9]) echo "scene-20s" ;; esac`

echo "Changing directory to $dir"

