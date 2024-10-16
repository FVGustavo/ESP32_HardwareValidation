#include <stdio.h>
#include <stdlib.h>

#include <esp_mac.h>
#include "driver/gpio.h"

#include "freertos/FreeRTOS.h"

#define RELAY1_PIN GPIO_NUM_13
#define RELAY2_PIN GPIO_NUM_2
#define RELAY3_PIN GPIO_NUM_12
#define BTN1_PIN GPIO_NUM_14

void app_main(void)
{
  gpio_config_t relay_config;
  relay_config.intr_type = GPIO_INTR_DISABLE;                                                       // Desabilita interrupção
  relay_config.mode = GPIO_MODE_OUTPUT;                                                             // Configura o pino como saída
  relay_config.pin_bit_mask = (1ULL << RELAY1_PIN) && (1ULL << RELAY2_PIN) && (1ULL << RELAY3_PIN); // Seleciona o pino GPIO
  relay_config.pull_up_en = GPIO_PULLUP_DISABLE;                                                    // Desabilita pull up
  relay_config.pull_down_en = GPIO_PULLDOWN_DISABLE;                                                // Desabilita pull down
  gpio_config(&relay_config);

  gpio_config_t btn_config;
  btn_config.intr_type = GPIO_INTR_NEGEDGE;        // Habilita interrupção na queda
  btn_config.mode = GPIO_MODE_INPUT;               // Configura o pino como saída
  btn_config.pin_bit_mask = (1ULL << BTN1_PIN);    // Seleciona o pino GPIO
  btn_config.pull_up_en = GPIO_PULLUP_ENABLE;      // Habilita pull up
  btn_config.pull_down_en = GPIO_PULLDOWN_DISABLE; // Desabilita pull down
  gpio_config(&btn_config);

  while (1)
  {
    if (gpio_get_level(BTN1_PIN) == 0)
    {
      gpio_set_level(RELAY1_PIN, 1);
      gpio_set_level(RELAY2_PIN, 1);
      gpio_set_level(RELAY3_PIN, 1);
    }
    if (gpio_get_level(BTN1_PIN) == 1)
    {
      gpio_set_level(RELAY1_PIN, 0);
      gpio_set_level(RELAY2_PIN, 0);
      gpio_set_level(RELAY3_PIN, 0);
    }
    if (gpio_get_level(RELAY1_PIN) == 1 && gpio_get_level(RELAY2_PIN) == 1 && gpio_get_level(RELAY3_PIN) == 1)
    {
      printf("Relés funcionando \n");
    }
    else
    {
      printf("Relés inoperantes \n");
    }

    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
