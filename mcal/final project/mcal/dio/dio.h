#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

typedef enum
{
    DIOA = 0,
    DIOB,
    DIOC,
    DIOD,
} dio_t;

typedef enum{
    PIN_0 = 0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
} dio_pin_t;

typedef enum
{
    INPUT = 0,
    OUTPUT = 1
} dio_direction_t;

typedef enum
{
    LOW = 0,
    HIGH = 1
} dio_level_t;

void dio_set_direction(dio_t port, dio_pin_t pin, dio_direction_t direction);
void dio_set_level(dio_t port, dio_pin_t pin, dio_level_t value);
dio_level_t dio_get_level(dio_t port, dio_pin_t pin);

void dio_set_port_direction(dio_t port, dio_direction_t direction);
void dio_set_port_level(dio_t port, dio_level_t value);

void dio_pin_toggel(dio_t PORTx, dio_pin_t pin, dio_level_t value);

#endif
