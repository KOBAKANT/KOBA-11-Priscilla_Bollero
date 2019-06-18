////////////////////////////////////////////////////////
// SOUND MODE FLASH
////////////////////////////////////////////////////////
uint32_t randomColor[] = {blue, redish, greenish, orange, yellow };

void soundModeFlash(int vol, int thre) {

  strip.setBrightness(255);

  if (vol > thre) {
    int currentPixel = random(4);
    int currentColor = random(5);

    for (int i = 0; i < 8; i++) {
      strip.setPixelColor(i, off);
    }

    strip.setPixelColor(currentPixel, randomColor[currentColor]);
    strip.setPixelColor(7-currentPixel, randomColor[currentColor]);
    strip.show();
    delay(20);
  }
  else {
    // turn all of them off
    for (int i = 0; i < 8; i++) {
      strip.setPixelColor(i, off);
    }
    strip.show();
  }
}
