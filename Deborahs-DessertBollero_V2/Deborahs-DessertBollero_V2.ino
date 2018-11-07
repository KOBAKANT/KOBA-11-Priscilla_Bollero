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
int mode = 0;
int lastMode;

int fadeTimer;
int fadeStep=3;

int micValue;
int micThreshold = 80;
int micMax = 0;
int micMin = 0;
long timeStamp = 0;
int avg;
int sampleSize=5;

int micFadeMax = 0;
int micFadeMin = 1023;

int intensity=0;
int intensityMax=0;
float thresholdPercent;

int randomNum;


uint32_t white = strip.Color(247, 150, 35);

uint32_t red = strip.Color(220, 20, 0);
uint32_t green = strip.Color(145, 255, 46);
uint32_t blue = strip.Color(22, 249,195);
uint32_t off = strip.Color(0, 0, 0);

uint32_t orange = strip.Color(255, 200, 5);
uint32_t yellow = strip.Color(255, 200, 30);

uint32_t fadecolor1 = strip.Color(226, 98, 10);
uint32_t fadecolor2 = strip.Color(220, 191, 73);

uint32_t tequilaSunrise[] = {orange, red, yellow};

uint32_t randomColor[] = {white,blue, fadecolor1, fadecolor2, orange, yellow };

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

  avg= analogRead(micPin);

  Serial.begin(9600);
}


void loop() {


      
  micValue = analogRead(micPin);
  avg=(avg*(sampleSize-1)+micValue)/sampleSize;
  micValue=avg;
  
  lastMode=mode;
  buttonMode();
  debugPrint();
  
    if (lastMode!=mode){
      fadeTimer=0;
      
      randomNum=random(5);
      
    }

   switch (mode) {

    case 0:  
// input two colors to mix
    animationMix(249,77,22,22, 249,195, 155,149,22);
   break;


    case 3:
      soundModeFade();
      break;

    case 1:
      soundModeFlash();

      break;

    case 2:
      soundModeTequilaSunrise();
      break;

//     case 6:
//      animation(randomColor[randomNum]);
//      break;



    case 4:

      callibrateMIC(5000,0.4);
      break;

    default:
      break;
  }

  delay(20);

}
