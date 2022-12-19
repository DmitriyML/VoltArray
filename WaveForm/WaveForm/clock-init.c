/*
 * clock_init.c
 *
 * Created: 12/19/2022 2:10:32 AM
 *  Author: dimat
 */ 

#include <avr/io.h>


void clock_init(void)
{	
	volatile uint8_t rg_ready ;
	
	/*	�������� XOSCCTRL � XOSC Control register	*/
	OSC.XOSCCTRL |= OSC_XOSCSEL_XTAL_1KCLK_gc ; /*	������� ����� 4-16��� , ������ ������������ 1K ������	*/
	OSC.XOSCCTRL |= 0 << OSC_X32KLPM_bp	; /* ��� � ���� ������ �� �������� */ 
	OSC.XOSCCTRL |= 0 << OSC_X32KLPM_bp ; /* ���������� 32��� �� ���������� */  
	OSC.XOSCCTRL |= OSC_FRQRANGE_12TO16_gc ; /* �������� ������ ������ : 12��� - 16��� */  
	
	/*	�������� PLLCTRL � PLL Control register	*/	
	OSC.PLLCTRL |= OSC_PLLFAC1_bm|OSC_PLLFAC0_bm ; /*	������� ��������� PLL ���������� �� 3*/
	OSC.PLLCTRL |= 0 << OSC_PLLDIV_bp ; /*	������� ��������� PLL �� ������� */
	OSC.PLLCTRL |= OSC_PLLSRC_XOSC_gc ; /*	�������� PLL - ������� ����� */ 
	
	rg_ready = 0x00;
	
	while(!((OSC.STATUS & OSC_PLLRDY_bm) == OSC_PLLRDY_bm)) ;
	
/*	do {
		rg_ready=OSC.STATUS;
	} while((rg_ready & OSC_PLLRDY_bm) == 0x00);
	
	do {
		rg_ready=OSC.STATUS;
	} while((rg_ready & OSC_XOSCRDY_bm) == 0x00);	*/
	
	/* CTRL � Oscillator Control register */
	OSC.CTRL |= OSC_PLLEN_bm ;
	OSC.CTRL |= OSC_XOSCEN_bm ;
	OSC.CTRL &= ~OSC_RC32KEN_bm ;
	OSC.CTRL &= ~OSC_RC32MEN_bm ;
	OSC.CTRL &= ~OSC_RC2MEN_bm;
	OSC.CTRL &= ~OSC_RC2MEN_bm;	
}

