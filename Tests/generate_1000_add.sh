#!/bin/bash

i2 = 0
str="add WIRE usb0"
for ((i=1; i<=700; i++)); do
    str+=", WIRE usb$i"
    i2+=1
done
str+="\ndisp"

echo "$str"