#define F_cpu 160000000UL
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
  DDRB|=(1<<PB5);
  DDRD &=~(1<<PD0);
  while(1) 
  {
   if(PINB &(1<<PD0))
   {
    PORTB |=(1<<PB5);
   }
   else
   {
    PORTB &=~(1<<PB5);
   }
  }
  return 0;
}