////////////////////////////////////////////////////////
// SOUND MODE TEQUILA SUNRISE
////////////////////////////////////////////////////////

void soundModeTequilaSunrise() {

  micValue = analogRead(micPin);
  if (micValue > micThreshold)
  {
    strip.setPixelColor(random(strip.numPixels()), tequilaSunrise[random(0,2)]);
    strip.show();
    delay(10);
    strip.show();

    //Serial.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
  }

  else {
    strip.setPixelColor(0, off);
    strip.show();
  }
}

