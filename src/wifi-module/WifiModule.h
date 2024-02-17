#ifndef WIFI_MODULE_H
#define WIFI_MODULE_H

#include <ESP8266WiFi.h>

#include "Arduino.h"
#include "WiFiClient.h"

/**
 * @brief The WifiModule class provides functionality to connect and disconnect
 * from a WiFi network, handle incoming requests, and control an LED.
 */
class WifiModule {
 public:
  /**
   * @brief Constructs a WifiModule object with the specified LED pin.
   *
   * @param ledPin The pin number to which the LED is connected.
   */
  WifiModule(int ledPin);

  /**
   * @brief Connects to the WiFi network.
   */
  void connect();

  /**
   * @brief Disconnects from the WiFi network.
   */
  void disconnect();

  /**
   * @brief Handles incoming requests from clients.
   */
  void handleRequests();

  /**
   * @brief Turns the LED on.
   */
  void turnLEDOn();

  /**
   * @brief Turns the LED off.
   */
  void turnLEDOff();

 private:
  int _ledPin;

  /**
   * @brief Sends a response to the client.
   *
   * @param client The WiFiClient object representing the client.
   * @param statusCode The HTTP status code of the response.
   * @param message The message to be sent as the response body.
   */
  void sendResponse(WiFiClient client, int statusCode, const char* message);
};

#endif