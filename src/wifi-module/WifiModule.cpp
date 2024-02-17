
/**
 * @file WifiModule.cpp
 * @brief Implementation of the WifiModule class for handling WiFi connections
 * and requests.
 */
#include "WifiModule.h"

// Set your network credentials
const char* ssid = "Bat-Wifi";
const char* password = "6mjnP$9ejWC1L!6p";

// Initialize with LED as low
WifiModule::WifiModule(int ledPin) { _ledPin = ledPin; }

// Create an instance of the server on port 80
WiFiServer server(80);

void WifiModule::connect() {
  pinMode(_ledPin, OUTPUT);
  digitalWrite(_ledPin, HIGH);

  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);

  // Wait for the connection
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(WiFi.status());
    delay(5000);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Server started");
}

void WifiModule::disconnect() {
  WiFi.disconnect();
  Serial.println("WiFi disconnected");
}

void WifiModule::handleRequests() {
  Serial.println("Sending data...");

  while (true) {
    // Check if a client has connected
    WiFiClient client = server.accept();
    if (!client.available()) {
      delay(10);
    }

    if (client.connected()) {
      Serial.println("Client connected");
      // Read the request from the client
      String request = client.readStringUntil('\n');
      Serial.println("client request " + request);

      // Call the appropriate function based on the request
      if (request.indexOf("/api/on") != -1) {
        turnLEDOn();
        sendResponse(client, 200, "Turned on LED");
      } else if (request.indexOf("/api/off") != -1) {
        turnLEDOff();
        sendResponse(client, 200, "Turned off LED");
      } else {
        sendResponse(client, 404, "Not found");
      }
      // Discard any remaining characters in the client input buffer
      client.flush();
    }
    delay(10);
  }
}

void WifiModule::turnLEDOn() {
  Serial.println("Turn LED on");
  digitalWrite(_ledPin, LOW);
}

void WifiModule::turnLEDOff() {
  Serial.println("Turn LED off");
  digitalWrite(_ledPin, HIGH);
}

void WifiModule::sendResponse(WiFiClient client, int statusCode,
                              const char* message) {
  client.println("HTTP/1.1 " + String(statusCode) + " OK");
  client.println("Content-Type: text/plain");
  client.println("Connection: close");
  client.println();
  client.println(message);
}
