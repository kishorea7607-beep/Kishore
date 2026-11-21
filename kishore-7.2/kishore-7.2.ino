#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0x0F;      

    while(1)
    {
        PORTB = 0x01; 
        _delay_ms(500);

        PORTB = 0x02;  
        _delay_ms(500);

        PORTB = 0x04; 
        _delay_ms(500);

        PORTB = 0x08;  
        _delay_ms(500);
    }

    return 0;
}
