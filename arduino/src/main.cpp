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
  // outputs a long signal and a pause
  Serial.print("-"); // creates nice serial output
  digitalWrite(laser, HIGH);
  delay(dash);
  digitalWrite(laser, LOW);
  delay(pause);
}

void morsedot() {
  // outputs a short signal and a pause
  Serial.print("•");// creates nice serial output
  digitalWrite(laser, HIGH);
  delay(dot);
  digitalWrite(laser, LOW);
  delay(pause);
}

void morsepause() {
  // outputs an pause
  Serial.println();// creates nice serial output
  delay(pause);
}

void morseChar(char Input) {
  // calls the morsedot and morsedash funktions depending on the character
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
      Serial.println("Falsches Zeichen"); // Error if you trie to send a invalit character
   }
   morsepause(); // between characters the pause has to be longer
}


void morse(String Input) {
  // calles the morseChar function for each char in the input
  for (unsigned int i = 0; i < Input.length(); i++) {
    Serial.print(Input.charAt(i)); // creates nice serial output
    morseChar(Input.charAt(i));
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  morse(Serial.readString());
  Serial.println(); // creates nice serial output
}
