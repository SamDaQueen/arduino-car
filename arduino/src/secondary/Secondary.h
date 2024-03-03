
#ifndef SECONDARY_H
#define SECONDARY_H

#include <Wire.h>

/**
 * @brief The Secondary class functions for the Arduino sketch.
 * @author Samreen Ansari
 *
 * This class provides functionality to set up the I2C communication.
 */
class Secondary {
 public:
  /**
   * @brief Constructs a new Secondary object.
   */
  Secondary();

  /**
   * @brief Initializes the I2C communication for sending and receiving data.
   */
  void initialize_i2c();

  /**
   * @brief Sends data to the primary device when requested.
   */
  static void respond_data_to_primary();

  /**
   * @brief Receives data from the primary device.
   *
   * @param byteCount The number of bytes to receive.
   */
  static void receive_data_from_primary(int byteCount);

 private:
  /**< The I2C address of the Arduino. */
  const int SECONDARY_ADDRESS = 8;
};

#endif