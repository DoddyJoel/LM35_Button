#include "header.h"

void serial_begin(){

    UCSR0B=0b00011000;
    UCSR0C=0b00000110;
    UBRR0=103;
}

unsigned char serial_read_char(){

    if(UCSR0A &(1<<7)){
        return UDR0;
    }else
    {
        return 0;
    }
}


void serial_print_char(unsigned char caracter){
    while (!(UCSR0A &(1<<5)));
    UDR0=caracter;
    
}


void serial_print_str(char* cadena){
    while (*cadena !=0x00)
    {
        serial_print_char(*cadena);
        cadena++;
    }
    
}