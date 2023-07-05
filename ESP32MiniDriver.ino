#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <TinyGPS++.h>
#include <SD.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

TinyGPSPlus gps;
HardwareSerial GPS_Serial(1);

File file;

void setup() {
  Serial.begin(115200);
  GPS_Serial.begin(9600, SERIAL_8N1, 16, 17);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  if(!SD.begin()){
    Serial.println("Card Mount Failed");
    return;
  }
  file = SD.open("/wifi_gps_data.csv", FILE_WRITE);
  if(!file){
    Serial.println("Failed to open file for writing");
    return;
  }
  file.println("SSID,RSSI,GPS Latitude,GPS Longitude");
}

void loop() {
  int n = WiFi.scanNetworks();
  for (int i = 0; i < n; i++) {
    while (GPS_Serial.available() > 0) {
      gps.encode(GPS_Serial.read());
    }
    String data = String(WiFi.SSID(i)) + "," + String(WiFi.RSSI(i)) + "," + String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6);
    file.println(data);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("SSID: " + WiFi.SSID(i));
    display.println("RSSI: " + String(WiFi.RSSI(i)));
    display.println("Location: " + String(gps.location.lat(), 6) + ", " + String(gps.location.lng(), 6));
    display.display();
    delay(5000);
  }
  WiFi.scanDelete();
  delay(5000);
}