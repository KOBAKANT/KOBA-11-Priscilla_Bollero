////////////////////////////////////////////////////////
// SOUND MODE FLASH
////////////////////////////////////////////////////////

uint32_t pink = strip.Color(255, 6, 154);
uint32_t whitish = strip.Color(215, 210, 183);
uint32_t greeny = strip.Color(194, 249, 22);
uint32_t brown = strip.Color(221, 221, 0);
uint32_t aqu = strip.Color(3, 221, 189);
uint32_t randomColor2[] = {pink,whitish,greeny,brown,aqu };

void soundModeFlash2(int vol, int thre) {

  strip.setBrightness(255);

  if (vol > thre) {
    int currentPixel = random(3);
    int currentColor = random(4);

    for (int i = 0; i < 8; i++) {
      strip.setPixelColor(i, off);
    }

    strip.setPixelColor(currentPixel, randomColor2[currentColor]);
    strip.setPixelColor(currentPixel + 4, randomColor2[currentColor]);
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
