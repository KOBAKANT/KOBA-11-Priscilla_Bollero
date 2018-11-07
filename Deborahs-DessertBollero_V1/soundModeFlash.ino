////////////////////////////////////////////////////////
// SOUND MODE FLASH
////////////////////////////////////////////////////////

void soundModeFlash() {

for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, off);
    }

  micValue = analogRead(micPin);
  if (micValue > micThreshold)
  {
    strip.setPixelColor(random(strip.numPixels()), Wheel(random(255)));
    strip.show();
    delay(100);
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, off);
    }
    strip.show();

    //Serial.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
  }

  else {
    strip.setPixelColor(0, off);
    strip.show();
  }
}
