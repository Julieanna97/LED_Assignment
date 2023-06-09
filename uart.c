#include "uart.h"            // include header file and its contents

void USART2_Init(void){      // construction for UART function 

 // RCC = Reset and clock control
 RCC->APB1ENR  |=  0x20000;  // Enable clock to USART2-device at bit 17.

 RCC->AHB1ENR   |=0x01;  // Enable clock to Port A

 
 GPIOA->MODER &=~0x00F0;  // Set moder 2 & 3 to reset state
 GPIOA->MODER |= 0x00A0; // Set moder 2 & 3 to alternative function mode

 GPIOA->AFR[0] &= ~0xFF00; // Set type of alternative functionn to AF7
 GPIOA->AFR[0] |= 0x7700; 


USART2->BRR  =  0x0683; // Manage the baud rate on the development board
USART2->CR1  =  0x000C; // Enables transmitter and receiver
USART2->CR2  =  0x000;  // Resets CR2
USART2->CR3  =  0x000;  // Resets CR2
USART2->CR1  |=  0x2000;  // Enables USART at bit 13
	
	

}

int USART2_write(int ch){  // Function to write with UART.

	while(!(USART2->SR & 0x0080)){} // while data transmission is incomplete/empty
	USART2->DR = (ch & 0xFF);  // write the next data character.
	
  return ch; // Basic function that writes to the registry if it is empty
}

int USART2_read(void){    // Function to read with UART.
  while(!(USART2->SR & 0x0020)){} // while read data register is incomplete/empty
	return USART2->DR; // read the next data character.
  // Basic function that reads from the register when it is not empty.
}

struct __FILE { int handle; };  // A structure for IO-events
FILE __stdin  = {0};
FILE __stdout = {1};
FILE __stderr = {2};


int fgetc(FILE *f) {
    int c;

    c = USART2_read();  // read character from the terminal
    // if line statement in case of line break
    if (c == '\r') {    // if it detects backslash, after calling read. it will go to new line.
        USART2_write(c);   // write character to the terminal
        c = '\n';
    }

    USART2_write(c);        // print out the characters

    return c;
}



int fputc(int c, FILE *f) {  // input function to write to the terminal
    return USART2_write(c);  
}


int n;
char str[80];
		
void test_setup(void){
	
  // initiate user input
	printf("please enter a number: ");
	scanf("%d", &n);
	printf("the number entered is: %d\r\n", n);
	printf("please type a character string: ");
	gets(str);
	printf("the character string entered is: ");
	puts(str);
	printf("\r\n");
	
}