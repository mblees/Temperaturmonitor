#ifndef SERVO_EXAMPLE_H
#define SERVO_EXAMPLE_H

#include <Arduino.h>
#include "config.h"

#include <Servo.h>

void servo_init(void);
void servo_rotate(int angle);

#endif // SERVO_EXAMPLE_H
