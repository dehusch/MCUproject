#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <stdio.h>

#define LED 2

void app_main(void)
{
    gpio_reset_pin(LED);
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);

    while (1)
    {
        gpio_set_level(LED, 1);
        printf("HIGH\n");
        vTaskDelay(pdMS_TO_TICKS(500));

        gpio_set_level(LED, 0);
        printf("LOW\n");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
