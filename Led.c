#include "Led.h"  // include led header file


void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state){ //Konstruktor för LED
  
	me->color  = _color; //Tilldelar angivna färgen till LED
	me->state  = _state;  //Tilldelar angivna tillståndet till LED

	//Hårdvaru-initialiseringen
	RCC->AHB1ENR |= LED_PORT_CLOCK;  //Aktiverar vi klocksignalen för porten vi skall arbeta med (PortB)
	
	switch(_color){   // olika LED-färger att välja mellan
		 
		case RED: //Kontrollerar värdet av color
			LED_PORT->MODER |=LED_RED_MODE_BIT; //Ställer in lägesbiten 27 för alternativ RED
		  if(me->state  == ON){  // om lampan lyser
			   LED_PORT->ODR |= LED_RED_PIN; //Slår på LED 13 om tillståndet är ON
				printf("The RED Led is set ON \n\r");
			}
			else{  // annars om lampan är släckt
			  LED_PORT->ODR &= ~LED_RED_PIN; //Slår av LED om tillståndet är OFF
        printf("The RED Led is set OFF \n\r");

			}
		break;
		
		case YELLOW:
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
        printf("The YELLOW Led is set OFF \n\r");

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("The BLUE Led is set OFF \n\r");

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("The GREEN Led is set OFF \n\r");

			}
		break;
	
	}
}


void Led_setState(Led_Type * const me, LedState_Type _state){
//En funktion för att tilldela LED-objektet sitt tillstånd
	 me->state =  _state;

	 
	
	switch(me->color){
		 
		case RED:
			LED_PORT->MODER |=LED_RED_MODE_BIT; //Ställer in lägesbiten till rätt alternativ funktion
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_RED_PIN; //Slår på röd LED om state är ON
				printf("The RED Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_RED_PIN; //Slår av röd LED om state är OFF
        printf("The RED Led is set OFF \n\r");

			}
		break;
		
		case YELLOW:
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
        printf("The YELLOW Led is set OFF \n\r");

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("The BLUE Led is set OFF \n\r");

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("The GREEN Led is set OFF \n\r");

			}
		break;
	
	}
}


LedState_Type Led_getState(Led_Type * const me){
//Funktion för att avläsa nuvarande status av LED-objektet
	switch(me->color){
		
		case RED:
			   printf("The RED Led is currently %d \n\r",me->state);
				 break;
		
		case GREEN:
			   printf("The GREEN Led is currently %d \n\r",me->state);
				 break;

		case BLUE:
			   printf("The BLUE Led is currently %d\n\r",me->state);
				 break;
				 
		case YELLOW:
			   printf("The YELLOW Led is currently  %d \n\r",me->state);
				 break;
		
		
	 }
  
	return me->state;
}
