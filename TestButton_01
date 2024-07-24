#include <stdio.h>
#include <stdlib.h>

#include <esp_mac.h>
#include "driver/gpio.h"

#include "freertos/FreeRTOS.h"

#define BTN1_PIN GPIO_NUM_14

void app_main(void)
{

  gpio_config_t btn_config;
  btn_config.intr_type = GPIO_INTR_DISABLE;        // Habilita interrupção na queda
  btn_config.mode = GPIO_MODE_INPUT;               // Configura o pino como saída
  btn_config.pin_bit_mask = (1ULL << BTN1_PIN);    // Seleciona o pino GPIO
  btn_config.pull_up_en = GPIO_PULLUP_ENABLE;      // Habilita pull up
  btn_config.pull_down_en = GPIO_PULLDOWN_DISABLE; // Desabilita pull down
  gpio_config(&btn_config);

  while (1)
  {
    if (gpio_get_level(BTN1_PIN) == 0)
    {
      printf("Botão 1 está funcionando \n");
    }
    else
    {
      printf("Botão inoperante \n");
    }
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}
