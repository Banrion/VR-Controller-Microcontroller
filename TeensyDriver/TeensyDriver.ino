void setup() {
  for (int i=0; i<9; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  Joystick.useManualSend(true);
}
void loop() { 
  Joystick.X(analogRead(0));
  Joystick.Y(analogRead(1));
  Joystick.Z(analogRead(2));
  Joystick.Zrotate(analogRead(3));
  Joystick.sliderRight(analogRead(4));

  Joystick.send_now();
  delayMicroseconds(500);
}
