
#include <Wire.h>

// Motor pin assignment
int MotorRight1 = 5; //IN1 PWM enabled
int MotorLeft1 = 10; //IN3 PWM enabled

int counter = 0;

//Initialise bluetooth
unsigned char bluetooth_val;
void Bluetooth_Control()
{
  while (bluetooth_val != 'E')
  {
    if (Serial.available())
    {
     bluetooth_val = Serial.read();
      switch (bluetooth_val)
      {
        case '8': advance(5); 
          break;
        case '2': back(2);   
          break;
        case '5': left(5);  
          break;
        case '6': right(5); 
          break;
        case '1': stopp(1);  
          break;
        default: stopp('1');
          break;
      }
    }
  }
  stopp(1);
}

void setup()
{
  Serial.begin(9600);
  pinMode(MotorRight1, OUTPUT);  
  pinMode(MotorLeft1,  OUTPUT);  
 
}

void advance(int a) //Forward
{
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorLeft1, HIGH);
  delay(a * 100);
}
void right(int b) //Turn right
{
  digitalWrite(MotorLeft1, HIGH);
  digitalWrite(MotorRight1, LOW);
  delay(b * 100);
}
void left(int c) //Turn left
{
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorLeft1, HIGH);
  delay(c * 100);
}

void stopp(int f) //stop
{
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorLeft1, LOW);
  delay(f * 100);
}
void back(int g) //Back
{
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorLeft1, HIGH);
  delay(g * 100);
}

void loop()
{
  if (Serial.available()) //If bluetooth connection is available
  {
    bluetooth_val = Serial.read();// start to read the first char
    if (bluetooth_val == 'b') 
    {
      Bluetooth_Control();
    }// if read in 'b' then begin bluetooth control    
  }
}
