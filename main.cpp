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

#define W 240       // Width of display
#define H 240       // Height of display
#define R 115       // Radius
#define R_SQR 13225 // 13225 * 13225 
#define CENTRE 120   // Centre of the display

void defScr(uint16_t); //Draws the default, variable n being how many "stop lines" it should draw

void setup() {
  Serial.begin(9600);
  tft.init();
  Serial.println("Initialised LCD");
  tft.fillScreen(TFT_BLACK);
  defScr(5);
}

void loop() {

}

void defScr(uint16_t n){
  if (n < 0 && n > 40){
    Serial.println("ERROR: In function defScr, number passed is out of range. Please choose a number from 0 to 40.");
    return;
  }

  uint16_t deg;
  uint16_t a;
  uint16_t b;
  uint16_t tempA;
  uint16_t tempB;

  tft.drawCircle(CENTRE, CENTRE, R, TFT_RED);

  deg = 360 / n; // Example: 360 / 4 = Every 90 degrees there should be a line
  Serial.println(deg);
  /*
    a = sin(d) * R;
    b = sqrt(R_SQR - a*a);
  */

  uint16_t count = 0;
  for (uint16_t d = 0; d < 360; d += deg){
    a = sin(d) * R;
    b = sqrt(R_SQR - a*a);
    
    if (d >= 0 && d <= 90){
      tempA = 120 + a;
      tempB = 120 - b;

      tft.drawLine(tempA, tempB, CENTRE, CENTRE, TFT_WHITE);
    }
    else if (d >= 90 && d<= 180){
      tempA = 120 - a;
      tempB = 120 - b;

      tft.drawLine(tempA, tempB, CENTRE, CENTRE, TFT_WHITE);
    }
    else if (d >= 180 && d<=270){
      tempA = 120 - a;
      tempB = 120 + b;

      tft.drawLine(tempA, tempB, CENTRE, CENTRE, TFT_WHITE);
    }
    else if (d>= 270 &&d <= 360){
      tempA = 120 + a;
      tempB = 120 + b;

      tft.drawLine(tempA, tempB, CENTRE, CENTRE, TFT_WHITE);
    }

    
    
  }


}