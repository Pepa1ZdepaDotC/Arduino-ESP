#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

int myFunction();

void setup() {
  tft.init();
  tft.fillScreen(TFT_BLACK);
  
}

void loop() {

}

int myFunction() {

}