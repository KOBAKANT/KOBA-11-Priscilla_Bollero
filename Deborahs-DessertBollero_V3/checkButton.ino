int buttonState;             // the current reading from the input pin
int lastButtonState;  // stores the state of the button (0=not pressed, 1=pressed)
int mode;
int lastMode;
long timeStamp;


int checkButton(boolean Reset) {

  // store the last state
  lastButtonState = buttonState;
  // button pin is on internal pullup, so if it is pressed, it is LOW
  // if not pressed it is HIGH
  buttonState = digitalRead(buttonPin);


  long currentTime = millis();


  // if button is pressed, and if it was previously not pressed
  if (buttonState == LOW && lastButtonState == HIGH) {

    // calculate the difference between the current time of the press and the previous press timestamp
    long diff = currentTime - timeStamp;

    //----------------------------
    // checking double click
    //----------------------------
    // if double click within 1sec, then it is mode 4 (calibration)
    if (diff > 100) {
      if (diff < 500) {
        if (mode != 4) {
          lastMode = (mode-1)%4;
          mode = 4; // calibtation mode

        }
      }
      else {
        // count the mode up
        mode++;
        // toggle between mode 0-3
        mode = mode % 4;
        // mark the time of the button press
        timeStamp = currentTime;

      }
    }

  }

  if (Reset) {
    mode = lastMode;
  }
  mode = constrain(mode, 0, 4);
  return mode;
}
