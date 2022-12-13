/*
 * main.c
 *
 * Created: 12/12/2022 11:57:45 PM
 *  Author: dimat
 */ 

#include <xc.h>
#include <avr/cpufunc.h>

int main(void)
{
	volatile uint8_t flag;

	OSC.XOSCCTRL =	  OSC_FRQRANGE_12TO16_gc
					| 0 << OSC_X32KLPM_bp
					| 0 << OSC_XOSCPWR_bp
					| OSC_XOSCSEL_XTAL_1KCLK_gc;
					
	OSC.PLLCTRL =	  OSC_PLLSRC_XOSC_gc
					| OSC_PLLFAC1_bm
					| OSC_PLLFAC0_bm;
					
	OSC.CTRL =	  0 << OSC_RC2MEN_bp
				| 0 << OSC_RC32MEN_bp
				| 0 << OSC_RC32KEN_bp
				| 1 << OSC_XOSCEN_bp
				| 1 << OSC_PLLEN_bp;

	do{
		flag = OSC.CTRL & OSC_XOSCRDY_bm ;
	}
	while(flag == 0x00);
					
	ccp_write_io(&CLK.CTRL,CLK_SCLKSEL_XOSC_gc);
					
	flag = OSC.CTRL & OSC_XOSCRDY_bm ;					
					
    while(1)
    {
        //TODO:: Please write your application code 
    }
}