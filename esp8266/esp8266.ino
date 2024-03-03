/**
 * @file esp8266.ino
 * @brief Arduino code for communication with the WIFi module.
 * @author Samreen Ansari
 *
 * This code initializes a I2C Communication between the Arduino and the
 * ESP8266. The ESP8266 sends data to the Arduino and requests data from the
 * Arduino.
 */

#include "src/primary/Primary.h"

Primary primaryDevice;

const int LED_PIN = LED_BUILTIN;

/**
 * @brief Initializes the ESP8266 primary WiFi module.
 *
 * This function initializes the I2C communication with the secondary device.
 */
void setup() {
  Serial.begin(115200);
  primaryDevice.initialize_i2c();
}

/**
 * @brief The main loop of the ESP8266 primary WiFi module.
 *
 * This function is called repeatedly send data to the secondary device,
 * and request data from the device.
 */
void loop() {
  primaryDevice.request_data_from_secondary();
  delay(1000);
  primaryDevice.send_data_to_secondary("from primary to secondary!");
  delay(1000);
}
