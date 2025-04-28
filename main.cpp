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


#define W 240             // Width of display
#define H 240             // Height of display
#define R 115             // Radius
#define CENTRE 120        // Centre of the display
#define BGCOLOR TFT_BLACK // Change it to whatever bg color you want

//currently unused variables, they will be used for the encoder in the future
int16_t pos = 0;
int16_t numOfRotations = 0;
int16_t position = 0;

// drawDefaultScr has a range from 0 to 60, 0 being a black screen.
void drawDefaultScr(uint16_t n) { //Draws the default screen, variable n being how many "stop lines" it should draw. 
  if (n < 0 || n > 60) {
      Serial.println("ERROR: In function drawDefaultScr, number passed is out of range. Please choose a number from 1 to 60.");
      return;
  } 
  else if (n == 0){
    tft.fillCircle(CENTRE, CENTRE, 100, BGCOLOR);
    return;
  }
  float_t rad = (2 * PI) / n; // Angle in radians for each segment

  for (uint16_t i = 0; i < n; i++) {
      float_t d = i * rad; // Current angle in radians
      float_t tempX = round(CENTRE + cos(d) * R);  // Calculate X for the starting point of the line
      float_t tempY = round(CENTRE + sin(d) * R);  // Calculate Y for the starting point of the line

      tft.drawLine(tempX, tempY, CENTRE, CENTRE, TFT_WHITE); // Draw the line
      
  }
  tft.fillCircle(CENTRE, CENTRE, 100, BGCOLOR); // "Erase" so there are only notches

  //TODO: calculate the starting point so you dont have to erase the lines

  return;
}

void currPos(){

}

void normalizedPos(){ // Normalizes variable pos into variable number of rotations * 360 + variable position.
  numOfRotations = pos / 360;
  position = pos % 360;
  return;
}

void setup() {
  Serial.begin(9600);
  tft.init();
  tft.fillScreen(BGCOLOR);
  drawDefaultScr(8); // Demonstration of drawing notches
}

void loop() {

}