

# ESP32MiniDriver
ESP32 Wroom 32U Mini Driver




 

<img src="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitC-v4-pinout.png">
ESP32 Wardriving
A arduino ino file to get your hardware going for wardriving on the ESP32 WiFi microcontroller 

Components
Any ESP32-based board should work with the basic required components,  


Required Components:

Component	Purpose
ESP32 Wroom-32U 	Gather WiFi data in 2.4 Ghz & BlueTooth 
SD Reader	Store data that we can analyze with WiGLE / Python
GPS Module	Grab geolocation data + timestamp


Component	Purpose

128x64 OLED	

GND GPIO GND 
VCC GPIO 3V3
SCK GPIO 22
SDA GPIO 21

SD Reader Module

SD Reader Pin	ESP32 GPIO	 
3V3  GPIO  3v3
CS GPIO 05
MOSI GPIO 23 
CLK GPIO 18
MISO GPIO 19
GND GPIO GND 

 
GPS Module

GPS Pin	ESP32
VCC    GPIO	 3v3
TX	    GPIO2	16
RX     GPIO0	17
GND    GPIO  GND
