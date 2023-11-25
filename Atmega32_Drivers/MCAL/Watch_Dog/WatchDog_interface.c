/*
 * WatchDog_interface.c
 *
 * Created: 10/7/2023 3:32:28 PM
 *  Author: Ahmed saleh
 */ 

#include "../../LIB/BITMATH.h"
#include "../../LIB/STD_Type.h"
#include "WatchDog_interface.h"

void WDT_Enable(u8 Desired_time)
{
	
	WDTCR_REG=0b11111000;
	WDTCR_REG|=Desired_time;
	SET_BIT(WDTCR_REG,3);	
	
}

void WDT_Disable(void)
{
	
	WDTCR_REG |= (1<<3) | (1<<4);
	WDTCR_REG=0x00;
	
	
}