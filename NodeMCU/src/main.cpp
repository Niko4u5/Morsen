#include <Arduino.h>

int input = A0;
int lastInput;
int signal;
int charLength;

unsigned long start;
unsigned long time;
//unsigned long start;
//unsigned long time;

#define dot 100
#define dash 200
#define pause 100

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void timesignal(){
  if (input > 512 && lastInput < 512){
    start = millis();
    lastInput = input;
  }
  else if (input <512 && lastInput > 512)
  {
    lastInput = input;
    time = millis() - start; 
  }

  if (time == dot)
  {
    Serial.print("•");
    bitWrite(signal,0,0);
  }
  else if (time == dash)
  {
    Serial.print("-");
    bitWrite(signal,0,1);
  }
  signal << 1;
}

void timebreak(){
  if (input < 512 && lastInput > 512)
  {
    start = millis();
    lastInput = input;
  }
  else if (input > 512 && lastInput < 512)
  {
    lastInput = input;
    time = millis() - start;
  }
    
}

void recievechar(){
  for (int i = 0; time > pause; i++)
  {
    timesignal();
    timebreak();
    i =  charLength; 
  }
  timestochar();
  signal << 8;
}

void timestochar(){
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

void loop() {
  // put your main code here, to run repeatedly:
   Serial.println(input);
  recievechar(); 
}
