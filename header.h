#include<lpc21xx.h>
extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);

extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern void uart0_tx_string(char *ptr);
extern unsigned char uart0_rx(void);
extern void uart0_rx_string(char *p,unsigned int max_size);
extern void uart0_tx_integer(int num);
extern void uart0_tx_float(float f);

extern unsigned char adc_read(unsigned char ch_num);
extern void adc_init(void);
//extern unsigned int adc_val;

extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_string(char *ptr);

extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);

extern float temperature(void);

