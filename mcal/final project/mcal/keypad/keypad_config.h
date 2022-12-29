#ifndef KYPAD_CONFIG_H_
#define KYPAD_CONFIG_H_


#define KEYPAD_RAW_NUM			4
#define KEYPAD_COLUMN_NUM		4

#define KEYPAD_RAW_ARR_VALUE {	\
	{DIOC, PIN_0},    \
	{DIOC, PIN_1},   \
	{DIOC, PIN_2},  \
	{DIOC, PIN_3}, \
};


#define KEYPAD_COL_ARR_VALUE {	\
	{DIOC, PIN_4},    \
	{DIOC, PIN_5},   \
	{DIOC, PIN_6},  \
	{DIOC, PIN_7}, \
};

#define KEYPAD_KEY_VALUES {		\
	{'1','2','3','4'},			\
	{'5','6','7','8'},			\
	{'A','B','C','D'},			\
	{'D','E','F','0'},			\
};
#define RELEASED_LEVEL	LOW
#define PRESSED_LEVEL	HIGH

#define  NO_PRESS_VAL   0

/*#define KEYPAD_R0_PIN		DIO_PIN6
#define KEYPAD_R0_PORT		DIO_PORTC

#define KEYPAD_R1_PIN		DIO_PIN7
#define KEYPAD_R1_PORT		DIO_PORTC

#define KEYPAD_R2_PIN		DIO_PIN6
#define KEYPAD_R2_PORT		DIO_PORTA

#define KEYPAD_R3_PIN		DIO_PIN7
#define KEYPAD_R3_PORT		DIO_PORTA

#define KEYPAD_C0_PIN		DIO_PIN2
#define KEYPAD_C0_PORT		DIO_PORTC

#define KEYPAD_C1_PIN		DIO_PIN3
#define KEYPAD_C1_PORT		DIO_PORTC

#define KEYPAD_C2_PIN		DIO_PIN4
#define KEYPAD_C2_PORT		DIO_PORTC

#define KEYPAD_C3_PIN		DIO_PIN5
#define KEYPAD_C3_PORT		DIO_PORTC


*/

#endif /* KYPAD_CONFIG_H_ */
