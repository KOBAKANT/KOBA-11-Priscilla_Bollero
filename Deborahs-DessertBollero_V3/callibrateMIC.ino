long callibrateDuration = 5000;
float  thresholdPercent = 0.25;

void callibrateMIC() {

if (debug){
  Serial.print("Now in CALLIBRATION mode for ");
  Serial.print(callibrateDuration);
  Serial.println(" cycles...");
}

  strip.setBrightness(255);

  // turn off all the pixels
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, strip.Color(22, 249, 195));
  }
  strip.show();

  // reset min and max
  micMax = 0;
  micMin = 1023;


  delay(1000);

  // mark the starting time
  long callibrateStart = millis();
  long currentTime = millis();

  while (currentTime - callibrateStart  < callibrateDuration) {

delay(40);
    micValue = read_Microphone();
    // if the micValue input is too loud at the calibration phase
//    micValue =(micValue /3)*2;


    if (micValue < micMin) micMin = micValue;
    if (micValue > micMax) micMax = micValue;
    
    // print the result in debug mode
    if (debug) calibDebug();


    // display the time with pixel
    long duration = currentTime - callibrateStart;
    int indicatorNum = map(duration, 0, callibrateDuration, 0, 4);
    indicatorNum = constrain(indicatorNum, 0, 3);

    
  // turn on all the pixels
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, strip.Color(22, 249, 195));
  }
    strip.setPixelColor(indicatorNum, off);
    switch(indicatorNum){
      case 0:
      strip.setPixelColor(7, off);
      break;
      case 1:
      strip.setPixelColor(6, off);
      break;
      case 2:
      strip.setPixelColor(4, off);
      break;
      case 3:
      strip.setPixelColor(5, off);
      break;
      
    }
    strip.setPixelColor(indicatorNum+4, off);
    strip.show();

    currentTime = millis();
  }

  // calculate the threshold
  micThreshold = ((micMax - micMin) * thresholdPercent) + micMin;

if (debug){
  Serial.print("microphoe Threshold is ");
  Serial.println(micThreshold);
  Serial.println("DONE CALLIBRATION");
  }

  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, off);
  }
  strip.show();


}

void calibDebug() {
  Serial.print("micMax: ");
  Serial.print(micMax);
  Serial.print('\t');

  Serial.print("micMin: ");
  Serial.print(micMin);
  Serial.print('\t');

  Serial.print("micVal: ");
  Serial.print(micValue);
  Serial.print('\t');

  Serial.println();
}

