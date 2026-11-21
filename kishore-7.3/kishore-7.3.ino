#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1 << PB0);     // PB0 as output (LED)
    DDRD &= ~(1 << PD0);    // PD0 as input (Push button)

    PORTD |= (1 << PD0);    // Enable internal pull-up

    while(1)
    {
        if (!(PIND & (1 << PD0)))
        {
            PORTB |= (1 << PB0);   // LED ON
        }
        else
        {
            PORTB &= ~(1 << PB0);  // LED OFF
        }
    }

    return 0;
}