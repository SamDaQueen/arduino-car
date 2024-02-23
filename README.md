# Arduino Car (WIP)

This project contains the modules required for creating an Arduino car using a Wi-Fi module, TT motor tire wheels, motor driver controller board, and other components.
<br><br>
For personal logs related to this project's development process, including notes on what was tried, issues faced, and solutions implemented, please visit my Notion page:

[Link to Personal Logs on Notion](https://www.notion.so/c5b6ac126b9d41408ebcfea41daa169a?v=1ad439b3949a4593b61890744ed84b66&pvs=4)

## Project Directory Structure

- `README.md`: Project documentation and overview.
- `arduino`: Sketch and src files for the Arduino
    - `arduino.ino`: The sketch file to make Arduino the secondary
    - `src`: Source code directory for Arduino
        - `secondary/`: The code for I2C communication as secondary
- `esp8266`: Sketch and src files for the ESP8266 WiFi Module
    - `esp8266.ino`: The sketch file to make ESP8266 the primary
    - `src/`: Source code directory
        - `check-wifi/`: Scans for available WiFi networks
        - `primary/`: The code for I2C communication as secondary
        - `wifi-server/`: The functions for Wifi connection

## Project Components

- `Arduino`: Arduino MEGA 2560
- `WiFi Module`: ESP8266 D1 Mini

## Dependencies

- `ArduinoJson` v7.0.3
- `Wire.h` Built-in
- `ESP8266WiFi.h` Built-in


