#include <Adafruit_NeoPixel.h>





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


// final pintout
#define micPin A1
#define neopixelPin 20
#define buttonPin 10


Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, neopixelPin, NEO_GRB + NEO_KHZ800);



int Mode;
int LastMode;

int micValue;
int micThreshold = 80;
int micMax = 1023;
int micMin = 0;

boolean debug = true;


uint32_t off = strip.Color(0, 0, 0);

uint32_t orange = strip.Color(255, 200, 5);
uint32_t yellow = strip.Color(255, 200, 30);
uint32_t redish = strip.Color(226, 98, 10);
uint32_t greenish = strip.Color(20, 191, 73);
uint32_t blue = strip.Color(22, 249, 195);


void setup() {

  strip.begin();
  strip.show();

  pinMode(micPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("hello");

  delay(1000);

  callibrateMIC();

}


void loop() {

  // check the button status
  Mode = checkButton(0);
  // print for Serial to debug
  if (debug) debugPrint();

  // read microphone value
  micValue = read_Microphone();

  Mode=constrain(Mode,0,4);

  switch (Mode) {

    case 0:
     soundModeFlash(micValue, micThreshold);
      break;

    case 1:
      
      animationMix(micValue, micMin, micMax);
      break;

    case 2:
      soundModeTequilaSunrise(micValue, micMin, micMax);
      break;

    case 3:
      soundModeFlash2(micValue, micThreshold);
      // soundModeFade(micValue, micThreshold);
      break;



    case 4:
      callibrateMIC();
      // set back to the last mode
      Mode = checkButton(1);
      break;

    default:
      break;
  }

  delay(10);

}


