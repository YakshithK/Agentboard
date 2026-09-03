#pragma once

// ==============================
// I2C
// ==============================

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7

// ==============================
// OLED
// ==============================

#define OLED_IC OLED_IC_SSD1306
#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_DISPLAY_128X32

// ==============================
// Encoder
// ==============================

#define ENCODER_RESOLUTION 4

// ==============================
// RP2040 bootloader
// ==============================

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

// ==============================
// OLED power / refresh
// ==============================

#define OLED_TIMEOUT 30000
#define OLED_UPDATE_INTERVAL 100