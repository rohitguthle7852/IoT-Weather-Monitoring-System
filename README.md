# IoT Based Smart Weather Monitoring System

This project monitors:
- Temperature
- Humidity
- Rain Detection
- Light Intensity

using ESP8266 and Blynk IoT platform.

## Features
- Real-time monitoring
- Blynk IoT integration
- LCD display output
- WiFi communication
- Smart weather analysis

## Components Used
- ESP8266
- DHT11 Sensor
- Rain Sensor
- LDR Sensor
- I2C LCD Display
- Blynk IoT



🔌 Connections — IoT Weather Monitoring System
🧠 Main Controller
ESP8266 WiFi Module (NodeMCU)
🌡 DHT11 Sensor Connection
DHT11 Pin	ESP8266 Pin
VCC	3V3
GND	GND
DATA	D4
🌧 Rain Sensor Connection
Rain Sensor Pin	ESP8266 Pin
VCC	3V3
GND	GND
DO	D5
☀ LDR Sensor Connection
LDR Module Pin	ESP8266 Pin
VCC	3V3
GND	GND
AO	A0
📟 I2C LCD 16x2 Connection
LCD Pin	ESP8266 Pin
VCC	VIN / 5V
GND	GND
SDA	D2
SCL	D1
🔋 Power Supply
Device	Supply
ESP8266	USB / 5V
Sensors	3.3V
LCD	5V
📌 Pin Summary
Component	Pin
DHT11	D4
Rain Sensor	D5
LDR	A0
LCD SDA	D2
LCD SCL	D1
⚙️ Output

The system displays:

temperature
humidity
rain status
light intensity

on:

16x2 I2C LCD Display
Blynk IoT app in real time.
