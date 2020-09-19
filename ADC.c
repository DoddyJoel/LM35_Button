#include "header.h"

void ADC_init(){
    // ADC right Adjust Result
    ADMUX &=~(1<<ADLAR);

    // Voltage Reference selections for ADC
    ADMUX |=(1<<REFS0);
    ADMUX &=~(1<<REFS1);

    // Prescaling:8000000/64 = 125KHz
    ADCSRA &=~(1<<ADPS0);
    ADCSRA |= (1<<ADPS1);
    ADCSRA |= (1<<ADPS2);

}

float ADC_GetData(int canal){
     ADMUX &=~ 0x0F;
     ADMUX |=canal;

     //Encendemos el ADC
     ADCSRA |= (1<<ADEN);
     _delay_us(10);

     //Mandamos el muestreo
     ADCSRA |=(1<<ADSC);

     //Esperamos a que muestree, leyendo el flag
     while(!(ADCSRA & (1<<ADIF)));
     ADCSRA |=(1<<ADIF);

     // Apagamos el ADC
     ADCSRA &=~(1<<ADEN);

     return ADC;

}