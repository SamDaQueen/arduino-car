
/**
 * @file Secondary.cpp
 * @brief Implementation file for the Secondary class.
 * @author Samreen Ansari
 */
#include "Secondary.h"

Secondary::Secondary() {}

void Secondary::initialize_i2c() {
  // Begin the synchronous I2C communication with the specified address.
  Wire.begin(SECONDARY_ADDRESS);

  // Register the functions to be called when data is requested or received.
  Wire.onRequest(respond_data_to_primary);
  Wire.onReceive(receive_data_from_primary);

  delay(100);
  Serial.println("I2C Secondary Initialized");
}

void Secondary::respond_data_to_primary() {
  // Send a response to the primary device when requested.
  const char *message = "Hello from secondary!";
  size_t messageSize = strlen(message);
  Wire.write((const uint8_t *)message, messageSize);
}

void Secondary::receive_data_from_primary(int byteCount) {
  // Receive data and print from the primary device whenever sent.
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
}
