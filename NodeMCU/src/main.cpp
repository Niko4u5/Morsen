#include <Arduino.h>

#define input A0 // the input pin
#define dot 100 // the time for a short signal
#define dash 200 // the time for a long signal
#define longpause 150 // the minimum pause between two characters
#define cutoff 512 // a number betwen a high and a low signal

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(input, INPUT);
}

int timesignal(){
  /* returns the time from calling this funktion untile the signal goes low */
  int start = millis(); // saves the curent time into start

  while (analogRead(A0) > cutoff){} // waits until the signal is low.

  int time = millis() - start; // sets time to the time since calling this function.
  //Serial.print("Signal: ");
  //Serial.println(time);
  return time;
}

int timebreak(){
  /* returns the time from calling this funktion untile the signal goes low 
  TODO: dont wait the whole time from a long pause */
  int start = millis();

  while (analogRead(A0) < cutoff){} // waits until the signal is low.

  int time = millis() - start; // sets time to the time since calling this function.
  //Serial.print("Pause: ");
  //Serial.println(time);
  return time;
}

void timestochar(int charLength, int signal){
  //Serial.print("charLength: ");
  //Serial.println(charLength);
  //Serial.print("signal: ");
  //Serial.println(signal);

  if (charLength == 1){
    switch (signal){
      case 0:
        Serial.println('E');
        break;
      case 2:
        Serial.println('T');
        break;
    } 
  }   

  if (charLength == 2)
  {
    switch (signal)
    {
    case 0:
      Serial.println('I');
      break;
    case 2:
      Serial.println('A');
      break;
    case 4:
      Serial.println('N');  
      break;
    case 6:
      Serial.println('M');
      break;
    }
  }

  if (charLength == 3)
  {
    switch (signal)
    {
    case 0:
      Serial.println('S');
      break;
    case 2:
      Serial.println('U');
      break;
    case 4:
      Serial.println('R');
      break;
    case 6:
      Serial.println('W');
      break;
    case 8:
      Serial.println('D');
      break;
    case 10:
      Serial.println('K');
      break;
    case 12:
      Serial.println('G');
      break;
    case 14:
      Serial.println('O');
      break;
    }
  }
  if (charLength == 4){
    switch (signal)
    {
    case 0:
      Serial.println('H');
      break;
    case 2:
      Serial.println('V');
      break;
    case 4:
      Serial.println('F');
      break;
    case 8:
      Serial.println('L');
      break;
    case 12:
      Serial.println('P');
      break;
    case 14:
      Serial.println('J');
      break;
    case 16:
      Serial.println('B');
      break;
    case 18:
      Serial.println('X');
      break;
    case 20:
      Serial.println('C');
      break; 
    case 22:
      Serial.println('Y');
      break;
    case 24:
      Serial.println('Z');
      break;
    case 26:
      Serial.println('Q');
      break;
    }
  }
}

void recievechar(){
  int time = 0;
  int signal = 0;
  int charlength = 0;

  timebreak();
  do{
    time = timesignal();

    if (time < (dot+dash)/2)
      {
        Serial.print("•");
        bitWrite(signal,0,0);
      }
    else if (time > (dot+dash)/2)
      {
        Serial.print("-");
        bitWrite(signal,0,1);
      }
    
    signal = signal << 1;
    charlength++;
    
  }while (timebreak() < longpause);

  timestochar(charlength, signal);
}

void loop() {
  // put your main code here, to run repeatedly:
   recievechar();
}
