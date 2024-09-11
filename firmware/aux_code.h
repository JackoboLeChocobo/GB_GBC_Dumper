#ifndef aux_code_h
#define aux_code_h

#include "some_globals.h"
#include "pins_arduino.h"


// This should be used for the Arduino Micro or Arduino Leonardo.
static const byte micro_bitwisse_thing = 0x02;

// This should be used for the Arduino Mega or Arduino Mega 2560.
static const byte mega_bitwise_thing = 0x10;

#if defined (__AVR_ATmega32U4__)
	#define PORT_THING micro_bitwise_thing
#elif ( defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) )
	#define PORT_THING mega_bitwise_thing
#else
	#error This program doesn't work on your Arduino (yet)!
#endif

#define N64_PIN 2
//#define N64_PIN_DIR DDRD

// these two macros set arduino pin 2 to input or output, which with an
// external 1K pull-up resistor to the 3.3V rail, is like pulling it high or
// low.  These operations translate to 1 op code, which takes 2 cycles
#if defined (__AVR_ATmega32U4__)
	#define N64_HIGH DDRD &= ~PORT_THING
	#define N64_LOW DDRD |= PORT_THING
	#define N64_QUERY (PIND & PORT_THING)
#elif ( defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) )
	#define N64_HIGH DDRE &= ~PORT_THING
	#define N64_LOW DDRE |= PORT_THING
	#define N64_QUERY (PINE & PORT_THING)
#else
	#error This program doesn't work on your Arduino (yet)!
#endif



void print_mem_managed();
void print_mem_managed2();
void write_mem_managed();

void print_crc_managed();

void clear_mem_dump();

void manage_mem_dump();		// arrange data into bytes 



void N64_stuff( unsigned char *buff, char length );


void N64_stuff_2( unsigned char *buff, char length );


void tpak_stuff_2();


void tpak_stuff();


void translate_raw_data();



/**
 * This sends the given byte sequence to the controller
 * length must be at least 1
 * Oh, it destroys the buffer passed in as it writes it
 */
void N64_send(unsigned char *buffer, char length);


void N64_get();


void loop2();


word calc_addr_crc( word address );


unsigned char calc_data_crc( unsigned char *data );

void N64_read_addr();


bool cmp_buf( const char* to_cmp, int num_recv );


#endif		// aux_code_h
