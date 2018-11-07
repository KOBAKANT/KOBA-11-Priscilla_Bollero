/*
  KOBA Discolele Commission code for Teensy
  Translates microphone input into thresholded trigger for Neopixels
  Pushbutton selects different modes

  ////////////
  PINOUT TEENSY
  ////////////
  +   --> +Teensy, +MIC, +Neopixel
  -   --> -Teensy, -MIC, -Neopixel, pushbutton
  10  --> pushbutton input
  20  --> neopixel data
  A1 ´--> MIC input
*/


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define micPin A1
#define neopixelPin 20
#define buttonPin 10

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, neopixelPin, NEO_GRB + NEO_KHZ800);

int buttonState;             // the current reading from the input pin
int buttonPressed = 0;  // stores the state of the button (0=not pressed, 1=pressed)
int mode = 0;
int micValue;
int micThreshold = 180;
int micMax = 0;
int timeStamp = 0;

uint32_t red = strip.Color(255, 0, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t off = strip.Color(0, 0, 0);
uint32_t white = strip.Color(255, 255, 255);
uint32_t orange = strip.Color(255, 200, 5);
uint32_t yellow = strip.Color(255, 218, 3);

uint32_t tequilaSunrise[] = {orange, red, yellow};

void setup() {
  Serial.println("test");
  // test LED:
  strip.begin();
  strip.setBrightness(20);
  strip.setPixelColor(0, orange);
  strip.show();
  delay(200);

  pinMode(micPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}


void loop() {
  
  buttonMode();
  debugPrint();

}
