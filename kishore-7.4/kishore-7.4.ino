#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0x07;    

    while(1)
    {
        PORTB = 0x01;  
        _delay_ms(5000);

        PORTB = 0x02;    
        _delay_ms(2000);

        PORTB = 0x04;    
        _delay_ms(5000);
    }

    return 0;
}