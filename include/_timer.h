#ifndef _TIMER_H
#define _TIMER_H

#include <Arduino.h>
#include "config.h"

#include <RPi_Pico_TimerInterrupt.h>

extern volatile bool timer0_flag;
extern volatile bool timer1_flag;
extern volatile bool timer2_flag;
extern volatile bool timer3_flag;

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
#define TIMER3 3

bool init_timer(uint8_t timerNo, uint32_t interval_ms);

#endif // _TIMER_H
