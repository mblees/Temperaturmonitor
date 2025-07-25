#include "__servo_example.h"

Servo servo;

/*
* @brief initializes Servo motor
*/
void servo_init(void)
{
    // attach servo to pin 9
    servo.attach(SERVO_DATA_PIN);
}

/*
* @brief rotates Servo motor to a specific angle, needs to be called in loop.
* @param angle: angle to rotate to
*/
void servo_rotate(int angle)
{
    // rotate servo to angle
    servo.write(angle);
}
