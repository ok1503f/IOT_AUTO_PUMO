# IOT_AUTO_PUMP
Soil Moisture Monitoring and Pump Control System
This project is an Arduino-based system that monitors soil moisture levels and controls a pump to maintain optimal soil moisture for plants. It utilizes Blynk for remote monitoring and control via a mobile app and sends notifications via LINE messaging platform.

Table of Contents
- Features
- Requirements
- Setup
- Usage
- Customization
- Contributing
- License

Features
- Real-time monitoring of soil moisture levels.
- Automatic control of the pump based on user-defined moisture thresholds.
- Manual control of the pump via the Blynk mobile app.
- Notifications sent via LINE when soil moisture exceeds certain thresholds.

Requirements
- Arduino board (e.g., ESP8266)
- Soil moisture sensor
- DHT temperature/humidity sensor
- Relay module
- Blynk account and mobile app
- LINE Notify account (for receiving notifications)

Setup
1. Hardware Setup:
Connect the soil moisture sensor, DHT sensor, and relay module to the Arduino board as per the provided circuit diagram.
2. Software Setup:
- Install the necessary Arduino libraries: Blynk, TridentTD_LineNotify, Adafruit_Sensor, and DHT.
- Clone or download this repository.
- Open the Arduino IDE and upload the provided sketch (soil_moisture_pump_control.ino) to your Arduino board.
3. Blynk Setup:
- Create a new project in the Blynk app.
- Add widgets (buttons, sliders, etc.) to control the pump and display soil moisture data.
- Obtain the Blynk authentication token and replace BLYNK_AUTH_TOKEN in the sketch with your token.
4. LINE Notify Setup:
- Create a LINE Notify account and generate an access token.
- Replace LINE_TOKEN in the sketch with your access token.

Usage
1. Power on the Arduino board.
2. Open the Blynk app on your mobile device.
3. Monitor soil moisture levels and control the pump manually or set automatic mode with desired moisture thresholds.
4. Receive notifications via LINE when soil moisture exceeds specified thresholds.

Customization
- Adjust the pin assignments and sensor types in the sketch if using different hardware configurations.
- Modify the thresholds and notification messages as per your requirements.
- Extend the functionality by adding more sensors or integrating with other platforms.
Contributing
Contributions to this project are welcome. You can contribute by reporting issues, suggesting improvements, or submitting pull requests.

License
This project is licensed under the MIT License.

