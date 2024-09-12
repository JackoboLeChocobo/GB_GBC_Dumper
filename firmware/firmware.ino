#include "misc_types.h"

#include "some_globals.h"
#include "aux_code.h"
#include "tpak_class.h"
#include "cart_helper_class.h"

void setup()
  {
  memset( N64_raw_dump, 0, 33 );
	
	pinMode( 13, OUTPUT );
	
	// Communication with gamecube controller on this pin
	// Don't remove these lines, we don't want to push +5V to the controller
	digitalWrite( N64_PIN, LOW );  
	pinMode( N64_PIN, INPUT );
	
	// Initialize the gamecube controller by sending it a null byte.  This
	// is unnecessary for a standard controller, but is required for the
	// Wavebird.
	unsigned char initialize = 0x00;
	noInterrupts();
	N64_send( &initialize, 1 );
	N64_read_addr();
	
	// Stupid routine to wait for the gamecube controller to stop
	// sending its response. We don't care what it is, but we
	// can't start asking for status if it's still responding
	int x;
	for ( x=0; x<64; x++ )
	  {
		if (!N64_QUERY) // make sure the line is idle for 64 iterations, should be plenty.x
		  {
			x = 0;
      }
	  }
	
	interrupts();
	Serial.begin(115200);
	Serial.setTimeout(2); //Or 20? // 2 ms timeout
  }

void loop()
  {
	tpak_stuff_2();
  }