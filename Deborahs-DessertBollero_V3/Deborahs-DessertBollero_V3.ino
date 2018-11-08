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

// teensy 2.0 for developping
//#define micPin A5
//#define neopixelPin 6
//#define buttonPin 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, neopixelPin, NEO_GRB + NEO_KHZ800);

int buttonState;             // the current reading from the input pin
int buttonPressed = 0;  // stores the state of the button (0=not pressed, 1=pressed)

int mode = 2;
int lastMode;

float intensity;
float acc = 0.01; // this will change the animation speed

float mix=0.0;
float mixadd=0.01;

int micValue;
int micThreshold = 80;
int micMax = 1023;
int micMin = 0;

boolean micTrigger;
boolean last_micTrigger;


int avg;
int sampleSize = 5;

int micFadeMax = 0;
int micFadeMin = 1023;

//int intensity=0;
//int intensityMax=0;
//float thresholdPercent;

//int randomNum;

//int fadeTimer;
//int fadeStep = 3;

long timeStamp = 0;


uint32_t white = strip.Color(247, 150, 35);


uint32_t off = strip.Color(0, 0, 0);

uint32_t orange = strip.Color(255, 200, 5);
uint32_t yellow = strip.Color(255, 200, 30);

uint32_t redish = strip.Color(226, 98, 10);
uint32_t greenish = strip.Color(20, 191, 73);
uint32_t blue = strip.Color(22, 249, 195);


uint32_t tequilaSunrise[] = {orange, redish, yellow};

uint32_t randomColor[] = {blue, redish, greenish, orange, yellow };

void setup() {


  // test LED:
  strip.begin();
  strip.setBrightness(20);
  strip.setPixelColor(0, orange);
  strip.show();
  delay(1000);

  pinMode(micPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  avg = analogRead(micPin);

  Serial.begin(9600);
  Serial.println("hello");
  delay(1000);
  strip.setPixelColor(0, off);
  strip.show();

  lastMode = mode;

callibrateMIC(5000,0.4);

}


void loop() {



  // store the current mode for comparison
  lastMode = mode;
  // check the button status
  buttonMode();
  // print for Serial to debug
  //debugPrint();

 

  switch (mode) {

    //-----------------------------------
    case 0:
      // if it is the first time it came to this mode, then reset values
      if (lastMode != 0) {
        intensity = 0.0 ;
        acc = 0.01;
      }

      intensity = intensity + acc; // this will change the animation speed
      if (intensity >= 1.0 || intensity <= 0.0) {
        acc = -acc;
      }
      intensity = constrain(intensity, 0.0, 1.0);

      // input two colors to mix,  R1, G1, B1, R2, G2, B2, R3, G3, B3
      animationMix(249, 77, 22, 22, 249, 195, 155, 149, 22);

      break;
    //-----------------------------------

    case 3:
      read_Microphone();

      if (micValue > micThreshold) {
        if (!micTrigger) {
          micTrigger = true;
          acc = 0.05;
          soundModeFade(micTrigger, acc);
        }
      }
      else {
        micTrigger = false;
      }
      soundModeFade(micTrigger, acc);
      break;
    //-----------------------------------
    
    case 1:
      read_Microphone();
      if (micValue > micThreshold) {
        soundModeFlash(50);
      }
      break;

    case 2:
    read_Microphone();
        soundModeTequilaSunrise(micValue);
      break;


    case 4:
      callibrateMIC(5000,0.4);
      break;

    default:
      break;
  }

  delay(20);

}

void   read_Microphone() {
  int val = analogRead(micPin);

  //take the avarage of the sample size
  avg = (avg * (sampleSize - 1) + val) / sampleSize;
  val = avg;
  micValue = val;

}
