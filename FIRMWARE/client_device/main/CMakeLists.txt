set(srcs "app_main.c"
         "interface/board.c"
         "protocol/ble.c")

idf_component_register(SRCS "${srcs}"
                    INCLUDE_DIRS  ".")
