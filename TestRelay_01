#include <stdio.h>
#include <stdlib.h>

#include <esp_mac.h>
#include "driver/gpio.h"

#include "freertos/FreeRTOS.h"

#define RELAY1_PIN GPIO_NUM_13
#define RELAY2_PIN GPIO_NUM_2
#define RELAY3_PIN GPIO_NUM_12

void app_main(void)
{
  gpio_config_t relay_config;
  relay_config.intr_type = GPIO_INTR_DISABLE;                                                       // Habilita interrupção na queda
  relay_config.mode = GPIO_MODE_OUTPUT;                                                             // Configura o pino como saída
  relay_config.pin_bit_mask = (1ULL << RELAY1_PIN) && (1ULL << RELAY2_PIN) && (1ULL << RELAY3_PIN); // Seleciona o pino GPIO
  relay_config.pull_up_en = GPIO_PULLUP_DISABLE;                                                    // Desabilita pull up
  relay_config.pull_down_en = GPIO_PULLDOWN_DISABLE;                                                // Desabilita pull down
  gpio_config(&relay_config);

  while (1)
  {
    gpio_set_level(RELAY1_PIN, 0);
    gpio_set_level(RELAY2_PIN, 0);
    gpio_set_level(RELAY3_PIN, 0);

    vTaskDelay(pdMS_TO_TICKS(1000));

    gpio_set_level(RELAY1_PIN, 1);
    gpio_set_level(RELAY2_PIN, 1);
    gpio_set_level(RELAY3_PIN, 1);

    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
