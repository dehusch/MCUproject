#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define MOTOR_GPIO GPIO_NUM_5

void app_main(void)
{
    gpio_reset_pin(MOTOR_GPIO);
    gpio_set_direction(MOTOR_GPIO, GPIO_MODE_OUTPUT);

    while (1) {

        // Motor desligado por 2 segundos
        gpio_set_level(MOTOR_GPIO, 0);
        printf("Motor desligado\n");
        vTaskDelay(pdMS_TO_TICKS(2000));

        // Motor ligado por 5 segundos
        gpio_set_level(MOTOR_GPIO, 1);
        printf("Motor ligado\n");
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
