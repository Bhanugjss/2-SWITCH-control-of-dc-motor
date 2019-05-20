/*
 * GccApplication4.c
 *
 * Created: 16-05-2019 09:50:28
 * Author : G J S S BHANU
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void PWM_init_()
{
	TCCR0 |=(1<<WGM00) |(1<<WGM01)|(1<<COM01)|(1<<CS00);
	TCCR2 |=(1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<CS20);
	DDRB|=(1<<PB3);
	DDRD|=(1<<PD7);
}


int main(void)
{
	DDRD&=~(1<<PD0);
	DDRD&=~(1<<PD1);
	DDRD&=~(1<<PD2);
	DDRD&=~(1<<PD3);
	PWM_init_();
    while (1) 
    {
		if((PIND&(1<<PD0))==0){
			OCR0=0;
			OCR2=100;
			_delay_ms(1000);
    }
	if((PIND&(1<<PD1))==0){
		OCR0=100;
		OCR2=0;
		_delay_ms(1000);
	}
	if((PIND&(1<<PD2))==0){
		OCR0=0;
		OCR2=200;
		_delay_ms(1000);
	}
	if((PIND&(1<<PD3))==0){
		OCR0=200;
		OCR2=0;
		_delay_ms(1000);
	}
	
}

}