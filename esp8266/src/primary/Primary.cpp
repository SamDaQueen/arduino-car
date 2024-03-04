/**
 * @file Primary.cpp
 * @brief Implementation file for the Primary class.
 * @author Samreen Ansari
 */
#include "Primary.h"

Primary::Primary() {}

void Primary::initialize_i2c() {
  // Begin the I2C communication (primary does not need to specify address).
  Wire.begin();
  delay(100);
  Serial.println("I2C Primary Initialized");
}

void Primary::request_data_from_secondary() {
  // Request 21 bytes of data from the secondary device and print it.
  Wire.requestFrom(SECONDARY_ADDRESS, 21);
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
}

void Primary::send_data_to_secondary(const char* data) {
  // Send data to the secondary device.
  size_t len = strlen(data);
  Wire.beginTransmission(SECONDARY_ADDRESS);
  Wire.write((uint8_t*)data, len);
  Wire.endTransmission();
}
