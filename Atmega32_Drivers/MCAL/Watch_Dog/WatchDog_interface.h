/*
 * WatchDog_interface.h
 *
 * Created: 10/7/2023 3:32:07 PM
 *  Author: Ahmed saleh
 */ 


#ifndef WATCHDOG_INTERFACE_H_
#define WATCHDOG_INTERFACE_H_

#define WDTCR_REG   *((volatile u8*)0x41)

#define _16ms_ 0x00
#define _32ms_ 0x01
#define _65ms_ 0x02
#define _0_13s_ 0x03
#define _0_26s_ 0x04
#define _0_52s_ 0x05
#define _1s_	0x06
#define _2_2s_  0x07




void WDT_Enable(u8 Desired_time);
void WDT_Disable(void);

#endif /* WATCHDOG_INTERFACE_H_ */