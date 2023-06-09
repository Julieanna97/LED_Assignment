#include "uart.h"  // including our header file

int main(){   // main function
  
	USART2_Init();   // establishing our UART-function from uart.c
	
	//test_setup();
	printf("Hello there from main function");
	while(1){  // loop that prints what we request upon request
	
	}

}