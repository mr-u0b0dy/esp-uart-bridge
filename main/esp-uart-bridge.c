#include <stdio.h>
#include <string.h>

#include "driver/gpio.h"
#include "driver/uart.h"
#include "esp_console.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"

#define UART_TXD (CONFIG_UART_TXD)
#define UART_RXD (CONFIG_UART_RXD)
#define UART_RTS (UART_PIN_NO_CHANGE)
#define UART_CTS (UART_PIN_NO_CHANGE)

#define UART_PORT_NUM (CONFIG_UART_PORT_NUM)
#define UART_BAUD_RATE (CONFIG_UART_BAUD_RATE)
#define UART_BRIDGE_TASK_STACK_SIZE (CONFIG_UART_BRIDGE_TASK_STACK_SIZE)
#define UART_BUF_SIZE 1024 * 2

static const char *TAG = "UART_BRIDGE";

// Function to forward data between two UARTs
void uart_bridge_task(void *arg) {
  uart_config_t uart_config = {
      .baud_rate = UART_BAUD_RATE,
      .data_bits = UART_DATA_8_BITS,
      .parity = UART_PARITY_DISABLE,
      .stop_bits = UART_STOP_BITS_1,
      .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
      .source_clk = UART_SCLK_DEFAULT,
  };

  ESP_ERROR_CHECK(uart_driver_install(UART_PORT_NUM, UART_BUF_SIZE,
                                      UART_BUF_SIZE, 0, NULL, 0));
  ESP_ERROR_CHECK(uart_param_config(UART_PORT_NUM, &uart_config));
  ESP_ERROR_CHECK(
      uart_set_pin(UART_PORT_NUM, UART_TXD, UART_RXD, UART_RTS, UART_CTS));

  // Configure a temporary buffer for the incoming data
  uint8_t *data = (uint8_t *)malloc(UART_BUF_SIZE);
  if (!data) {
    ESP_LOGE(TAG, "Failed to allocate memory for buffer");
    vTaskDelete(NULL);
  }

  while (1) {
    // Read input from the console
    printf("Enter command: ");
    fflush(stdout);  // Ensure output is flushed

    char input_line[UART_BUF_SIZE];
    if (fgets(input_line, sizeof(input_line), stdin) != NULL) {
      // Write input from the console to the UART port
      uart_write_bytes(UART_PORT_NUM, input_line, strlen(input_line));
      ESP_LOGI(TAG, "Sent to UART: %s", input_line);
    }

    // Read response from UART
    int len =
        uart_read_bytes(UART_PORT_NUM, data, sizeof(data), pdMS_TO_TICKS(100));
    if (len > 0) {
      // Null-terminate and print data received from UART to the console
      data[len] = '\0';
      printf("Received from UART: %s\n", (char *)data);
    }

    vTaskDelay(pdMS_TO_TICKS(10));  // Avoid starving other tasks
  }
}

void app_main(void) {
  xTaskCreate(uart_bridge_task, "uart_bridge_task", UART_BRIDGE_TASK_STACK_SIZE,
              NULL, 10, NULL);  // Create UART bridge task
}

