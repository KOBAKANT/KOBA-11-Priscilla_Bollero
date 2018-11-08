////////////////////////////////////////////////////////
// SOUND MODE FLASH
////////////////////////////////////////////////////////

void soundModeFlash(int dulation) {

  int currentPixel = random(4);
  int currentColor = random(4);

  strip.setPixelColor(currentPixel, randomColor[currentColor]);
  strip.setPixelColor(currentPixel + 4, randomColor[currentColor]);
  strip.setBrightness(255);
  strip.show();


  delay(dulation);

  // turn all of them off
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, off);
  }
  strip.show();


}
