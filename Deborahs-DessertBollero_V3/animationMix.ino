// ANIMATION MIX
////////////////////////////////////////////////////////
void animationMix(int vol, int mMin, int mMax){


  int R_1=249; 
  int G_1=77; 
  int B_1=22; 
  int R_2=22;
  int G_2=249; 
  int B_2=195;
  int R_3=15;
  int G_3=149;
  int B_3=122; 

  int R;
  int G;
  int B;

strip.setBrightness(255);

int t = map(vol, mMin, mMax, 0 , 100 );
float intensity=constrain((float)(t / 100.0), 0.0, 1.0);

// calculate the color witn intensity change
  R = (int)(R_2-R_1)*intensity + R_1;
  G = (int)(G_2-G_1)*intensity+ G_1;
  B = (int)(B_2-B_1)*intensity + B_1;

// make sure it stays within the range
  R=constrain(R,0,255);
  G=constrain(G,0,255);
  B=constrain(B,0,255);

// first 4 pixels animage between color 1 and color2
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, strip.Color(R, G, B));
  }

  R = (int)(R_3-R_1)*intensity + R_1;
  G = (int)(G_3-G_1)*intensity + G_1;
  B = (int)(B_3-B_1)*intensity + B_1;

  R=constrain(R,0,255);
  G=constrain(G,0,255);
  B=constrain(B,0,255);

// next 4 pixels animage between color 1 and color3
  for (int i = 4; i < 8; i++) {
    strip.setPixelColor(i, strip.Color(R, G, B));
  }

  strip.show();

  delay(10);

}
