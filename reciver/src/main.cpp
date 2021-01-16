#include <Arduino.h>

#define input A0     // the input pin
#define dot 100      // the time for a short signal
#define dash 200     // the time for a long signal
#define pause 100    // the minimum pause between two characters
#define cutoff 100   // a number betwen a high and a low signal

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(input, INPUT_PULLUP);
}

int timesignal()
{
  /* returns the time from calling this funktion untile the signal goes low */
  unsigned long start = millis(); // saves the curent time into start

  while (analogRead(A0) < cutoff)
  {
  } // waits until the signal is low.

  int time = millis() - start; // sets time to the time since calling this function.
  //Serial.print("Signal: ");
  //Serial.println(time);
  return time;
}

int timebreak()
{
  /* returns the time from calling this funktion untile the signal goes low */
  unsigned long start = millis();

  while (analogRead(A0) > cutoff && (millis() - start) < pause * 1.5)
  {
  } // waits until the signal is low.

  int time = millis() - start; // sets time to the time since calling this function.
  //Serial.print("Pause: ");
  //Serial.println(time);
  return time;
}

char timestochar(int charLength, int signal)
{
  //Serial.print("charLength: ");
  //Serial.println(charLength);
  //Serial.print("signal: ");
  //Serial.println(signal);

  /* prints a character based on its lenght and the signal variable */

  if (charLength == 1)
  {
    switch (signal)
    {
    case 0:
      return('E');
      break;
    case 2:
      return('T');
      break;
    }
  }

  if (charLength == 2)
  {
    switch (signal)
    {
    case 0:
      return('I');
      break;
    case 2:
      return('A');
      break;
    case 4:
      return('N');
      break;
    case 6:
      return('M');
      break;
    }
  }

  if (charLength == 3)
  {
    switch (signal)
    {
    case 0:
      return('S');
      break;
    case 2:
      return('U');
      break;
    case 4:
      return('R');
      break;
    case 6:
      return('W');
      break;
    case 8:
      return('D');
      break;
    case 10:
      return('K');
      break;
    case 12:
      return('G');
      break;
    case 14:
      return('O');
      break;
    }
  }
  if (charLength == 4)
  {
    switch (signal)
    {
    case 0:
      return('H');
      break;
    case 2:
      return('V');
      break;
    case 4:
      return('F');
      break;
    case 8:
      return('L');
      break;
    case 12:
      return('P');
      break;
    case 14:
      return('J');
      break;
    case 16:
      return('B');
      break;
    case 18:
      return('X');
      break;
    case 20:
      return('C');
      break;
    case 22:
      return('Y');
      break;
    case 24:
      return('Z');
      break;
    case 26:
      return('Q');
      break;
    }
  }
  return('-');
}

void recievechar()
{
  int time = 0;
  int signal = 0;
  int charlength = 0;

  timebreak();
  do
  {
    time = timesignal();

    if (time < dot / 2)
    {
    }                                 // If the signal ist to short it does nothing
    else if (time < (dot + dash) / 2) // If the time is smaller then half of both signal lengths together
    {
      //Serial.print("•"); // it prints a dot
      bitWrite(signal, 0, 0); //  writes a 0 at the end of signal
      signal = signal << 1;   // bitshift by one to the letf
      charlength++;           // adds one to the length of the character
    }
    else if (time > (dot + dash) / 2) // If the time is bigger then half of both signal lengths together
    {
      //Serial.print("-"); // prints a dash
      bitWrite(signal, 0, 1); //  writes a 1 at the end of signal
      signal = signal << 1;   // bitshift by one to the letf
      charlength++;           // adds one to the length of the character
    }

  } while (timebreak() < pause *1.5);

  Serial.print(timestochar(charlength, signal));
}

void loop()
{
  // put your main code here, to run repeatedly:
  //Serial.println(analogRead(A0));
  recievechar();
}
