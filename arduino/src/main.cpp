#include <Arduino.h>

#define laser 16
#define dot 100
#define dash 200
#define pause 100

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(laser, OUTPUT);
}

void morsedash() {
  Serial.print("-");
  digitalWrite(laser, HIGH);
  delay(dash);
  digitalWrite(laser, LOW);
  delay(pause);
}

void morsedot() {
  Serial.print("•");
  digitalWrite(laser, HIGH);
  delay(dot);
  digitalWrite(laser, LOW);
  delay(pause);
}

void morsepause() {
  Serial.println();
  delay(pause);
}

void morseChar(char Input) {
  switch(Input) {
    case 'a':
      morsedot();
      morsedash();
      break;
    case 'b':
      morsedash();
      morsedot();
      morsedot();
      morsedot();
      break;
    case 'c':
      morsedash();
      morsedot();
      morsedash();
      morsedot();
      break;
    case 'd':
      morsedash();
      morsedot();
      morsedot();
      break;
    case 'e':
      morsedot();
      break;
    case 'f':
      morsedot();
      morsedot();
      morsedash();
      morsedot();
      break;
    case 'g':
      morsedash();
      morsedash();
      morsedot();
      break;
    case 'h':
      morsedot();
      morsedot();
      morsedot();
      morsedot();
      break;
    case 'i':
      morsedot();
      morsedot();
      break;
    case 'j':
      morsedot();
      morsedash();
      morsedash();
      morsedash();
      break;
    case 'k':
      morsedash();
      morsedot();
      morsedash();
      break;
    case 'l':
      morsedot();
      morsedash();
      morsedot();
      morsedot();
      break;
    case 'm':
      morsedash();
      morsedash();
      break;
    case 'n':
      morsedash();
      morsedot();
      break;
    case 'o':
      morsedash();
      morsedash();
      morsedash();
      break;
    case 'p':
      morsedot();
      morsedash();
      morsedash();
      morsedot();
      break;
    case 'q':
      morsedash();
      morsedot();
      morsedash();
      morsedash();
      break;
    case 'r':
      morsedot();
      morsedash();
      morsedot();
      break;
    case 's':
      morsedot();
      morsedot();
      morsedot();
      break;
    case 't':
      morsedash();
      break;
    case 'u':
      morsedot();
      morsedot();
      morsedash();
      break;
    case 'v':
      morsedot();
      morsedot();
      morsedot();
      morsedash();
      break;
    case 'w':
      morsedot();
      morsedash();
      morsedash();
      break;
    case 'x':
      morsedash();
      morsedot();
      morsedot();
      morsedash();
      break;
    case 'y':
      morsedash();
      morsedot();
      morsedash();
      morsedash();
      break;
    case 'z':
      morsedash();
      morsedash();
      morsedot();
      morsedot();
      break;
    default:
      Serial.println("Falsches Zeichen");
   }
   morsepause();
}


void morse(String Input) {
  for (unsigned int i = 0; i < Input.length(); i++) {
    Serial.print(Input.charAt(i));
    morseChar(Input.charAt(i));
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  morse(Serial.readString());
  Serial.println();
  delay(1000);
}
