#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define SENSOR 21

void app_main(void)
{
    gpio_reset_pin(SENSOR);
    gpio_set_direction(SENSOR, GPIO_MODE_INPUT);

    while (1)
    {
        int estado = gpio_get_level(SENSOR);

        printf("Sensor = %d\n", estado);

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
