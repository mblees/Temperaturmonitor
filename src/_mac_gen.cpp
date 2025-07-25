#include "_mac_gen.h"

/**
 * @brief Retrieves the unique ID of the controller used by the MAC address.
 * @param id Pointer to the array to store the unique ID.
 */
void get_unique_id(uint8_t* id){
    flash_get_unique_id(id);
}

/**
 * @brief Generates a unique MAC address based on the unique ID.
 * @param id Pointer to the unique ID.
 * @param mac_adress Pointer to the array to store the MAC address.
 */
void get_unique_mac_adress(uint8_t* id, byte* mac_adress){
    get_unique_id(id);
    mac_adress[0] = 0xDE;
    mac_adress[1] = 0x04;
    mac_adress[2] = 0x25;
    mac_adress[3] = id[5];
    mac_adress[4] = id[6];
    mac_adress[5] = id[7];
    Serial.print("MAC address: ");
    for (int i = 0; i < 6; i++)
    {
        Serial.print(mac_adress[i], HEX);
        if (i < 5)
        {
            Serial.print(":");
        }
    }
    Serial.println();
}