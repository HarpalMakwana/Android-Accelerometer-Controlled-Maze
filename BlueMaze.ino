//BlueMaze By CaveMad
#include <Servo.h> 
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

Servo servo1;
Servo servo2;
int x,y,ax,ay;


void setup() {
  SerialBT.begin("Bluemaze");
  servo1.attach(12);                    // pin for servo X
  servo2.attach(27);                   // pin for servo Y
}

void loop(){

  while(SerialBT.available()>0)
  {
   x= SerialBT.parseInt();
   y= SerialBT.parseInt();
   
   ax= map(x,0,200,0,180);
   ay= map(y,0,200,0,180);
   
   if(SerialBT.read()=='\n')
   {
    servo1.write(ax);
    servo2.write(ay);
   }
  }
    }
