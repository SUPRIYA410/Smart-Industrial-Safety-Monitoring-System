#include"header.h"

#define Red (1<<19)
#define Yellow (1<<18)
#define Green (1<<17)
#define PIR (1<<11)
#define FLAME (1<<23)
unsigned int d3;

int main()
{
float temp;//,pir;
uart0_init(9600);
adc_init();
temp=temperature();
while(1)
{
lcd_cmd(0x08);
lcd_string("Temperature : ");
lcd_data(temp);
lcd_string("\r\n");
lcd_cmd(0xc0);
lcd_string("Satus : Safe \r\n");

//temp=temperature();
if(temp<40)
{
uart0_tx_string("temperature:\n");
uart0_tx_float(temp);
uart0_tx_string("%c \r\n");
uart0_tx_string("safe\r\n");
delay_ms(200);


if(((IOPIN0>>11)&1)==1)					                                                                                                                                                         
uart0_tx_string("\r\n");
uart0_tx_string("PIR Sensor : ");
//uart0_tx_integer(adc_read(0));
uart0_tx_string("worker detected\r\n");
delay_ms(100);

if(((IOPIN0>>23)&1)==1)
{
uart0_tx_string("Flame Sensor : ");
uart0_tx_string("No Fire\r\n");
}
uart0_tx_string("LED status: GREEN\r\n");
delay_ms(100);
}
else
{
uart0_tx_string("Temperature:\n");
//delay_ms(100);
uart0_tx_float(temp);
uart0_tx_string("%c \r\n");
uart0_tx_string("Machine Status : ");
uart0_tx_string("not safe\r\n");
delay_ms(200);
if(((IOPIN0>>11)&1)==1)
{
uart0_tx_string("PIR Sensor : ");
uart0_tx_string("worker detected:\r\n"); 
}
delay_ms(100);

if(((IOPIN0>>23)&1)==1)
{
uart0_tx_string("Flame Sensor : ");
uart0_tx_string("Fire detected\r\n");
}
uart0_tx_string("LED status:RED\r\n");
delay_ms(100);
}
}
}

