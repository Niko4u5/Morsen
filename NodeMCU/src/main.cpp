#include <Arduino.h>

int input = A0;
int lastInput;
int signal;
int ;

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
  for (size_t i = 0; time > pause; i++)
  {
    timesignal();
    timebreak();  
  }
  timestochar();
  signal << 8;
}

void timestochar(){
 
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.println(input);
}
