#!/bin/bash
export TERM=rxvt-unicode
export NCURSES_NO_UTF8_ACS=1 
FILE="./build/apps/adventure"
if [ -f $FILE ]; then
   ./build/apps/adventure
else
   echo "File $FILE does not exist; building..."
   make clean
   make all
   ./build/apps/adventure
fi