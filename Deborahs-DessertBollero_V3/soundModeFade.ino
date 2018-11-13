////////////////////////////////////////////////////////
// SOUND MODE FADE
////////////////////////////////////////////////////////

int brightness;
int fadeSpeed = 15;

void soundModeFade(int vol, int thre) {

  if (vol > thre) {
    //set the brightness to full intensity
    brightness = 255;
  }


  brightness = constrain(brightness, 0, 255);
  strip.setBrightness(brightness);

  // slowly fade out
  if (brightness > 0) {
    brightness = brightness - fadeSpeed;
  }




  for (int i = 0; i < 4; i++) {
    strip.setPixelColor(i, strip.Color(226, 98, 10));
  }
  for (int i = 4; i < 8; i++) {
    strip.setPixelColor(i, strip.Color(220, 191, 73));
  }

  strip.show();
  delay(10);



}
