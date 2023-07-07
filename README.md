

# ESP32MiniDriver
ESP32 Wroom 32U Mini Driver




 

<img src="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitC-v4-pinout.png">
ESP32 Wardriving
A arduino ino file to get your hardware going for wardriving on the ESP32 WiFi microcontroller 

Components
Any ESP32-based board should work with the basic required components,  


Required Components:

Component	Purpose
ESP32 Wroom-32U 	Gather WiFi data & control hardware modules
SD Reader	Store data that we can analyze with WiGLE / Python
GPS Module	Grab geolocation data + timestamp
Optional Components:

Component	Purpose
128x64 OLED	Get a visual display of WiFi data being captured
LiPo Battery	Power your ESP8266 for portable applications
Battery Module	Manage power for your ESP8266 w/ a LiPo battery
100K Ω Resistor	Optional to read in battery level w/ the D1 Mini
Hardware Setup
SD Reader Module

SD Reader Pin	ESP32 GPIO	D1 Mini Pin
MISO	GPIO12	D6
MOSI	GPIO13	D7
SCK	GPIO14	D5
CS	GPIO15	D8
GPS Module

GPS Pin	ESP8266 GPIO	D1 Mini Pin
TX	GPIO2	D4
RX	GPIO0	D3
