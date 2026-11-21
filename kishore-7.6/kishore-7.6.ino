#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define RS PB0
#define EN PB1
void lcd_enable(void)
{
    PORTB |= (1 << EN);
    _delay_ms(1);
    PORTB &= ~(1 << EN);
    _delay_ms(1);
}
void lcd_nibble(unsigned char data)
{
    PORTB = (PORTB & 0x0F) | (data & 0xF0);
    lcd_enable();
}
void lcd_command(unsigned char cmd)
{
    PORTB &= ~(1 << RS);
    lcd_nibble(cmd & 0xF0);
    lcd_nibble(cmd << 4);
    _delay_ms(2);
}
void lcd_data(unsigned char data)
{
    PORTB |= (1 << RS);
    lcd_nibble(data & 0xF0);
    lcd_nibble(data << 4);
    _delay_ms(2);
}
void lcd_string(char *str)
{
    while(*str)
    {
        lcd_data(*str++);
    }
}
void lcd_init(void)
{
    DDRB = 0xFF;
    _delay_ms(20);

    PORTB &= ~(1 << RS);

    lcd_nibble(0x30);
    _delay_ms(5);
    lcd_nibble(0x30);
    _delay_ms(1);
    lcd_nibble(0x30);
    _delay_ms(1);
    lcd_nibble(0x20);

    lcd_command(0x28);
    lcd_command(0x0C);
    lcd_command(0x06);
    lcd_command(0x01);
}
int main(void)
{
    lcd_init();

    lcd_command(0x80);
    lcd_string("YOUR NAME");

    lcd_command(0xC0);
    lcd_string("YOUR USN");

    while(1)
    {
    }

    return 0;
}