#ifndef	_POWERLED_H
#define _POWERLED_H

#include "led.h"    // include led header properties

// Define aliases for the type unsigned 8int-bit
typedef uint8_t led_elec_type;  // led electric type
typedef uint8_t led_dim_type;   // led dim type


typedef enum
{
    /* current of the power led */
	CURR_LOW = 10,   /* 10mA */
	CURR_NORMAL = 20,
	CURR_HIGH = 35,
	CURR_VERY_HIGH = 60


}LedCurrent_Type;

typedef enum
{
    /* diameter of the power led */
	DIAM_2MM = 2,  /* 2mm */
	DIAM_5MM = 5,
	DIAM_7MM = 7

}LedDiamter_Type; 

typedef enum
{
    /* voltage of the power led */
    VOL_LOW = 3, /*3 volts*/
	VOL_NORMAL = 5,
	VOL_HIGH = 9
	
}LedVoltage_Type;


// struct that combines different various attributes to a power LED
typedef struct
{
	Led_Type super;  // base type defined in Led.h
	LedDiamter_Type diameter;
	LedCurrent_Type current;
	LedVoltage_Type voltage;

}PowerLed_Type;

/* constructor for the power LED */
void PowerLed_ctor(PowerLed_Type * const me,
									 LedColor_Type   _color,
									 LedState_Type	_state,
									 LedDiamter_Type  _diameter,
									 LedCurrent_Type   _current,
									 LedVoltage_Type  _voltage);


/* sets current, diameter, voltage value of led */
void PowerLed_setCurrent(PowerLed_Type * const me,LedCurrent_Type  _current );
void PowerLed_setDiameter(PowerLed_Type * const me, LedDiamter_Type _diameter);
void PowerLed_setVoltage(PowerLed_Type *const me, LedVoltage_Type _voltage);

/* computes power of led*/
led_elec_type PowerLed_computePower(PowerLed_Type * const me);

/* retrieves current value of led */
led_elec_type PowerLed_getCurrent(PowerLed_Type * const me);

/* retrieves the diamater value of led */
led_elec_type PowerLed_getDiameter(PowerLed_Type * const me);

/* retrives the voltage value of led*/
led_elec_type PowerLed_getVoltage(PowerLed_Type * const me);









#endif