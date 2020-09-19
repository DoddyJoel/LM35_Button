#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif
# define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

void ADC_init();
float ADC_GetData(int canal);
void serial_begin();
unsigned char serial_read_char();
void serial_print_char(unsigned char caracter);
void serial_print_str(char* cadena);