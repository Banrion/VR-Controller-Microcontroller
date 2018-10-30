const int numButtons = 23;

void setup() {
  for (int i=0; i<16; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  Joystick.useManualSend(true);
}


byte allButtons[numButtons];

void loop() {
  short inputValues[23] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  uint16_t i = 0;
  while(i < 20) {
    inputValues[0] = analogRead(0) + inputValues[0];
    inputValues[1] = analogRead(1) + inputValues[1];
    inputValues[2] = analogRead(2) + inputValues[2];
    inputValues[3] = analogRead(3) + inputValues[3];
    inputValues[4] = analogRead(4) + inputValues[4];
    inputValues[5] = analogRead(5) + inputValues[5];
    inputValues[6] = analogRead(6) + inputValues[6];
    inputValues[7] = analogRead(7) + inputValues[7];
    inputValues[8] = analogRead(8) + inputValues[8];
    inputValues[9] = analogRead(9) + inputValues[9];
    inputValues[10] = analogRead(10) + inputValues[10];
    inputValues[11] = analogRead(11) + inputValues[11];
    inputValues[12] = analogRead(12) + inputValues[12];
    i = i + 1;
  }
  
  uint8_t inputPercentage[23];

  for (uint8_t x = 0; x < sizeof(inputValues); x++) {
    inputPercentage[x] = (float(inputValues[x] / i)); 
  }
  
  Joystick.X(inputPercentage[0]);
  Joystick.Y(inputPercentage[1]);
  Joystick.Z(inputPercentage[2]);
  Joystick.Zrotate(inputPercentage[3]);
  Joystick.sliderLeft(inputPercentage[4]);
  Joystick.sliderRight(inputPercentage[5]);
  
  // read digital pins and use them for the buttons
  for (int i=0; i<numButtons; i++) {
    if (digitalRead(i)) {
      // when a pin reads high, the button is not pressed
      // the pullup resistor creates the "on" signal
      allButtons[i] = 0;
    } else {
      // when a pin reads low, the button is connecting to ground.
      allButtons[i] = 1;
    }
//    Joystick.button(i + 1, allButtons[i]);
  }
  
  Joystick.button(1, allButtons[14]);
  Joystick.button(2, allButtons[15]);
  Joystick.button(3, allButtons[16]);
  Joystick.button(4, allButtons[17]);
  Joystick.send_now();
  delay(1);
}
