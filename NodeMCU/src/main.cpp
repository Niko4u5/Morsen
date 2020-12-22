#include <Arduino.h>

int input = A0;
int lastInput;

unsigned long start;
unsigned long time;

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
  
  if (input <512 && lastInput > 512)
  {
    lastInput = input;
    time = millis() - start; 
  }
  
   if (time == dot)
  {
    Serial.print("•");
  }
   else if (time == dash)
   {
     Serial.print("-");
   }
   
}

void timesbreak(){
  if (input < 512 && lastInput > 512){
    start = millis();
    lastInput = input;
  }
  
  if (input > 512 && lastInput < 512)
  {
    lastInput = input;
    time = millis() - start;
  }
  
}

void timestochar(){
  
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.println(input);
}