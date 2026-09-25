#include"header.h"

float temperature_read(void)
{
unsigned int adc_value;
float vout, temp;
adc_value=adc_read(1);
vout=(adc_value*3.3)/1023;
temp=vout*100;
return temp;
}
