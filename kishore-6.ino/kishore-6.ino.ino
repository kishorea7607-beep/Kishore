#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

// LCD control pins
#define RS PB0
#define EN PB1

// Send enable pulse
void lcd_enable(void)
{
    PORTB |= (1 << EN);
    _delay_ms(1);
    PORTB &= ~(1 << EN);
    _delay_ms(1);
}

// Send 4-bit data
void lcd_nibble(unsigned char data)
{
    PORTB = (PORTB & 0x0F) | (data & 0xF0);
    lcd_enable();
}

// Send command to LCD
void lcd_command(unsigned char cmd)
{
    PORTB &= ~(1 << RS);

    lcd_nibble(cmd & 0xF0);
    lcd_nibble(cmd << 4);

    _delay_ms(2);
}

// Send data to LCD
void lcd_data(unsigned char data)
{
    PORTB |= (1 << RS);

    lcd_nibble(data & 0xF0);
    lcd_nibble(data << 4);

    _delay_ms(2);
}

// Initialize LCD
void lcd_init(void)
{
    DDRB = 0xFF;

    _delay_ms(20);

    PORTB &= ~(1 << RS);

    // 4-bit initialization sequence
    lcd_nibble(0x30);
    _delay_ms(5);

    lcd_nibble(0x30);
    _delay_ms(1);

    lcd_nibble(0x30);
    _delay_ms(1);

    lcd_nibble(0x20);

    // LCD configuration
    lcd_command(0x28);  // 4-bit, 2 lines
    lcd_command(0x0C);  // Display ON, cursor OFF
    lcd_command(0x06);  // Auto increment
    lcd_command(0x01);  // Clear display
}

// Display string
void lcd_string(char *str)
{
    while (*str)
    {
        lcd_data(*str++);
    }
}

// Main function
int main(void)
{
    lcd_init();
    lcd_command(0x80);
    lcd_string("HELLO STUDENTS");

    lcd_command(0xC0);
    lcd_string("WELCOME TO AVR");

    while (1)
    {
    }
}