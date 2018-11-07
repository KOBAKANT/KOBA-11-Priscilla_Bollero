////////////////////////////////////////////////////////
// SOUND MODE TEQUILA SUNRISE
////////////////////////////////////////////////////////

void soundModeTequilaSunrise() {
strip.setBrightness(255);

  if (micValue > micThreshold)
  {
    strip.setPixelColor(random(strip.numPixels()), tequilaSunrise[random(0,2)]);
    strip.show();
    delay(10);
    strip.show();

    //Serial.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
  }

 else {
          for (int i = 0; i < 8; i++) {
        strip.setPixelColor(i, off);
      }
      strip.show();
  }
}

