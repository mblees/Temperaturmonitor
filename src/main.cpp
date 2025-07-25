#include "main.h"

void setup_network(void);

BME280Sensor bme;

static bool once = true;

void setup()
{
  Serial.begin(SERIAL_BAUDRATE); // Start the serial connection, default 115200
#if WAIT_FOR_SERIAL
  while (!Serial)
    ; // Waiting for Serial when WAIT_FOR_SERIAL = 1
#endif
  Serial.println("Serial connected");
  setup_network();
  init_timer(TIMER0, 3000);
  bme.begin(BME280_ADRS);
}

void loop()
{
  if (timer0_flag)
  {
    if (once)
    {
      Serial.println("Temperature,Humidity,Pressure");
      once = false;
    }
    timer0_flag = false; // Reset the timer flag

    float temp = bme.getTemperature();
    float hum = bme.getHumidity();
    float pres = bme.getPressure() / 1000.0; // Convert to kPa

    Serial.print(temp);
    Serial.print(",");
    Serial.print(hum);
    Serial.print(",");
    Serial.println(pres);
  }
}

/*
 * @brief setup WiFi and Serial connection
 */
void setup_network()
{
#if ENABLE_WIFI
  init_wifi();    // Initialize WiFi
  connect_wifi(); // Connect to WiFi
#endif
}