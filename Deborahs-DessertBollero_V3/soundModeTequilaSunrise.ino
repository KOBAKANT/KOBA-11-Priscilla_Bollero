////////////////////////////////////////////////////////
// SOUND MODE TEQUILA SUNRISE
////////////////////////////////////////////////////////

int mix;
int mixadd = 1;

void soundModeTequilaSunrise(int vol,int mMin, int mMax) {

  int y_R = 255;
  int y_G = 200;
  int y_B = 30;
  int r_R = 226;
  int r_G = 0;
  int r_B = 64;

  int R;
  int G;
  int B;

mMin=mMin+5;
mMax=mMax*0.8;
  vol=map(vol,mMin,mMax,0,255);
  vol=constrain(vol,0,255);
  strip.setBrightness(vol);

  mix = mix + mixadd; 
  if (mix >= 100 || mix <= 0) {
    mixadd = -mixadd;
  }

  for (int i = 0; i < 4; i++) {
    int temp = mix+ 25*i;
    temp=temp%100;
    float imix = (float)temp/100.0;
       
//    R =(int)((y_R-r_R)*imix+r_R);
//    G=(int)((y_G-r_G)*imix+r_G);
//    B=(int)((y_B-r_B)*imix+r_B);

    R =(y_R-r_R)*imix+r_R;
    G=(y_G-r_G)*imix+r_G;
    B=(y_B-r_B)*imix+r_B;

    R=constrain(R,0,255);
    G=constrain(G,0,255);
    B=constrain(B,0,255);

    strip.setPixelColor(i, strip.Color(R, G, B));
    strip.setPixelColor(7-i, strip.Color(R, G, B));
  }
  

  strip.show();
  delay(10);


}

