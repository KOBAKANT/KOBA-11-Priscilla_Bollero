////////////////////////////////////////////////////////
// SOUND MODE UPDATE
////////////////////////////////////////////////////////

void soundModeUpdate() {
strip.setBrightness(255);

  if (micValue > micThreshold)
  {
    strip.setPixelColor(random(strip.numPixels()), Wheel(random(255)));
    strip.show();
    delay(10);
    strip.show();

    //Serial.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
  }

 else {
 
  }
}
