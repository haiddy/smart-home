#include <avr/delay.h>
#include "lcd.h"
#include "lcd_config.h"

#define LCD_CMD_FUNCTION_SET
#define LCD_CMD_CLEAR_DISPLAY
#define LCD_CMD_ENTRY

void lcd_init()
{
    _delay_ms(30);
    //pin init
    dio_set_direction(LCD_EN_PORT, LCD_EN_PIN, OUTPUT);
    dio_set_direction(LCD_RS_PORT, LCD_RS_PIN, OUTPUT);
    dio_set_port_direction(LCD_DATA_PORT, OUTPUT);

    //LCD Init
    lcd_send_cmd(0b00111000); // function set
    lcd_send_cmd(0b00000001); // clear
    _delay_ms(2);
    lcd_send_cmd(0b00000110); // entry mode
    lcd_send_cmd(0b00001101); // display on

}


void lcd_send_cmd(uint8_t command)
{
    //read/write -> always write
    //RS-> CMD:0
    dio_set_level(LCD_RS_PORT, LCD_RS_PIN, LOW);
    // write value on data bus
    dio_set_port_level(LCD_DATA_PORT, command);
    //EN-> pulse
    dio_set_level(LCD_EN_PORT, LCD_EN_PIN, HIGH);
    _delay_us(500);
    dio_set_level(LCD_EN_PORT, LCD_EN_PIN, LOW);
}


void lcd_send_data(char data)
{
    //RS-> data:1
    dio_set_level(LCD_RS_PORT, LCD_RS_PIN, HIGH);
    // write value on data bus
    dio_set_port_level(LCD_DATA_PORT, data);
    //EN-> pulse
    dio_set_level(LCD_EN_PORT, LCD_EN_PIN, HIGH);
    _delay_us(500);
    dio_set_level(LCD_EN_PORT, LCD_EN_PIN, LOW);

}

void lcd_send_str(char str[])
{
    //RS -> data:1
    dio_set_level(LCD_RS_PORT, LCD_RS_PIN, HIGH);
    uint8_t i = 0;

    while(str[i] != '\0')
    { // write value on data bus
        dio_set_port_level(LCD_DATA_PORT, str[i]);
        i++;
        // signal en pin
        dio_set_level(LCD_EN_PORT, LCD_EN_PIN, HIGH);
        _delay_us(500);
        dio_set_level(LCD_EN_PORT, LCD_EN_PIN, LOW);
        _delay_us(500);
    }
}

void lcd_set_curser(uint8_t x, uint8_t y)
{
    uint8_t address = x;
    if(1 == y)
    {
        address += 0x40;
    }
    lcd_send_cmd(0b10000000 | address);
}


void lcd_set_specialcharc(uint8_t arr[], uint8_t block_num)
{
    uint8_t address = block_num * 8;
    lcd_send_cmd(0b01000000 | address);
    _delay_us(30);
    for(uint8_t i = 0; i < 8; i++)
    {
        lcd_send_data(arr[i]);
        _delay_us(30);
    }
}
void lcd_send_specialcharc(uint8_t block_num, uint8_t x, uint8_t y)
{
    lcd_set_curser(x,y);
    lcd_send_data(block_num);
}
