#include "_mqtt.h"

/**
 * @brief Callback function for incoming MQTT messages.
 * @param topic Topic of the received message.
 * @param payload Payload of the message.
 * @param length Length of the payload.
 */
void mqtt_callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.println("] ");
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println();
    Serial.println("You can add your own code here to handle the incoming message.");
    return;
}

/**
 * @brief Connects to the MQTT broker.
 * @note May require multiple attempts and can take over a minute. Initializes the server and callback only once.
 */
void mqtt_connect()
{
    static uint8_t do_once = 0;
    if (!do_once) {
        do_once = 1;
        client.setServer(mqtt_server, 1883);
        client.setCallback(mqtt_callback);
    }
    String unique_id = rp2040.getChipID();
    String unique_mqtt_name = String(mqtt_client_name) + String("-") + String(unique_id);
    Serial.println("Connecting to MQTT broker using the Name: " + unique_mqtt_name);
    client.connect(unique_mqtt_name.c_str());
}

/**
 * @brief Publishes a message to a specified MQTT topic.
 * @param message The message to be published as a constant character string.
 */
void mqtt_publish(const char *topic, const char *message)
{
    if (client.connected())
    {
        client.publish(topic, message);
    }
}

/**
 * @brief Subscribes to a specified MQTT topic.
 * @param topic The topic to subscribe to.
 */
void mqtt_subscribe(const char *topic)
{
    if (client.connected())
    {
        client.subscribe(topic);
    }
}

/**
 * @brief Keeps MQTT functionality alive by maintaining the connection loop.
 */
void mqtt_loop()
{
    client.loop();
}

/**
 * @brief Checks if the connection to the MQTT broker is established.
 * @return 1 if connected, 0 otherwise.
 */
uint8_t is_mqtt_connected()
{
    return client.connected();
}

/**
 * @brief Waits until the MQTT connection is established.
 * @note Reconnects every 5 seconds if the connection is not established. Necessary due to static IP usage.
 */
void wait_for_mqtt()
{
    uint32_t start_time = millis();
    while (!is_mqtt_connected())
    {
        if (millis() - start_time > 5000) // Attempt to reconnect every 5 seconds
        {
            Serial.println("Retrying to connect to MQTT");
            mqtt_connect(); // The internal PubSubClient function is blocking 
            start_time = millis();
        }
    }
}
