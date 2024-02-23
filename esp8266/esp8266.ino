/**
 * @file esp8266.ino
 * @brief Arduino code for communication with the WIFi module.
 *
 * This code initializes a WiFi module and handles requests using the WifiServer
 * class. It connects to a WiFi network, turns on an LED, and continuously
 * handles requests in the loop.
 */
#include "src/primary/Primary.h"
// #include "src/wifi-server/WifiServer.h"

Primary primaryDevice;

const int LED_PIN = LED_BUILTIN;

// WifiServer wifiServer(LED_PIN);

/**
 * @brief Initializes the ESP8266 primary WiFi module.
 *
 * This function starts the HTTP server and initializes the I2C
 * communication with the secondary device.
 */
void setup() {
  Serial.begin(115200);
  // wifiServer.connect();
  primaryDevice.initialize_i2c();
}

/**
 * @brief The main loop of the ESP8266 primary WiFi module.
 *
 * This function is called repeatedly to handle HTTP requests, send
 * data to the secondary device, and request data from the device.
 */
void loop() {
  // wifiServer.handleRequests();
  primaryDevice.request_data_from_secondary();
  delay(1000);
  primaryDevice.send_data_to_secondary("from primary to secondary!");
  delay(1000);
}
