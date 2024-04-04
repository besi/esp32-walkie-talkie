#include <freertos/FreeRTOS.h>
#include <driver/i2s.h>

// WiFi credentials
// wifi.h must include the following two lines:
// 
//     #define WIFI_SSID "whatever"
//     #define WIFI_PSWD "secret"
#include "wifi_config.h"


// sample rate for the system
#define SAMPLE_RATE 16000

// are you using an I2S microphone - comment this out if you want to use an analog mic and ADC input
#define USE_I2S_MIC_INPUT

// I2S Microphone Settings

// Which channel is the I2S microphone on? I2S_CHANNEL_FMT_ONLY_LEFT or I2S_CHANNEL_FMT_ONLY_RIGHT
// Generally they will default to LEFT - but you may need to attach the L/R pin to GND
#define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_LEFT
// #define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_RIGHT
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_18
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_23
#define I2S_MIC_SERIAL_DATA GPIO_NUM_13

// Analog Microphone Settings - ADC1_CHANNEL_7 is GPIO35
#define ADC_MIC_CHANNEL ADC1_CHANNEL_7

// speaker settings
#define USE_I2S_SPEAKER_OUTPUT
#define I2S_SPEAKER_SERIAL_CLOCK GPIO_NUM_18
#define I2S_SPEAKER_LEFT_RIGHT_CLOCK GPIO_NUM_23
#define I2S_SPEAKER_SERIAL_DATA GPIO_NUM_5
// Shutdown line if you have this wired up or -1 if you don't
#define I2S_SPEAKER_SD_PIN -1

// transmit button
#define GPIO_TRANSMIT_BUTTON 22

// Which transport do you want to use? ESP_NOW or UDP?
// comment out this line to use UDP
#define USE_ESP_NOW

// i2s config for using the internal ADC
extern i2s_config_t i2s_adc_config;
// i2s config for reading from of I2S
extern i2s_config_t i2s_mic_Config;
// i2s microphone pins
extern i2s_pin_config_t i2s_mic_pins;
// i2s speaker pins
extern i2s_pin_config_t i2s_speaker_pins;