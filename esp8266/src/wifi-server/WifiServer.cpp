
/**
 * @file WifiServer.cpp
 * @brief Implementation of the WifiServer class for handling WiFi connections
 * and requests.
 */
#include "WifiServer.h"

// Set your network credentials
const char* ssid = "Samreen";
const char* password = "hellothere";

// Initialize with LED as low
WifiServer::WifiServer(int ledPin) { _ledPin = ledPin; }

// Create an instance of the server on port 80
WiFiServer server(80);

void WifiServer::connect() {
  pinMode(_ledPin, OUTPUT);
  digitalWrite(_ledPin, HIGH);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);

  // Wait for the connection
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(WiFi.status());
    delay(5000);
    Serial.print(".");
  }

  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Server started");
}

void WifiServer::disconnect() { WiFi.disconnect(); }

void WifiServer::handleRequests() {
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

void WifiServer::turnLEDOn() { digitalWrite(_ledPin, LOW); }

void WifiServer::turnLEDOff() { digitalWrite(_ledPin, HIGH); }

void WifiServer::sendResponse(WiFiClient client, int statusCode,
                              const char* message) {
  client.println("HTTP/1.1 " + String(statusCode) + " OK");
  client.println("Content-Type: text/plain");
  client.println("Connection: close");
  client.println();
  client.println(message);
}
