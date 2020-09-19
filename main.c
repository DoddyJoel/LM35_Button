#include "header.h"
char float_txt [4]={0};
int main(){
    serial_begin();
    ADC_init();
    DDRD |=~(1<<DDD5);
    while (1)
    {
        float adc=(ADC_GetData(0)*5/1023.0)*100;

        if(bit_is_clear(PIND,PD5)){
            dtostrf(adc,3,2,float_txt);
            serial_print_str(float_txt);
            serial_print_str("\r\n");
            _delay_ms(1000);
        }      
    }
    
    return 0;
}