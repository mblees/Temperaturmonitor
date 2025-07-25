#include "main.h"

void network_keep_alive(void);
void setup_network(void);

void setup()
{
  setup_network();

  // --- Example code ---
  mqtt_subscribe("hardware/W5100S-Example/topic");

  led_init();
  led_fill_color(0, 120, 255);

  servo_init();

  init_timer(TIMER0, 10000);

  pinMode(26, INPUT);
  // --- Example code end ---
}

void loop()
{
  network_keep_alive();

  // --- Example code ---
  led_rainbow(1);

  static int direction = 0;
  static int count = 0;
  if (timer0_flag)
  {
    timer0_flag = false;
    count++;
    String message = "Timer 0 callback count: " + String(count);
    mqtt_publish("hardware/W5100S-Example/topic", message.c_str());
    direction = !direction;
  }

  if (direction)
    servo_rotate(0);
  else
    servo_rotate(180);
  // --- Example code end ---
}

/*
 * @brief Keeps MQTT, Ethernet and OTA alive
 */
void network_keep_alive()
{
#if ENABLE_ETHERNET && ENABLE_MQTT
  if (!is_mqtt_connected()) // losing MQTT connection means no Internet or MQTT server down
  {
    Serial.println("Ethernet disconnected -> Rebooting the board");
    rp2040.reboot(); // couldn't properly restart the ethernet connection, so reboot required
  }
  else
  {
    mqtt_loop();
#if ENABLE_OTA
    handle_ota();
#endif
  }
#endif
}

/*
 * @brief setup MQTT, Ethernet and OTA
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

#if ENABLE_ETHERNET
  const IPAddress static_ip(0, 0, 0, 0); // leave 0.0.0.0 for DHCP
  init_ethernet(static_ip);
  wait_for_ethernet(); // wait for Ethernet connection
#endif

#if ENABLE_MQTT
  mqtt_connect();  // connect to MQTT broker
  wait_for_mqtt(); // wait for MQTT connection
#endif

#if ENABLE_OTA
  init_ota(); // initialize OTA
#endif
}