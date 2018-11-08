////////////////////////////////////////////////////////
// SOUND MODE FADE
////////////////////////////////////////////////////////

void soundModeFade(boolean trig, float acc) {

  //Color1 is (226, 98, 10);
  //Color2 is (220, 191, 73);

  int R_1 = 226;
  int G_1 = 98;
  int B_1 = 10;
  int R_2 = 220;
  int G_2 = 191;
  int B_2 = 73;
 
strip.setBrightness(255);
  if (trig){intensity=1.0;}

  intensity = intensity - acc;
  intensity = constrain(intensity, 0.0, 1.0);
  Serial.println(intensity);

  for (int i = 0; i < 4; i++) {
    R_1 = (int)R_1 * intensity;
    G_1 = (int)G_1 * intensity;
    B_1 = (int)B_1 * intensity;
    strip.setPixelColor(i, strip.Color(R_1, G_1, B_1));
  }
  for (int i = 4; i < 8; i++) {
    R_2 = (int)R_2 * intensity;
    G_2 = (int)G_2 * intensity;
    B_2 = (int)B_2 * intensity;
    strip.setPixelColor(i, strip.Color(R_2, G_2, B_2));
  }

  strip.show();
  delay(10);



}
