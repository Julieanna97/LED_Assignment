#include "led.h"

/* Libraries for time */
#include <chrono>
#include <thread>

LedState_Type led1_state;

int main(void)
{
	
	USART2_Init();

	/* Set LEDs state to OFF */
	// Initialize the LED object
	Led* redLed =  new Led(RED,OFF);

	led1_state = redLed->getState();

	Led green(GREEN, OFF);
	Led yellow(YELLOW, OFF);
	Led blue(BLUE, OFF);

	while(1)
	{
		// Switching "ON" LEDs
		redLed->setState(ON);
		// Delay for a specified duration
		this_thread::sleep_for(chrono::milliseconds(1000)); // Delay for 1 second
		green.setState(ON);
		this_thread::sleep_for(chrono::milliseconds(1000));
		yellow.setState(ON);
		this_thread::sleep_for(chrono::milliseconds(1000));
		blue.setState(ON);
		this_thread::sleep_for(chrono::milliseconds(1000));

		// Switching "OFF" LEDs in reverse
		blue.setState(OFF);
		this_thread::sleep_for(chrono::milliseconds(1000));
		yellow.setState(OFF);
		this_thread::sleep_for(chrono::milliseconds(1000));
		green.setState(OFF);
		this_thread::sleep_for(chrono::milliseconds(1000));
		redLed->setState(OFF);
		this_thread::sleep_for(chrono::milliseconds(1000));

	}


	return 0;
}
