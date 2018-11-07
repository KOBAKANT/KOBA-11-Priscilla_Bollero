////////////////////////////////////////////////////////
// SOUND MODE UPDATE
////////////////////////////////////////////////////////

void soundModeUpdate() {

  micValue = analogRead(micPin);
  if (micValue > micThreshold)
  {
    strip.setPixelColor(random(strip.numPixels()), Wheel(random(255)));
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
