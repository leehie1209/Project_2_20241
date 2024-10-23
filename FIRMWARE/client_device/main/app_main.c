#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/queue.h"
#include "freertos/ringbuf.h"
#include "freertos/semphr.h"

#include "esp_log.h"
#include "nvs_flash.h"

#include "interface/board.h"
#include "protocol/ble.h"

static const char *TAG = "Cleint";

void app_main (void){
    esp_err_t err = ESP_OK;
    ESP_LOGI(TAG, "Initializing ... ...");

        err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }

    ESP_ERROR_CHECK(err);

    board_init();

    err = bluetooth_init();
    
    err = ble_mesh_init();
    ESP_LOGI(TAG, "DITME DE VAI LON ");
    
}