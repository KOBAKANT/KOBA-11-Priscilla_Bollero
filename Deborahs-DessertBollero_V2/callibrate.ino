void callibrateMIC(long callibrateDuration, float  thresholdPercent) {

  Serial.print("Now in CALLIBRATION mode for ");
  Serial.print(callibrateDuration);
  Serial.println(" cycles...");

 strip.setBrightness(50);
          for (int i = 0; i < 8; i++) {
        strip.setPixelColor(i, off);
      }

      strip.show();
      
  micMax = 0;
  micMin = 1023;
 

  delay(1000);

  long callibrateStart = millis();
  avg=analogRead(micPin);



  while ((millis() - callibrateStart ) < callibrateDuration) {
    
    micValue = analogRead(micPin);
    avg=(avg*(sampleSize-1)+micValue)/sampleSize;
    micValue=avg;
    
    if(micValue < micMin) micMin = micValue;
    if (micValue > micMax) micMax = micValue;

long duration = millis() - callibrateStart;
int indicatorNum=map(duration,0,callibrateDuration,0,4);
indicatorNum=constrain(indicatorNum,0,3);

Serial.print("micMax: ");
  Serial.print(micMax);
  Serial.print('\t');

  Serial.print("micMin: ");
  Serial.print(micMin);
  Serial.print('\t');

Serial.print("micVal: ");
  Serial.print(micValue);
  Serial.print('\t');
  
  Serial.println();

                        for (int i = 0; i < 8; i++) {
        strip.setPixelColor(i, off);
      }
        strip.setPixelColor(indicatorNum, blue);
        strip.show();

        
  }
  
micThreshold = ((micMax - micMin) * thresholdPercent)+ micMin;
 
  
  Serial.println(micThreshold);
  Serial.println("DONE CALLIBRATION");

  // end callibration:
  mode = 1;

  

}
