#!/bin/bash
FILE="./build/apps/adventure_tests"
if [ -f $FILE ]; then
   ./build/apps/adventure_tests
else
   echo "File $FILE does not exist; building..."
   make clean
   make all
   ./build/apps/adventure_tests
fi