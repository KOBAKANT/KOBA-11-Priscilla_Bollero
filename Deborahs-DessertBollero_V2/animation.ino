////////////////////////////////////////////////////////
// ANIMATION
////////////////////////////////////////////////////////

void animation(uint32_t animColor) {

  fadeTimer = fadeTimer + fadeStep;
  if (fadeTimer > 255) {
    fadeStep = -5;
    delay(500);
  }
  if (fadeTimer < 0) {
    fadeStep = 5;
    //delay(100);
  }

  fadeTimer = constrain(fadeTimer, 0, 255);

  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, animColor);
  }

  strip.setBrightness(fadeTimer);
  strip.show();

  delay(10);

}

void animationMix(int red1, int green1, int blue1, int red2, int green2, int blue2, int red3, int green3, int blue3) {
strip.setBrightness(255);
  fadeTimer = fadeTimer + fadeStep;
  if (fadeTimer > 255) {
    fadeStep = -1;
    delay(500);
  }
  if (fadeTimer < 0) {
    fadeStep = 1;
    delay(500);
  }

  fadeTimer = constrain(fadeTimer, 0, 255);





  int R;
  int G;
  int B;

  R = map(fadeTimer, 0, 255, red1, red2);
  G = map(fadeTimer, 0, 255, green1, green2);
  B = map(fadeTimer, 0, 255, blue1, blue2);


  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, strip.Color(R, G, B));
  }

  R = map(fadeTimer, 0, 255, red3, red1);
  G = map(fadeTimer, 0, 255, green3, green1);
  B = map(fadeTimer, 0, 255, blue3, blue1);

  for (int i = 4; i < 8; i++) {
    strip.setPixelColor(i, strip.Color(R, G, B));
  }

  strip.show();

  delay(10);

}
