#include"header.h"
void uart0_init(unsigned int baud)
{
unsigned int pclk, result=0;
if(VPBDIV==0x0)
pclk=15000000;
else if(VPBDIV==0x04)
pclk=60000000;
else if(VPBDIV==0x03)
pclk=30000000;
result=pclk/(16*baud);
PINSEL0|=0x05;
U0LCR=0x83;
U0DLL=result & 0xff;
U0DLM=(result >> 8)& 0xff;
U0LCR=0x03;
}

void uart0_tx(unsigned char data)
{
	U0THR=data;
	while(((U0LSR>>5)&1)==0);
}

void uart0_tx_string(char *ptr)
{
	while(*ptr!=0)
	{
		uart0_tx(*ptr);
		ptr++;
	}
}

#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)

unsigned char uart0_rx(void)
{
while(RDR == 0);
return U0RBR;
}

void uart0_rx_string(char *p,unsigned int max_size)
{
int i;
for(i=0;i<max_size;i++)
{
while(RDR==0)
p[i]=U0RBR;
if(p[i]=='\r')
break;
}
}

void uart0_tx_integer(int num)
{
char a[10];
int i;
if(num<0)
{
uart0_tx('-');
num=-num;
}
if(num==0)
{
uart0_tx('0');
return ;
}
for(i=0; num; num=num/10, i++)
a[i]=num%10+48;
for(--i; i>=0; i--)
uart0_tx(a[i]);
}

void uart0_tx_float(float f)
{
int num;
if(f<0)
{
uart0_tx('-');
f=-f;
}
if(f==0)
{
uart0_tx_string("0.0");
return;
}
num=f;
uart0_tx_integer(num);
uart0_tx('.');
num=(f-num)*1000000;
uart0_tx_integer(num);
}

