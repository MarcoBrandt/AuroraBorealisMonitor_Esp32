# Aurora Borealis Detector for ESP32

This project is an Aurora Borealis detector for the ESP32 microcontroller. The built-in LED on the ESP32 board will blink if there's a higher chance of seeing the Aurora Borealis in Helsinki, Finland. The detector checks for Aurora Borealis every 15 minutes.

## Prerequisites
- ESP32 development board
- Arduino IDE
- Access to a Wi-Fi network

## Libraries

Make sure to install the following libraries in the Arduino IDE:

- WiFi (included with the ESP32 package)
- HTTPClient (included with the ESP32 package)
- ArduinoJson (install from the Library Manager)

## Setup
1. Open the Aurora Borealis Detector script in the Arduino IDE.
2. Replace your_SSID and your_PASSWORD in the script with your Wi-Fi credentials.
3. Connect the ESP32 board to your computer using a USB cable.
4. In the Arduino IDE, select the appropriate board and port for your ESP32 board.
5. Upload the script to your ESP32 board.

## Usage

After uploading the script, the ESP32 will automatically connect to your Wi-Fi network and start checking for Aurora Borealis every 15 minutes.

* If there's a higher chance of seeing the Aurora Borealis, the built-in LED will blink.
* If there's a low chance of seeing the Aurora Borealis, the built-in LED will remain off.

To monitor the K-index values and the detector's status, open the Serial Monitor in the Arduino IDE. The K-index values and the status messages will be printed there.

## Customization

To change the time interval between checks or to adapt the project for a different location, modify the following variables in the script:

* kIndexThreshold: Adjust this value to change the K-index threshold for detecting the Aurora Borealis.
 
* delay(): Change the value in the delay() function at the end of the loop() to set a different time interval between checks (in milliseconds). For example, delay(1800000) would set a 30-minute interval between checks.

## API

The project uses the Aurora API provided by the National Oceanic and Atmospheric Administration (NOAA) Space Weather Prediction Center. The API provides the estimated planetary K-index, which is a measure of geomagnetic activity. In general, higher K-index values indicate better chances of seeing the Aurora Borealis.
