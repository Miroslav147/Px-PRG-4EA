// Pico SDK libraries
#include "pico/stdlib.h"
#include "pico/time.h"

// Standard libraries
#include <stdio.h>
#include <stdbool.h>

#define LED_PIN 6
#define TLACITKO 21
#define BUTTON_PIN 20

void handler(uint gpio, uint32_t events);
uint32_t millis();

uint32_t lastIrgTime = 0;

int main()
{
    int konstanta = 0;
    // Initialize all standard I/O
    stdio_init_all();
    // Wait for serial monitor to reconnect
    sleep_ms(2000);
    printf("Starting...\n");

    // Initialize GPIO pins
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    gpio_init(BUTTON_PIN);
    gpio_pull_up(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);

    gpio_init(TLACITKO);
    gpio_pull_up(TLACITKO);
    gpio_set_dir(TLACITKO, GPIO_IN);

    // Enable interrupts for button pin
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_RISE, true, &handler);
    gpio_set_irq_enabled_with_callback(TLACITKO, GPIO_IRQ_EDGE_RISE, true, &handler);

    // Infinite loop
    /*while (1)
    {
        printf("Run...\n");
        sleep_ms(1000);
    }*/
    printf("%d", konstanta);
    if (gpio_get(BUTTON_PIN) == 1) {
        konstanta -= 1;
        printf("%d", konstanta);
    }

    else if (gpio_get(TLACITKO) == 1) {
        konstanta += 1;
        printf("%d", konstanta);
    return 0;
}
}

void handler(uint gpio, uint32_t events)
{
  if ((millis() - lastIrgTime) >= 200) {
        gpio_put(LED_PIN, !gpio_get(LED_PIN));
        lastIrgTime = millis();  
}
}
uint32_t millis() {
    return to_ms_since_boot(get_absolute_time());
}