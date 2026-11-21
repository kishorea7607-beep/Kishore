#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    unsigned char count = 0;

    DDRB = 0x0F;         
    DDRD &= ~(1 << PD0);  

    PORTD |= (1 << PD0);  

    while(1)
    {
        if(!(PIND & (1 << PD0)))
        {
            _delay_ms(50);  

            if(!(PIND & (1 << PD0)))
            {
                count++;

                if(count > 15)
                    count = 0;

                PORTB = (PORTB & 0xF0) | count;

                while(!(PIND & (1 << PD0)));
                _delay_ms(50);
            }
        }
    }

    return 0;
}