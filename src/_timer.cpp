#include "_timer.h"

bool ITimer0_callback(struct repeating_timer *t);
bool ITimer1_callback(struct repeating_timer *t);
bool ITimer2_callback(struct repeating_timer *t);
bool ITimer3_callback(struct repeating_timer *t);

RPI_PICO_Timer ITimer0(0);
RPI_PICO_Timer ITimer1(1);
RPI_PICO_Timer ITimer2(2);
RPI_PICO_Timer ITimer3(3);

volatile bool timer0_flag = false;
volatile bool timer1_flag = false;
volatile bool timer2_flag = false;
volatile bool timer3_flag = false;

/*
 * @brief initializes timer
 * @param timerNo timer number
 * @param interval_ms interval in milliseconds
 * @return true if successful, false if not
 */
bool init_timer(uint8_t timerNo, uint32_t interval_ms)
{
    switch (timerNo)
    {
    case 0:
        ITimer0.attachInterruptInterval(interval_ms * 1000, ITimer0_callback);
        break;
    case 1:
        ITimer1.attachInterruptInterval(interval_ms * 1000, ITimer1_callback);
        break;
    case 2:
        ITimer2.attachInterruptInterval(interval_ms * 1000, ITimer2_callback);
        break;
    case 3:
        ITimer3.attachInterruptInterval(interval_ms * 1000, ITimer3_callback);
        break;
    default:
        Serial.println("Invalid timer number");
        return false;
    }
    return true;
}

/*
* @brief Timer 0 callback function
* @param t timer object, automatically passed
*/
bool ITimer0_callback(struct repeating_timer *t)
{
    Serial.println("Timer 0 callback");
    timer0_flag = true;
    return true;
}

/*
* @brief Timer 1 callback function
* @param t timer object, automatically passed
*/
bool ITimer1_callback(struct repeating_timer *t)
{
    Serial.println("Timer 1 callback");
    timer1_flag = true;
    return true;
}

/*
* @brief Timer 2 callback function
* @param t timer object, automatically passed
*/
bool ITimer2_callback(struct repeating_timer *t)
{
    Serial.println("Timer 2 callback");
    timer2_flag = true;
    return true;
}

/*
* @brief Timer 3 callback function
* @param t timer object, automatically passed
*/
bool ITimer3_callback(struct repeating_timer *t)
{
    Serial.println("Timer 3 callback");
    timer3_flag = true;
    return true;
}