cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(ncs-i2c-sb1602b)

target_sources(app PRIVATE
    src/main.c
    src/drivers/led.c
    src/drivers/sb1602b.c
)
