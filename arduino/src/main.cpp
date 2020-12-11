#include <Arduino.h>

#define laser LED_BUILTIN
#define dot 1000
#define dash 2000
#define pause 1000

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(laser, OUTPUT);
}



void morsedash() {
  digitalWrite(laser, HIGH);
  delay(dash);
  digitalWrite(laser, LOW);
  delay(pause);
}

void morsedot() {
  digitalWrite(laser, HIGH);
  delay(dash);
  digitalWrite(laser, LOW);
  delay(pause);
}

void morse(String Input) {
  for (int i=0; i < Input.length(); i++) {
    Serial.print(Input.charAt(i));
    morseChar(Input.charAt(i));
    }
}

void morseChar(char Input) {
  switch(Input) {
    case 'a':
      morsedots("·−");
      break;
    case 'b':
      morsedots("− · · ·");
      break;
    case 'c':
      morsedots("− · − ·");
      break;
    case 'd':
      morsedots("− · ·");
      break;
    case 'e':
      morsedots("·");
      break;
    case 'f':
      morsedots("· · − ·");
      break;
    case 'g':
      morsedots("− − ·");
      break;
    case 'h':
      morsedots("· · · ·");
      break;
    case 'i':
      morsedots("· ·");
      break;
    case 'j':
      morsedots("· − − −");
      break;
    case 'k':
      morsedots("− · −");
      break;
    case 'l':
      morsedots("· − · ·");
      break;
    case 'm':
      morsedots("− −");
      break;
    case 'n':
      morsedots("− ·");
      break;
    case 'o':
      morsedots("− − −");
      break;
    case 'p':
      morsedots("· − − ·");
      break;
    case 'q':
      morsedots("− − · −");
      break;
    case 'r':
      morsedots("· − ·");
      break;
    case 's':
      morsedots("· · ·");
      break;
    case 't':
      morsedots("−");
      break;
    case 'u':
      morsedots("· · −");
      break;
    case 'v':
      morsedots("· · · −");
      break;
    case 'w':
      morsedots("· − −");
      break;
    case 'x':
      morsedots("  − · · −");
      break;
    case 'y':
      morsedots("− · − −");
      break;
    case 'z':
      morsedots("− − · ·");
      break;
    default:
      Serial.println("Falsches Zeichen");
   }
}

void loop() {
  // put your main code here, to run repeatedly:
  morse("atest");
  Serial.println();
  delay(1000);
}
