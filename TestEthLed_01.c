#include <stdio.h>
#include <stdlib.h>

#include <esp_mac.h>
#include "driver/gpio.h"

#include "freertos/FreeRTOS.h"

#define ETH_RXD0 GPIO_NUM_25
#define ETH_RXD1 GPIO_NUM_26
#define ETH_TXD1 GPIO_NUM_22
#define ETH_TXEN GPIO_NUM_21
#define ETH_TXD0 GPIO_NUM_19
// #define ETH_CLK GPIO_NUM_0
// #define ETH_MDC GPIO_NUM_23
// #define ETH_MDIO GPIO_NUM_18

void app_main(void)
{
  gpio_config_t eth_out_config;
  eth_out_config.intr_type = GPIO_INTR_DISABLE;
  eth_out_config.mode = GPIO_MODE_OUTPUT;
  eth_out_config.pin_bit_mask = (1ULL << ETH_RXD0) | (1ULL << ETH_RXD1);
  eth_out_config.pull_up_en = GPIO_PULLUP_DISABLE;
  eth_out_config.pull_down_en = GPIO_PULLDOWN_ENABLE;
  gpio_config(&eth_out_config);

  gpio_config_t eth_in_config;
  eth_in_config.intr_type = GPIO_INTR_DISABLE;
  eth_in_config.mode = GPIO_MODE_INPUT;
  eth_in_config.pin_bit_mask = (1ULL << ETH_TXD0) | (1ULL << ETH_TXD1) | (1ULL << ETH_TXEN);
  eth_in_config.pull_up_en = GPIO_PULLUP_DISABLE;
  eth_in_config.pull_down_en = GPIO_PULLDOWN_ENABLE;
  gpio_config(&eth_in_config);

  gpio_set_level(ETH_TXEN, 1);
  gpio_set_level(ETH_RXD0, 1);
  gpio_set_level(ETH_RXD1, 1);

  while (1)
  {
    gpio_set_level(ETH_TXD0, 1);
    gpio_set_level(ETH_TXD1, 1);

    vTaskDelay(pdMS_TO_TICKS(1000));

    gpio_set_level(ETH_TXD0, 0);
    gpio_set_level(ETH_TXD1, 0);

    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
