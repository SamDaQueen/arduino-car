/**
 * @file arduino.ino
 * @brief Arduino Sketch for the Arduino Secondary Device
 * @author Samreen Ansari
 *
 * This sketch initializes the Arduino secondary device, sets up the serial
 *communication, and initializes the I2C communication for the secondary device.
 **/
#include <Wire.h>

#include "src/secondary/Secondary.h"

Secondary secondaryDevice;

/**
 * @brief Initializes the Arduino secondary device.
 *
 * This function sets up the serial communication and initializes the I2C
 * communication for the secondary device.
 */
void setup() {
  Serial.begin(9600);
  secondaryDevice.initialize_i2c();
}

/**
 * @brief The main loop of the Arduino secondary device.
 *
 * This function is called repeatedly to add a delay of 100 milliseconds.
 */
void loop() { delay(100); }
