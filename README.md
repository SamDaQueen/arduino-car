# Arduino Car (WIP)

This project contains the modules required for creating an Arduino car using a Wi-Fi module, TT motor tire wheels, motor driver controller board, and other components.
<br><br>
For personal logs related to this project's development process, including notes on what was tried, issues faced, and solutions implemented, please visit my Notion page:

[Link to Personal Logs on Notion](https://www.notion.so/c5b6ac126b9d41408ebcfea41daa169a?v=1ad439b3949a4593b61890744ed84b66&pvs=4)

## Project Directory Structure

- `README.md`: Project documentation and overview.
- `src/`: Source code directory
    - `wifi-module/`: The code for connecting to the ESP8266 WiFi module
        - `check-wifi/`: Scans for available WiFi networks
        - `wifi-module.h`: Header file for the functions for Wifi connection
        - `wifi-module.h`: Implements the functions in the header file
        - `wifi-module.ino`: Arduino sketch that starts the wifi connection and server from the header file

## Project Components

- `WiFi Module`: ESP8266 D1 Mini




