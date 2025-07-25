#include "__led_example.h"

uint32_t Wheel(byte WheelPos);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_AMOUNT, LED_DATA_PIN, NEO_GRB + NEO_KHZ800);
static uint32_t colors[LED_AMOUNT];

/**
 * @brief Initializes the LED strip.
 */
void led_init()
{
    strip.begin();
    strip.setBrightness(LED_BRIGHTNESS);
    strip.show();
}

/**
 * @brief Makes all the LEDs light up in a single color. Does not overwrite the colors array.
 * @param color obtained by strip.Color(r, g, b) or use led_fill_color(r, g, b)
 */
void led_fill_color(uint32_t color)
{
    for (int i = 0; i < strip.numPixels(); i++)
    {
        strip.setPixelColor(i, color);
    }
    strip.show();
}

/**
 * @brief Makes all the LEDs light up in a single color. Does not overwrite the colors array.
 * @param r red value
 * @param g green value
 * @param b blue value
 */
void led_fill_color(uint8_t r, uint8_t g, uint8_t b)
{
    led_fill_color(strip.Color(r, g, b));
}

/**
 * @brief Makes all the LEDs turn off. Does not overwrite the colors array.
 */
void led_clear()
{
    led_fill_color(strip.Color(0, 0, 0));
}

/**
 * @brief Makes the LEDs light up in the colors stored in the colors array.
 */
void led_show_stored()
{
    for (int i = 0; i < strip.numPixels(); i++)
    {
        strip.setPixelColor(i, colors[i]);
    }
    strip.show();
}

/**
 * @brief Sets the color of a single LED. led_show() must be called to update the LEDs.
 * @param index the index of the LED
 * @param color obtained by strip.Color(r, g, b) or use led_fill_color(r, g, b)
 */
void led_set_color(int index, uint32_t color)
{
    colors[index] = color;
}

/**
 * @brief Sets the color of a single LED. led_show() must be called to update the LEDs.
 * @param index the index of the LED
 * @param r red value
 * @param g green value
 * @param b blue value
 */
void led_set_color(int index, uint8_t r, uint8_t g, uint8_t b)
{
    led_set_color(index, strip.Color(r, g, b));
}

/**
 * @brief Makes the LEDs light up in a rainbow pattern. Call in loop with delay, increments automatically.
 */
void led_rainbow()
{
    static uint8_t offset = 0;
    for (int i = 0; i < strip.numPixels(); i++)
    {
        strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + offset) & 255)); // rainbow
    }
    strip.show();
    offset++;
}

/**
 * @brief Shows a rainbow pattern for a specified duration.
 * @param duration duration in seconds
 */
void led_rainbow(uint16_t duration)
{
    uint32_t start = millis();
    while (millis() - start < duration * 1000)
    {
        led_rainbow();
        delay(20);
    }
}

/**
 * @brief Generates a rainbow color based on a position in the color wheel.
 * @param WheelPos Position on the color wheel (0-255).
 * @return RGB color as a 32-bit unsigned integer.
 */
uint32_t Wheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85)
    {
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if (WheelPos < 170)
    {
        WheelPos -= 85;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}