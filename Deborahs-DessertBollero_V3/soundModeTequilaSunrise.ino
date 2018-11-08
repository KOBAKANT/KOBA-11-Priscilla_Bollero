////////////////////////////////////////////////////////
// SOUND MODE TEQUILA SUNRISE
////////////////////////////////////////////////////////

void soundModeTequilaSunrise(int vol) {

  int y_R = 255;
  int y_G = 200;
  int y_B = 30;
  int r_R = 226;
  int r_G = 0;
  int r_B = 64;

  int R;
  int G;
  int B;


  vol=map(vol,micMin,micMax,0,255);
  vol=constrain(vol,0,255);

  mix = mix + mixadd;
  
  if (mix >= 1.0 || mix <= 0.0) {
    mixadd = -mixadd;
  }

  for (int i = 0; i < 4; i++) {
    int temp = (int)(mix*100) + 25*i;
    temp=temp%100;
    float imix = (float)temp/100.0;
    imix = constrain(imix, 0.0, 1.0);
    
    R =(int)((y_R-r_R)*imix+r_R);
    G=(int)((y_G-r_G)*imix+r_G);
    B=(int)((y_B-r_B)*imix+r_B);

    strip.setPixelColor(i, strip.Color(R, G, B));
    strip.setPixelColor(i + 4, strip.Color(R, G, B));
  }
  strip.setBrightness(vol);

  strip.show();
  delay(10);


}

