#!/bin/bash

chmod 777 $1
stty 115200 -F $1 raw -echo
./run $1 $2 $3

echo " "
echo "You can power off the Arduino card and change your cartridge before doing a new try"
echo " "
