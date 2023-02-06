#include "Servo.h"

int servo_pin_lid = D8;  // for ESP8266 microcontroller
int servo_pin_arm = D0;  // for ESP8266 microcontroller

Servo myservolid;
Servo myservoarm;
int angle = 5;  
int randomNumber;
int armpark=20;
int flip_switch=140;

void setup() 
{
  myservoarm.attach(servo_pin_arm, 500, 2400);
  pinMode(D5, INPUT);
  myservoarm.write(15);
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
  for(int i=armpark;i<flip_switch;i++)
  {
      myservoarm.write(i);
      delay(10);
  }
  delay(500);
  for(int i=flip_switch;i>armpark;i--)
  {
      myservoarm.write(i);
      delay(10);
  }
}

void moveArmFast()
{
  delay(1000);
  myservoarm.write(flip_switch);
  delay(1000);
  myservoarm.write(armpark);
  delay(1000);
}
