# GB(C) Dumper

Fork of the project "arduinogbdump" ( Author : Andrew Clark (FL4SHK) - https://github.com/fl4shk/arduinogbdump ), GB(C) Dumper will allow you to dump your GB/GBC real cartridges to obtain their ROM.

The **required** hardwares are : a **supported** Arduino, a N64 controller, a N64 Transfer Pak and a pull-up resistor.

## Modifications applied
- Software : Cleaning code & Bug fix on detection + reading
- Firmware : Updated project structure & optimisation 

## Features/Compatibility

There is currently support for dumping ROMs from cartridges of the following types:
  1.  ROM Only (32 kiB)
  2.  MBC1
  3.  MBC2
  4.  MBC3
  5.  MBC5 (*mostly* complete support, but only works for ROMs up to 4 MiB.)

There is currently support for dumping RAM from cartridges of the following
types:
  1.  MBC1
  2.  MBC2
  3.  MBC3 (No RTC support yet)
  4.  MBC5

There is currently support for restoring RAM to cartridges of the following
types:
  1.  MBC1
  2.  MBC3 (No RTC support yet)
  3.  MBC5

The software will be tested on Linux ( [Fenikkusu](https://jackobo.info/?datas=fenikkusu) / Debian ). It is not known whether it would even compile on other systems, but there's a good chance of it working on other Unices (such as FreeBSD).

## How to Connect the Arduino Board to the N64 Controller

![alt text](https://github.com/JackoboLeChocobo/GB_GBC_Dumper/blob/main/schematics/arduino_mega_2560.png?raw=true)

## Arduino Board Compatibility

12th Sept 2024 : Tested successfully on Arduino Mega 2560 R3 

## Credits/Thanks

- [Andrew Clark (FL4SHK)](https://github.com/fl4shk/arduinogbdump) 
- [brownan](https://github.com/brownan/Gamecube-N64-Controller)
