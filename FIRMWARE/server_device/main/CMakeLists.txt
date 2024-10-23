set(srcs    "app_main.c"
            "interface/board.c"
            "protocol/ble_server.c"
            "sensor_lipo/data.c")

idf_component_register(SRCS "${srcs}"
                    INCLUDE_DIRS ".")
