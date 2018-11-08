void buttonMode() {

// button pin is on internal pullup, so if it is pressed, it is LOW
// if not pressed it is HIGH

  buttonState = digitalRead(buttonPin);

// if button not pressed
  if (buttonState == HIGH) {
    buttonPressed = false;
  }

  long currentTime = millis();
  // calculate the difference between the current time of the press and the previous press timestamp
  long diff = currentTime - timeStamp;

// if button is pressed, and if it was previously not pressed
  if (buttonState == LOW && buttonPressed == false) {
    // switch the state so we can compare the next time
    buttonPressed = true;

    // count the mode up
    mode++;
    // toggle between mode 0-3
    mode = mode % 4;
    // mark the time that is pressed
    timeStamp = currentTime;


// if double click within 1sec, then it is mode 4 (calibration)
    if (diff > 40 && diff < 1000) {
      mode = 4; // calibtation mode
    }

  }

  delay(10);
}
