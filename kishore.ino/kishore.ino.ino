#define F_cpu 160000000UL
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
  DDRD|=(1<<PB3);
  while(1)
  {
    PORTB |=(1<<PB3);
    _delay_ms(1000);
    PORTB &=-(1<<PB3);
    _delay_ms(1000);
  }
  return 0;
}
