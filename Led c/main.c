#include "uart.h"  // including our header file
#include "Led.h"

int main(){   // main function
  
	USART2_Init();   // establishing our UART-function from uart.c
	
	//test_setup();
	printf("Hello there from main function");
	while(1){  // loop that prints what we request upon request
	
	}

	Led_ctor(&led1, RED, OFF);
	Led_ctor(&led2, BLUE, ON);

	Led_getState(&led1);
	Led_getState(&led2);

	Led_setState(&led1, ON);

}