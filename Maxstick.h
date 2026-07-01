#ifndef MAXSTICK_H
#define MAXSTICK_H

#include <Arduino.h>

class Maxstick {
public:
  int xPin, yPin, swPin;
  bool left, right, forward, backward, push;
  bool active;

  Maxstick(int x, int y, int sw) {
    xPin = x;
    yPin = y;
    swPin = sw;
    active = false;
    left = right = forward = backward = push = false;
  }

  void start() {
    pinMode(swPin, INPUT_PULLUP);
    active = true;
  }

  void end() {
    active = false;
    left = right = forward = backward = push = false;
  }

  void update() {
    if (!active) return;

    int xVal = analogRead(xPin);
    int yVal = analogRead(yPin);
    int swVal = digitalRead(swPin);

    // Deadzone for noise reduction
    const int mid = 512;
    const int deadzone = 80;

    left = (xVal < mid - deadzone);
    right = (xVal > mid + deadzone);
    backward = (yVal < mid - deadzone);
    forward = (yVal > mid + deadzone);
    push = (swVal == LOW);
  }
};

#endif
