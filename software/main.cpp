#include <stdint.h>

typedef uint8_t u8; typedef int8_t s8;
typedef uint16_t u16; typedef int16_t s16;
typedef uint32_t u32; typedef int32_t s32;
typedef uint64_t u64; typedef int64_t s64;
typedef unsigned int uint;

#include <iostream>
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
	cout << "  #####  ######    ##  #####  ##      ######   ####  #    # #      ###### #    #" << endl;
	cout << endl;
		
	if ( argc < 4 )
	{
		cout << "Usage 1:  " << argv[0] << " {Arduino_Serial_Dev} dump_rom {your_name}.(gb|gbc)\n";
		cout << "Usage 2:  " << argv[0] << " {Arduino_Serial_Dev} dump_ram {your_name}.sav\n";
		cout << endl;
		return 0;
	}
	
	communicator the_communicator( argc, argv );
		
	return 0;
}
