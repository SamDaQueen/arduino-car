#ifndef PRIMARY_H
#define PRIMARY_H

#include <ArduinoJson.h>
#include <Wire.h>

/**
 * @brief The Primary class functions for the ESP8266 sketch.
 *
 * This class provides functionality to set up the I2C communication.
 */
class Primary {
 public:
  /**
   * @brief Constructs a new Primary object.
   */
  Primary();

  /**
   * @brief Initializes the I2C communication for sending and receiving data.
   */
  void initialize_i2c();

  /**
   * @brief Requests data from the secondary module.
   */
  void request_data_from_secondary();

  /**
   * @brief Sends data to the secondary module.
   *
   * @param data The data to be sent.
   */
  void send_data_to_secondary(const char* data);

 private:
  /**< The I2C address of the secondary module. */
  const int SECONDARY_ADDRESS = 8;
};

#endif  // PRIMARY_H