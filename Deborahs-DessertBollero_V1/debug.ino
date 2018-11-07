void debugPrint() {
  Serial.print("Mode: ");
  Serial.print(mode);
  Serial.print('\t');
  
  Serial.print("buttonState: ");
  Serial.print(buttonState);
  Serial.print('\t');

Serial.print("micMax: ");
  Serial.print(micMax);
  Serial.print('\t');
  
  Serial.print("micThereshold: ");
  Serial.print(micThreshold);
  Serial.print('\t');

Serial.print("micVal: ");
  Serial.print(micValue);
  Serial.print('\t');
  
  Serial.println();
  delay(10);
}
