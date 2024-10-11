#include <stdio.h>
#include "ble.h"
#include "board.h"
#include "esp_log.h"

void app_main(void)
{
    esp_err_t err = ESP_OK;

    ESP_LOGI(TAG, "Initializing...");

    TimerHandle_t Timer = xTimerCreate(
        "datarecieved",
        pdMS_TO_TICKS(2000),
        pdTRUE,
        (void *)0,
        ble
    );

    err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK(err);


    err = bluetooth_init();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "esp32_bluetooth_init failed (err %d)", err);
        return;
    }

    ble_mesh_get_dev_uuid(dev_uuid);

    /* Initialize the Bluetooth Mesh Subsystem */
    err = ble_mesh_init();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Bluetooth mesh init failed (err %d)", err);
    }
}