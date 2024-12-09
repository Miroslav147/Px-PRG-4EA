#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include <stdio.h>

int main() {
    stdio_init_all();
    sleep_ms(2000);
    printf("Starting...\n");

    const uint LED_PIN = 15;
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);

    uint slice_num = pwm_gpio_to_slice_num(LED_PIN);
    pwm_config config = pwm_get_default_config();

    pwm_config_set_clkdiv(&config, 64.0f);
    pwm_config_set_wrap(&config, 65535);

    pwm_init(slice_num, &config, true);

    int32_t duty_cycle = 0;
    int32_t step = 256; // Krok změny jasu

    while (true) {
        pwm_set_gpio_level(LED_PIN, duty_cycle);

        duty_cycle += step;

        if (duty_cycle >= 65535 || duty_cycle <= 0) {
            step = -step; // Otočení směru
        }

        sleep_ms(10); // Rychlost změny
    }

    return 0;
}
