// Pico SDK libraries
#include "pico/stdlib.h"

#define LED_PIN 6
#define BLINK_DELAY_MS 500
#define BLINK_DELAY_MSM 1500


gpio_init(LED_PIN);
gpio_set_dir(LED_PIN, GPIO_OUT);


void pomlcka()
{
    gpio_put(LED_PIN, 1);
    sleep_ms(BLINK_DELAY_MSM);

    // Turn off the LED
    gpio_put(LED_PIN, 0);
    sleep_ms(BLINK_DELAY_MSM);
}

void tecka()
{
    gpio_put(LED_PIN, 1);
    sleep_ms(BLINK_DELAY_MS);

    // Turn off the LED
    gpio_put(LED_PIN, 0);
    sleep_ms(BLINK_DELAY_MS);
    
}

int main()
{
    
    }
  

