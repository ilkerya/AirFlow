
//https://github.com/adafruit/Adafruit_SSD1306
// https://upload.wikimedia.org/wikipedia/commons/f/f8/Codepage-437.png


/*
      #define OLED_GND 42// 13
      #define OLED_POWER 40// 13
      #define OLED_CS    36// 13
      #define OLED_RESET 34
      #define OLED_DC    32// 12  // common 50
      #define OLED_CLK   30 //13 // common  52
      #define OLED_MOSI  28// 11 //common 51
*/
      #define OLED_GND 47// 13
      #define OLED_POWER 45// 13
      #define OLED_CS    41// 13
      #define OLED_RESET 39
      #define OLED_DC    37// 12  // common 50
      #define OLED_CLK   35 //13 // common  52
      #define OLED_MOSI  33// 11 //common 51

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

  /*
 * In Adafruit_SSD1306.h
 * 1. uncomment #define SSD1306_128_64
2. comment #define SSD1306_128_32
3. comment #define SSD1306_96_16
In the example ssd1306_128x64_i2c
4. add #define SSD1306_LCDHEIGHT 64
 *
 */
  /*
#ifdef SSD1306_LCDHEIGHT
  #define SSD1306_LCDHEIGHT 64
#endif  
#ifndef SSD1306_LCDHEIGHT
  #define SSD1306_LCDHEIGHT 64
#endif  

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
*/

//#define DISPLAY_POWEROFF_STANDBYE
#define DISPLAY_SOFTOFF_STANDBYE 

#if defined (DISPLAY_POWEROFF_STANDBYE)  & defined (DISPLAY_SOFTOFF_STANDBYE) 
    #error Select Only One Standbye Type
#endif
 #if !(!defined (DISPLAY_POWEROFF_STANDBYE) ^ !defined (DISPLAY_SOFTOFF_STANDBYE)) 
    #error Select At Least One Standbye Type
#endif

//Adafruit_SSD1306 display(OLED_RESET);
//DISPLAY INITIALIZER
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
void Display_SwitchOff(){

     
      display.clearDisplay(); 
      display.display();  
   #ifdef DISPLAY_POWEROFF_STANDBYE
      digitalWrite(OLED_POWER, LOW);       // turn on pullup resistors
      digitalWrite(OLED_GND, LOW);       // keep GND Level
   #endif   
      
}
void DisplaySetPowerIO(){
     //-- DISPLAY INIT --//
    pinMode(OLED_GND, OUTPUT);
    digitalWrite(OLED_GND, LOW);       // keep GND Level           
    pinMode(OLED_POWER, OUTPUT);
    digitalWrite(OLED_POWER, HIGH);       // turn on pullup resistors    
}
void Display_ReInit_Start(uint8_t Timer){
    DisplaySetPowerIO();
    
}
void Display_ReInit_End(){
   #ifdef DISPLAY_SOFTOFF_STANDBYE
    return;
  #endif

  
   // delay(300); // Pause for 2 seconds // critical
#if defined  ARDUINO_DUE | defined (ARDUINO_MKRZERO) 
    delay(300); // Pause for 2 seconds 
    if(!display.begin(SSD1306_SWITCHCAPVCC)) {  //    SSD1306_EXTERNALVCC
        Serial.println(F("SSD1306 allocation failed"));
            //for(;;); // Don’t proceed, loop forever
    }
  #endif
#if defined (ARDUINO_MEGA)  | defined (CHIPKIT_MAX32) 
    if(!display.begin(SSD1306_SWITCHCAPVCC)) {  //    SSD1306_EXTERNALVCC
        Serial.println(F("SSD1306 allocation failed"));
            //for(;;); // Don’t proceed, loop forever
    }
#endif
      
     Serial.println(F("Display ReInitilized"));  
 //   display.clearDisplay();
 //   display.setTextSize(3);
 //   display.setTextColor(WHITE);  //0  white on black
 //    display.setTextColor(0);  //1     Black on white
    display.dim(0); // lower brightness 
 //   display.setCursor(0, 0);
 //   display.println();
//    display.println("DATALOG"); 
 //   display.display();
    

}

 

void DisplayInit(void){
    DisplaySetPowerIO();
    
    delay(1800); // Pause for 2 seconds // critic !!

  
    if(!display.begin(SSD1306_SWITCHCAPVCC)) {  //  SSD1306_EXTERNALVCC
        Serial.println(F("SSD1306 allocation failed"));
        // for(;;); // Don’t proceed, loop forever
      }


       display.dim(0); // lower brightness 
   // display.begin(SSD1306_SWITCHCAPVCC);
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(WHITE);  //0  white on black
 //    display.setTextColor(0);  //1     Black on white
    display.setCursor(0, 0);
    display.println();
    display.println(F("DATALOG")); 
      display.display();
     // Adafruit_SSD1306::dim  ( 1 ) //1 == lower brightness // 0 == full brightness
      //display.dim       
}

void testdrawchar(void) {
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for(int16_t i=0; i<256; i++) {
    if(i == '\n') display.write(' ');
    else          display.write(i);
  }
  display.display();
 // delay(2000);
}

void displayValues(void)
{


    display.clearDisplay();
    display.setTextSize(1);

//    display.setCursor(0, 0);
//    display.print(Display_Line1);   //10

    display.setCursor(0, 0);
    display.print("Counter :"); 
    display.println(Counter); 

    display.setCursor(0, 8); // Line 1
 //   display.print(Display_Line2);   //10

    display.print(AirTemp,2); // Line 2
    display.print("'C   ");   //10
    display.print(Humidity,4);   //10
    display.print("Rh");   //10

    display.setCursor(0, 16);// Line 3


    
    display.print("V Adc:");   //10
    #ifdef ADC_10BIT     
      display.print(Adc_10bit);   //10
    #endif
    #ifdef ADC_12BIT 
     display.print(Adc_12bit);   //10
    #endif    
    display.print(" V:");   //10
    display.print(Voltage,4);   //10

    display.setCursor(0, 24);//Line 4
    //display.print(Voltage,3);   //10

    display.setCursor(0, 32); //Line 5 
    display.print(AirSpeed,8);   //10
    display.print(" m/sn");   //10

    display.setCursor(0, 40);
 //   display.print(Display_Line6);  // Line 6

    display.setCursor(0, 48);
  //  display.print(Display_Line7); // Line 7

    display.setCursor(0, 56); // // Line 8 

   display.display();
}
