/**
 * @file wifi-module.ino
 * @brief Arduino code for controlling a WiFi module.
 *
 * This code initializes a WiFi module and handles requests using the WifiModule
 * class. It connects to a WiFi network, turns on an LED, and continuously
 * handles requests in the loop.
 */
#include "WifiModule.h"

const int LED_PIN = LED_BUILTIN;

WifiModule wifiModule(LED_PIN);

void setup() {
  Serial.begin(115200);
  wifiModule.connect();
  wifiModule.turnLEDOn();
}

void loop() { wifiModule.handleRequests(); }
