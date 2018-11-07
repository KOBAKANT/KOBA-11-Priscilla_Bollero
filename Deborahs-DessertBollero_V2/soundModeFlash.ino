////////////////////////////////////////////////////////
// SOUND MODE FLASH
////////////////////////////////////////////////////////

void soundModeFlash() {


  if (micValue > micThreshold)
  {
    int currentPixel= random(4);
    int currentColor= random(4);
    intensityMax=255;
    strip.setPixelColor(currentPixel,randomColor[currentColor]);
    strip.setPixelColor(currentPixel+4,randomColor[currentColor]);
    strip.setBrightness(intensityMax);
    strip.show();
  }
//
//intensityMax=intensityMax-10;
//intensityMax=constrain(intensityMax,0,255);
//    strip.setBrightness(intensityMax);
//    strip.show();
delay (100);
            for (int i = 0; i < 8; i++) {
        strip.setPixelColor(i, off);
      }
      strip.show();
}
