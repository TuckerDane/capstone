#!/bin/bash

FILE="./build/apps/adventure"
if [ -f $FILE ]; then
   ./build/apps/adventure
else
   echo "File $FILE does not exist; building..."
   make clean
   make all
   ./build/apps/adventure
fi