#include<lpc21xx.h>
#include"header.h"
void lcd_data(unsigned char data)
{
IOCLR1=0XFF<<16;
IOSET1=(data & 0xF0)<<16;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;

IOCLR1=0XFE<<16;
IOSET1=(data & 0x0F)<<20;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
}
void lcd_cmd(unsigned char cmd)
{
IOCLR1=0XFF<<16;
IOSET1=(cmd & 0xF0)<<16;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;

IOCLR1=0XFE<<16;
IOSET1=(cmd & 0x0F)<<20;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
}

void lcd_string(char *ptr)
{
while(*ptr!=0)
{
lcd_data(*ptr);
ptr++;
}
}
