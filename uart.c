#include "gpio.h"

/* Auxilary mini UART registers */
#define AUX_ENABLE      (volatile unsigned int*)(MMIO_BASE+0x00215004))
#define AUX_MU_IO       (volatile unsigned int*)(MMIO_BASE+0x00215040))
#define AUX_MU_IER      ((volatile unsigned int*)(MMIO_BASE+0x00215044))
#define AUX_MU_IIR      ((volatile unsigned int*)(MMIO_BASE+0x00215048))
#define AUX_MU_LCR      ((volatile unsigned int*)(MMIO_BASE+0x0021504C))
#define AUX_MU_MCR      ((volatile unsigned int*)(MMIO_BASE+0x00215050))
#define AUX_MU_LSR      ((volatile unsigned int*)(MMIO_BASE+0x00215054))
#define AUX_MU_MSR      ((volatile unsigned int*)(MMIO_BASE+0x00215058))
#define AUX_MU_SCRATCH  ((volatile unsigned int*)(MMIO_BASE+0x0021505C))
#define AUX_MU_CNTL     ((volatile unsigned int*)(MMIO_BASE+0x00215060))
#define AUX_MU_STAT     ((volatile unsigned int*)(MMIO_BASE+0x00215064))
#define AUX_MU_BAUD     ((volatile unsigned int*)(MMIO_BASE+0x00215068))

void uart_init(void)
{

	register unsigned int r;
	/* initialize UART */
	*AUX_ENABLE |=1; // enable UART1, AUX mini uart
	*AUX_MU_CNTL =0;
	*AUX_MU_LCR=3; //UART works in 8-bit mode
	*AUX_MU_MCR=0;
	*AUX_MU_IER=0;
	*AUX_MU_IIR=0xc6;//Disable interrupts
	*AUX_MU_BAUD=270; //115200 baud
	/* map UART1 to GPIO pins */
	r=*GPFSEL1;
	r&=~((7<<12)|(7<<15));
	r|=(2<<12)|(2<<15); //alternate function 5,pg102
	*GPFSEL1=r;
	*GPPUD=0; //Disable pull-up/down
	r=150;
	while(r--){asm volatile("nop");}//Wait 150 cycles
	*GPPUDCLK0 =0;
	while(r--){asm volatile("nop");}//Wait 150 cycles
	*AUX_MU_CNTL =3; //Enable Mini UART Transmitter + Reciever
}

/* Send a character */

void uart_send(unsigned int c) {

	/* wait untill we can send */
	do(asm volatile("nop");}while(!(*AUX_MU_LSR&0x20));
	/* Write char to the buffer */
	*AUX_MU_IO=c;
}

/* Recieve a character */

void uart_getc(){
	char r;
	do(asm volatile("nop");}while(!(*AUX_MU_LSR&0x01));
	r=(char)(*AUX_MU_IO);
	return r=='\r'?'\n':r;
}

/* Display a string */

void uart_puts(char *s){
	while(*s){
		if(*s=='\n'){
			uart_send('\r');
		}
		uart_send(*s++);
	}
}


