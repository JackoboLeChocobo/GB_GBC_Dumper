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

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "misc_types.hpp"
#include "stuffs.hpp"

int do_select_for_write( int fd )
	{
	fd_set readfds, writefds, exceptfds;
	int nfds = fd + 1;
	
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	FD_ZERO(&exceptfds);
	
	FD_SET( fd, &writefds );												// We want to wait until we can write to the Arduino.
	timeval timeout = { 0, 10000 };											// Wait 10 ms
	
	if ( select( nfds, &readfds, &writefds, &exceptfds, &timeout ) < 0 )
		return 1;
	if ( !FD_ISSET( fd, &writefds ) )
		return 2;
		
	return 0;
	}

int do_select_for_read( int fd )
	{
	fd_set readfds, writefds, exceptfds;
	int nfds = fd + 1;
	
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	FD_ZERO(&exceptfds);
	
	FD_SET( fd, &readfds );														// We want to wait until we can read from the Arduino.
	timeval timeout = { 0, 10000 };												// Wait 10 ms

	if ( select( nfds, &readfds, &writefds, &exceptfds, &timeout ) < 0 )
		return 1;

	if ( !FD_ISSET( fd, &readfds ) )
		return 2;
	
	return 0;
	}

// Read text from the Arduino
void do_arduino_read( int fd, string& from_arduino )
	{
	do_select_for_read(fd);
	from_arduino = "";
	
	char c = 0;
	do
		{
		int num_read = read( fd, &c, 1 );
		if ( num_read > 0 )
			from_arduino += c;
		}
	while ( c != '\n' );
	}
