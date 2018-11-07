////////////////////////////////////////////////////////
// SOUND MODE FADE
////////////////////////////////////////////////////////

void soundModeFade() {

for (int i = 0; i < 4; i++) {
        strip.setPixelColor(i, fadecolor1);              
      }
      for (int i = 4; i < 8; i++) {
        strip.setPixelColor(i, fadecolor2);              
      }

if (micValue > micThreshold)
  {   
     for (int i = 255; i >0; i=i-5) {
  strip.setBrightness(i); 
    strip.show();
    delay(20);
  }
delay(100);
  }

  

      

}
