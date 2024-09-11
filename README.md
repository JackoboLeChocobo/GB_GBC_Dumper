# GB(C) Dumper

Fork of the project "arduinogbdump" ( Author : Andrew Clark (FL4SHK) )
Github : https://github.com/fl4shk/arduinogbdump

## Modifications applied
- Software : Cleaning code
- Firmware : Updated project structure & optimisation 

## Presentation

GB(C) Dumper will allow you to dump GB/GBC real cartridges to obtain their ROM.
The required hardwares are :
- a **supported** Arduino
- a N64 controller
- a N64 Transfer Pak
- a pull-up resistor.

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

All testing of the communicator program has been done on Linux. It is not known whether it would even compile on other systems, but there's a good chance of it working on other Unices (such as FreeBSD).

## How to Connect the Arduino Board to the N64 Controller

TODO

## Arduino Board Compatibility

TODO

## Credits/Thanks

- [Andrew Clark (FL4SHK)](https://github.com/fl4shk/arduinogbdump) 
- [brownan](https://github.com/brownan/Gamecube-N64-Controller)