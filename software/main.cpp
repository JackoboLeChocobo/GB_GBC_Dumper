#include <stdint.h>

typedef uint8_t u8; typedef int8_t s8;
typedef uint16_t u16; typedef int16_t s16;
typedef uint32_t u32; typedef int32_t s32;
typedef uint64_t u64; typedef int64_t s64;
typedef unsigned int uint;

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;

#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "misc_types.hpp"
#include "stuffs.hpp"
#include "communicator_class.hpp"

int main( int argc, char** argv )
{
	cout << endl;
	cout << "  #####  ######    ##  #####  ##      ######                                     " << endl;
	cout << " #     # #     #  #   #     #   #     #     # #    # #    # #####  ###### #####  " << endl;
	cout << " #       #     # #    #          #    #     # #    # ##  ## #    # #      #    # " << endl;
	cout << " #  #### ######  #    #          #    #     # #    # # ## # #    # #####  #    # " << endl;
	cout << " #     # #     # #    #          #    #     # #    # #    # #####  #      #####  " << endl;
	cout << " #     # #     #  #   #     #   #     #     # #    # #    # #      #      #   #  " << endl;
	cout << "  #####  ######    ##  #####  ##      ######   ####  #    # #      ###### #    # " << endl;
	cout << endl;
		
	if ( argc < 4 )
	{
		cout << "Usage 1:  " << argv[0] << " {Arduino_Serial_Dev} dump_rom {your_name}.(gb|gbc)\n";
		cout << "Usage 2:  " << argv[0] << " {Arduino_Serial_Dev} dump_ram {your_name}.sav\n";
		cout << endl;
		return 0;
	}
	
	communicator the_communicator( argc, argv );
	
	if(strstr(argv[3], ".gb") || strstr(argv[3], ".gbc"))
		{
		std::ifstream infile(argv[3], std::ios_base::binary);
		const int length = 512;
		unsigned char bytes[length];

		if (infile.read(reinterpret_cast<char*>(bytes), length)) {
			std::ostringstream oss;
			cout << endl;
			cout << "Header results :" << endl;
			cout << endl;
			cout << "Game title (11 characters from the header) : ";
			for(size_t i = 308; i < 319; ++i) {
				cout << ( char ) static_cast<unsigned short>(bytes[i]) << "";
			}
			cout << endl;

			// Source : https://gbdev.gg8.se/wiki/articles/The_Cartridge_Header
			// 00h  ROM ONLY                 19h  MBC5
			// 01h  MBC1                     1Ah  MBC5+RAM
			// 02h  MBC1+RAM                 1Bh  MBC5+RAM+BATTERY
			// 03h  MBC1+RAM+BATTERY         1Ch  MBC5+RUMBLE
			// 05h  MBC2                     1Dh  MBC5+RUMBLE+RAM
			// 06h  MBC2+BATTERY             1Eh  MBC5+RUMBLE+RAM+BATTERY
			// 08h  ROM+RAM                  20h  MBC6
			// 09h  ROM+RAM+BATTERY          22h  MBC7+SENSOR+RUMBLE+RAM+BATTERY
			// 0Bh  MMM01
			// 0Ch  MMM01+RAM
			// 0Dh  MMM01+RAM+BATTERY
			// 0Fh  MBC3+TIMER+BATTERY
			// 10h  MBC3+TIMER+RAM+BATTERY   FCh  POCKET CAMERA
			// 11h  MBC3                     FDh  BANDAI TAMA5
			// 12h  MBC3+RAM                 FEh  HuC3
			// 13h  MBC3+RAM+BATTERY         FFh  HuC1+RAM+BATTERY
			cout << "Cartridge Type :                             ";
			switch (static_cast<unsigned short>(bytes[327]))
				{
				case 0:
					cout << "ROM only" << endl;
					break;
				case 1:
					cout << "MBC1" << endl;
					break;
				case 2:
					cout << "MBC1+RAM" << endl;
					break;
				case 3:
					cout << "MBC1+RAM+Battery" << endl;
					break;
				case 5:
					cout << "MBC2" << endl;
					break;
				case 6:
					cout << "MBC2+Battery" << endl;
					break;
				case 8:
					cout << "ROM+RAM" << endl;
					break;
				case 9:
					cout << "ROM+RAM+Battery" << endl;
					break;
				case 15:
					cout << "MBC3+Timer+Battery" << endl;
					break;
				case 16:
					cout << "MBC3+Timer+RAM+Battery" << endl;
					break;
				case 17:
					cout << "MBC3" << endl;
					break;
				case 18:
					cout << "MBC3+RAM" << endl;
					break;
				case 19:
					cout << "MBC3+RAM+Battery" << endl;
					break;
				case 25:
					cout << "MBC5" << endl;
					break;
				case 26:
					cout << "MBC5+RAM" << endl;
					break;
				case 27:
					cout << "MBC5+RAM+Battery" << endl;
					break;
				case 28:
					cout << "MBC5+Rumble" << endl;
					break;
				case 29:
					cout << "MBC5+Rumble+RAM" << endl;
					break;
				case 30:
					cout << "MBC5+Rumble+RAM+Battery" << endl;
					break;
				default:
					cout << "Unknown" << endl;
					break;
				}

			// Source : https://gbdev.gg8.se/wiki/articles/The_Cartridge_Header		
			// 00h -  32KByte (no ROM banking)
			// 01h -  64KByte (4 banks)
			// 02h - 128KByte (8 banks)
			// 03h - 256KByte (16 banks)
			// 04h - 512KByte (32 banks)
			// 05h -   1MByte (64 banks)  - only 63 banks used by MBC1
			// 06h -   2MByte (128 banks) - only 125 banks used by MBC1
			// 07h -   4MByte (256 banks)
			// 08h -   8MByte (512 banks)
			// 52h - 1.1MByte (72 banks)
			// 53h - 1.2MByte (80 banks)
			// 54h - 1.5MByte (96 banks)
			cout << "ROM Size :                                   ";
			switch (static_cast<unsigned short>(bytes[328]))
				{
				case 0:
					cout << "32 KByte" << endl;
					break;
				case 1:
					cout << "64KByte" << endl;
					break;
				case 2:
					cout << "128KByte" << endl;
					break;
				case 3:
					cout << "256KByte" << endl;
					break;
				case 4:
					cout << "512KByte" << endl;
					break;
				case 5:
					cout << "1MByte" << endl;
					break;
				case 6:
					cout << "2MByte" << endl;
					break;
				case 7:
					cout << "4MByte" << endl;
					break;
				case 8:
					cout << "8MByte" << endl;
					break;
				case 82:
					cout << "1.1MByte" << endl;
					break;
				case 83:
					cout << "1.2MByte" << endl;
					break;
				case 84:
					cout << "1.5MByte" << endl;
					break;
				default:
					cout << "Unknown" << endl;
					break;
				}
			
			// Source : https://gbdev.gg8.se/wiki/articles/The_Cartridge_Header		
			// 00h - Japanese
			// 01h - Non-Japanese
			cout << "Destination Code :                           ";
			switch (static_cast<unsigned short>(bytes[330]))
				{
				case 0:
					cout << "Japanese" << endl;
					break;
				case 1:
					cout << "Non-Japanese" << endl;
					break;
				}
			
			cout.flush();
			std::string hex_data = oss.str();
			cout << hex_data << endl;
		}
	}
	
	return 0;
}
