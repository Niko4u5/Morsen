#include <Arduino.h>

int eingang = A0;
int sensorWert = 0;

#define dot 100
#define dash 200
#define pause 100

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(eingang);
}