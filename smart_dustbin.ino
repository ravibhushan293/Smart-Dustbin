#include <Servo.h>

Servo servoMain; // define our Servo
int trigpin = 4;
int echopin = 3;
int distance;
float duration;
float cm;

void setup()
{
  servoMain.attach(5);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}

void loop()
{
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  cm = (duration/58.82);
  distance = cm;

  if(distance<30)
  {
    servoMain.write(180); // Turn Servo back to center position
    delay(3000);
  }
  else
  {
    servoMain.write(0);
    delay(50);
  }
}

