
#define CUSTOM_SETTINGS
#define INCLUDE_SENSOR_MODULE
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
int x = 0;
int y = 0;
int z = 0;
const int FOR = 8;
const int BACK= 9;
const int LEFT = 10;
const int RIGHT = 11;


void setup() {
  //Serial.begin(2000000);     // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);    //Change this baudrate as per your bluetooth baudrate. Connect bluetooth on digital pin 2(RX) and 3(TX) for Uno/Nano and on Serial3 pins for Mega.
  pinMode(FOR, OUTPUT);
  pinMode(BACK, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  digitalWrite(FOR, LOW);
  digitalWrite(BACK, LOW);
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, LOW);
}

void loop()
{
  Dabble.processInput();    
  battery(); 
  delay(10);
}

void battery()
{
  x = Sensor.getAccelerometerXaxis(), 4;
  //y = Sensor.getAccelerometerYaxis(), 4;
  //z = Sensor.getAccelerometerZaxis(), 4;
  //Serial.print(x);
  if(GamePad.isLeftPressed())
  {
    //Serial.print("Forward");
    digitalWrite(FOR, HIGH);
  }
  else
  {
    digitalWrite(FOR, LOW);
  }
  if(GamePad.isRightPressed())
  {
    //Serial.print("Backward");
    digitalWrite(BACK, HIGH);
  }
  else
  {
    digitalWrite(BACK, LOW);
  }
  if(x < -2)
  {
    //Serial.print("Left");
    digitalWrite(LEFT, HIGH);
  }
  else
  {
    digitalWrite(LEFT, LOW);
  }
  if(x > 2)
  {
    //Serial.print("Right");
    digitalWrite(RIGHT, HIGH);
  }
  else
  {
    digitalWrite(RIGHT, LOW);
  }
  //Serial.println();
}

void mainCode()
{
  x = Sensor.getAccelerometerXaxis(), 4;
  //y = Sensor.getAccelerometerYaxis(), 4;
  //z = Sensor.getAccelerometerZaxis(), 4;
  Serial.print(x);
  if(GamePad.isLeftPressed())
  {
    Serial.print("Forward");
    digitalWrite(FOR, HIGH);
  }
  else
  {
    digitalWrite(FOR, LOW);
  }
  if(GamePad.isRightPressed())
  {
    Serial.print("Backward");
    digitalWrite(BACK, HIGH);
  }
  else
  {
      digitalWrite(BACK, LOW);
  }
  if(x < -2)
  {
    Serial.print("Left");
    digitalWrite(LEFT, HIGH);
  }
  else
  {
    digitalWrite(LEFT, LOW);
  }
  if(x > 2)
  {
    Serial.print("Right");
    digitalWrite(RIGHT, HIGH);
  }
  else
  {
    digitalWrite(RIGHT, LOW);
  }
  Serial.println();
}

void test1()
{
  digitalWrite(11,LOW);
  delay(1000);
  digitalWrite(10, LOW);
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000);
  digitalWrite(8, LOW);
  delay(1000);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(8, HIGH);
  delay(1000);
}

void test2()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
}

void test3()
{
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
}



