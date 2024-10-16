#include <stdio.h>
#include <stdlib.h>

#include <esp_mac.h>
#include "driver/gpio.h"

#include "freertos/FreeRTOS.h"

#define LED1_PIN GPIO_NUM_32
#define LED2_PIN GPIO_NUM_33

void app_main(void)
{
  gpio_config_t led_conf;
  led_conf.intr_type = GPIO_INTR_DISABLE;
  led_conf.mode = GPIO_MODE_OUTPUT;
  led_conf.pin_bit_mask = (1ULL << LED1_PIN) | (1ULL << LED2_PIN);
  led_conf.pull_up_en = GPIO_PULLUP_DISABLE;
  led_conf.pull_down_en = GPIO_PULLDOWN_ENABLE;
  gpio_config(&led_conf);

  while (1)
  {
    gpio_set_level(LED1_PIN, 0);
    gpio_set_level(LED2_PIN, 0);

    vTaskDelay(pdMS_TO_TICKS(1000));

    gpio_set_level(LED1_PIN, 1);
    gpio_set_level(LED2_PIN, 1);

    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
