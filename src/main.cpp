#include <Arduino.h>
/*
TFT LCD 240x240

  RST - Reset                  D4
  CS  - Chip Select            D22
  DC  - Data / Command         D16

  SDA - Serial Data            D23
  SCL - Serial Clock (CLK)     D18
  GND - Ground                 GND
  Vcc - +3.3 V                 3V3 (3,3 V; V serves as the decimal point)


*/

#include <TFT_eSPI.h>
/*
install this library in library manager
in this library you have to change some pins so they correspond with the pins above
D:\whatever your folder is called \Sketches\libraries\TFT_eSPI\User_Setup.h

LINE 45 comment in (disable) #define -> //#define
LINE 65 uncomment the driver //#define -> #define GC9A01_DRIVER

LINE 223
  #define TFT_MOSI 23
  #define TFT_SCLK 18
  #define TFT_CS   22
  #define TFT_DC   16
  #define TFT_RST  4 
LINE 227
*/

TFT_eSPI tft = TFT_eSPI();

void setup() {
  tft.init();
  tft.fillScreen(TFT_BLACK);
  Serial.begin(9600);
  
}

void loop() {

}