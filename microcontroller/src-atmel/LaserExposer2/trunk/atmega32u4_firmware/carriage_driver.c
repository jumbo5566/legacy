//carriage_driver.c
//used hardware:
//* Timer1 PWM (OC1A, OC1B)


//IH1 <- OC1A
//IH2 <- OC1B

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "config.h"
#include "carriage_driver.h"

void bts7741g_stop()
{
	bts7741g_IL1_HIGH
	bts7741g_IL2_HIGH
	OCR1A=0;		//TODO: verify
	OCR1B=0;
}

void bts7741g_freerunning()
{
	bts7741g_IL1_LOW
	bts7741g_IL2_LOW
	OCR1A=0;
	OCR1B=0;
}

//if !speed stop condition is called
void bts7741g_forward(uint16_t speed)
{
	if(!speed)
		bts7741g_stop();
	
	bts7741g_IL1_LOW
	bts7741g_IL2_HIGH
	OCR1A=speed;
	OCR1B=0;
}

//if !speed stop condition is called
void bts7741g_backwards(uint16_t speed)
{
	if(!speed)
		bts7741g_stop();
		
	bts7741g_IL1_HIGH
	bts7741g_IL2_LOW
	OCR1A=0;
	OCR1B=speed;
}

//Timer1
void timer1_init()
{
	TCCR1A=_BV(COM1A1)|_BV(COM1B1)|_BV(WGM11)|_BV(WGM10);		//PWM Clear OC4A on Compare Match, set on TOP,10 bit PWM
	TCCR1B=_BV(WGM12)|_BV(CS11)|_BV(CS10);	//clk prescaler 1:64
	OCR1A=0;	//always low ?
	OCR1B=0;	//always low ?
}

#if 0
#define START_TIMER3_1 TCCR3B = _BV(CS30);	//prescaler to 1:1
#define START_TIMER3_8 TCCR3B = _BV(CS31);	//prescaler to 1:8
#define START_TIMER3_256 TCCR3B = _BV(CS32);	//prescaler to 1:256
#define STOP_TIMER3 TCCR3B = 0;
#endif
