#include "_ethernet.h"

/**
 * @brief Initializes the Ethernet connection.
 */
void init_ethernet(const IPAddress static_ip)
{
    SPI.setRX(WIZNET_MISO);
    SPI.setCS(WIZNET_CS);
    SPI.setSCK(WIZNET_SCLK);
    SPI.setTX(WIZNET_MOSI);

    pinMode(WIZNET_RSTn, OUTPUT);
    digitalWrite(WIZNET_RSTn, LOW);
    delayMicroseconds(500);
    digitalWrite(WIZNET_RSTn, HIGH);
    delay(200);

    uint8_t mac_address[6];
    uint8_t uinque_id[8];
    get_unique_mac_adress(uinque_id, mac_address);
    eth.macAddress(mac_address);    
    if(static_ip[0] != 0){
        Serial.println("Using Static IP!");
        eth.config(static_ip);
    }
    // Start the Ethernet port
    Serial.println("Starting Ethernet...");
    eth.begin();
}

/**
 * @brief Checks if the Ethernet link is established.
 * @return 1 if the link is established, 0 otherwise.
 */
uint8_t check_for_ethernet_link()
{
    return eth.isLinked();
}

/**
 * @brief Checks if the Ethernet connection is established.
 * @return 1 if the connection is established, 0 otherwise.
 */
uint8_t check_for_ethernet_connection()
{
    if (eth.status() == WL_CONNECTED)
    {
        Serial.println("Ethernet Ready!");
        Serial.print("IP address: ");
        Serial.println(eth.localIP());
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Waiting for the ethernet connection to be established
 * @note This takes a long time (>2 min) if IP is static
 */
void wait_for_ethernet()
{
  while (!check_for_ethernet_link());
  while (!check_for_ethernet_connection());
}