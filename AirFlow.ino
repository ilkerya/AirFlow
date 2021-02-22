
#include <stdio.h>
#include <math.h>

//  #define ARDUINO_MEGA // 8 bit AVR Compiler -> GNU AVRDude
#define ARDUINO_DUE // ARM Cortex M3 -> GNU AVRDude 
// #define ARDUINO_MKRZERO // ARM Cortex M0

#if defined (ARDUINO_MEGA)  & defined (ARDUINO_DUE)
#error Select Only One Platform
#endif
#if !(!defined (ARDUINO_MEGA) ^ !defined (ARDUINO_DUE))
#error Select At Least One Platform
#endif

  #define ADC_12BIT  
 // #define ADC_10BIT 

#if defined (ADC_12BIT)  & defined (ADC_10BIT)
#error Select Only Adc Res
#endif
#if !(!defined (ADC_12BIT) ^ !defined (ADC_10BIT))
#error Select At Least One Adc Res
#endif
  
  
  //#define PRINTOUT 
  #define NTC_INPUT  A2

#include <Adafruit_Si7021.h>
#include <Adafruit_SSD1306.h>
#include <gfxfont.h>
#include <Adafruit_GFX.h>

#include  "Variables.h"
#include  "Display.h"
#include  "Functions.h"

void setup() {
  Serial.begin(115200);
  delay(100);
  DisplayInit();
  SensorInit(); // TEMP HUM
  CSV_Header();
}
void loop() {
  Adc_Read();
  SensorRead();
  Run_AirSpeed();
  CSV_Data();
  //PrintOutputs();
  displayValues();
  delay(2000);
  Counter++;
}
