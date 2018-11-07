void buttonMode() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    buttonPressed = false;
  }

  if (buttonPressed == false && buttonState == LOW) {
    buttonPressed = true;
    mode++;
    if (mode > 3) mode = 0;
    if (millis() - timeStamp < 200) {
      mode = 4;
    }
    Serial.println(mode);
    timeStamp = millis();
  }

  switch (mode) {

    case 0:
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, white);
      }
      strip.show();
      break;

    case 1:
      soundModeFlash();
      break;

    case 2:
      soundModeUpdate();
      //rainbow(20);
      break;

    case 3:
      soundModeTequilaSunrise();
      break;

    case 4:
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red);
      }
      strip.show();
      callibrateMIC(5000, 90);
      break;

    default:
      break;
  }
}
