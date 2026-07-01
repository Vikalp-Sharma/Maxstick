#include <Maxstick.h>

Maxstick joystick(A1, A2, 2); // X, Y, Switch pin

void setup() {
  Serial.begin(9600);
  joystick.start();
}

void loop() {
  joystick.update();

  if (joystick.left) Serial.println("LEFT");
  if (joystick.right) Serial.println("RIGHT");
  if (joystick.forward) Serial.println("FORWARD");
  if (joystick.backward) Serial.println("BACKWARD");
  if (joystick.push) Serial.println("PUSH");

  delay(100);
}
