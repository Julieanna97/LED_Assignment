#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "uart.h"  // Includes UART-driver for future use such state analysis
#include "stm32f4xx.h"  // Includes the header file for our development board to reference the hardware       

#define	LED_PORT 		GPIOB  // Defines Port B as the port to be used for the LED work

#define	LED_PORT_CLOCK  (1U<<1)  // Defines the clock signal for the port where LED should be connected

#define LED_RED_PIN	(1U<<14)  // Defines the pin on the port to be used for the respective LED color
#define LED_GREEN_PIN	(1U<<12)
#define	LED_BLUE_PIN	(1U<<15)
#define LED_YELLOW_PIN	(1U<<13)

#define LED_RED_MODE_BIT  (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

// Done with the translation of binary values to its purpose


// constant definitions

typedef enum {
	
	RED = 0,   // constants for the different colors of LED
	GREEN = 1,
	YELLOW = 2,
	BLUE = 3

}LedColor_Type;


typedef enum{
	
	OFF = 0,   // constants för on and off state
 	ON = 1

}LedState_Type;


/*Led's attributes*/
class Led{
	
	private:
		LedColor_Type  color; /* Color of led*/
		LedState_Type  state; /* State of Led*/
		
	public:

		Led(LedColor_Type _color,LedState_Type _state);
		void setState( LedState_Type _state);
		LedState_Type getState() const;

};


#endif
