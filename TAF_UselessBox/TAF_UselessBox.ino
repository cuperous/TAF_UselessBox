#include "Servo.h"

int servo_pin_lid = D8;  // for ESP8266 microcontroller
int servo_pin_arm = D0;  // for ESP8266 microcontroller

Servo myservolid;
Servo myservoarm;
int angle = 5;  
int randomNumber;

void setup() 
{
  myservoarm.attach(servo_pin_arm, 500, 2400);
  pinMode(D5, INPUT);
  myservoarm.write(30);
  delay(1000);
}

void loop() 
{
   if ((digitalRead(D5)== LOW)) {
     randomNumber=random(500);
      if(randomNumber > 250)
        moveArmFast();
      else
        moveArmSlow();
  } 
}

void moveArmSlow()
{
  for(int i=30;i<160;i++)
  {
      myservoarm.write(i);
      delay(10);
  }
  delay(1000);
  for(int i=140;i>30;i--)
  {
      myservoarm.write(i);
      delay(10);
  }
}

void moveArmFast()
{
  delay(5000);
  myservoarm.write(160);
  delay(1000);
  myservoarm.write(30);
  delay(1000);
}
