#include <Arduino.h>
#include <FFat.h>
#include <Wire.h>
#include <BLEDevice.h>
#include <nvs_flash.h>

#include "config.h"
#include "M5GFX.h"
#include "M5Unified.h"
#include "lvgl.h"
#include "m5gfx_lvgl.h"
#include "esp_camera.h"

#include "App.h"

void setup() {
    // 初始化非易失性存储器
    esp_err_t ret = nvs_flash_init();
    // 如果没有空闲页或找到新版本，则擦除并重新初始化
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES ||
        ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }

    // 初始化USB串口
    USBSerial.begin(15200);
    // 初始化M5CoreS3
    M5.begin();

#if defined(M5CORES3)
    // 打印M5CoreS3用户演示版本
    USBSerial.printf("M5CoreS3 User Demo, Version: %s\r\n", DEMO_VERSION);
#elif defined(M5CORES3SE)
    // 打印M5CoreS3SE用户演示版本
    USBSerial.printf("M5CoreS3SE User Demo, Version: %s\r\n", DEMO_VERSION);
#endif

    // BM8563 Init (clear INT)
    M5.In_I2C.writeRegister8(0x51, 0x00, 0x00, 100000L);
    M5.In_I2C.writeRegister8(0x51, 0x01, 0x00, 100000L);
    M5.In_I2C.writeRegister8(0x51, 0x0D, 0x00, 100000L);

    // AW9523 Control BOOST
    M5.In_I2C.bitOn(AW9523_ADDR, 0x03, 0b10000000, 100000L);  // BOOST_EN

#if MONKEY_TEST_ENABLE
    M5.Speaker.setAllChannelVolume(0);
#endif
    M5.Display.setBrightness(60);

    lv_init();
    m5gfx_lvgl_init();

    App_Init();
}

void loop() {

    lv_timer_handler();
    delay(10);
}
