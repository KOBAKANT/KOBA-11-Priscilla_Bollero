void buttonMode() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    buttonPressed = false;
  }
  long currentTime=millis();
long diff=currentTime - timeStamp;

  if (buttonPressed == false && buttonState == LOW) {
    buttonPressed = true;
    mode++;
    mode = mode%4;
    timeStamp = currentTime;
    
    
    if (diff>40 && diff < 1000) {
      mode = 4;
    }
    
    
  }

delay(10);
}
