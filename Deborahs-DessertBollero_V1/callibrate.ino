void callibrateMIC(long callibrateDuration, int thresholdPercent) {

  Serial.print("Now in CALLIBRATION mode for ");
  Serial.print(callibrateDuration);
  Serial.println(" cycles...");

  long callibrateStart = millis();

  //delay(1000);

  while ((millis() - callibrateStart ) < callibrateDuration) {
    int micValue = analogRead(micPin);
    //if(micValue < micMin) micMin = micValue;
    if (micValue > micMax) micMax = micValue;
  }
  micThreshold = micMax - (micMax / 100) * thresholdPercent;

  Serial.println("DONE CALLIBRATION");

  // end callibration:
  mode = 1;
}
