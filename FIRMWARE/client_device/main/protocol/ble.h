#ifndef _BLE_H_
#define _BLE_H_

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


#define CID_ESP             0x02E5

#define PROV_OWN_ADDR       0x0001

#define MSG_SEND_TTL        3
#define MSG_SEND_REL        false
#define MSG_TIMEOUT         0
#define MSG_ROLE            ROLE_PROVISIONER

#define COMP_DATA_PAGE_0    0x00

#define APP_KEY_IDX         0x0000
#define APP_KEY_OCTET       0x12

#define COMP_DATA_1_OCTET(msg, offset)      (msg[offset])
#define COMP_DATA_2_OCTET(msg, offset)      (msg[offset + 1] << 8 | msg[offset])

void ble_mesh_get_dev_uuid(uint8_t *dev_uuid);
esp_err_t ble_mesh_init(void);
esp_err_t bluetooth_init(void);

#endif