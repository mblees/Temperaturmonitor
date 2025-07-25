#include "main.h"

void setup_network(void);

void setup()
{
  setup_network();
  init_timer(TIMER0, 10000);
}

void loop()
{
  if (timer0_flag)
  {
    Serial.println("Timer 0 triggered");
  }
}

/*
 * @brief setup WiFi and Serial connection
 */
void setup_network()
{
  Serial.begin(SERIAL_BAUDRATE); // Start the serial connection, default 115200
#if WAIT_FOR_SERIAL
  while (!Serial)
    ; // Waiting for Serial when WAIT_FOR_SERIAL = 1
#endif
  Serial.println("Serial connected");

#if ENABLE_WIFI
  init_wifi(); // Initialize WiFi
  connect_wifi(); // Connect to WiFi
#endif
}