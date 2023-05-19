#define CUSTOM_SETTINGS
#define INCLUDE_SENSOR_MODULE
#define INCLUDE_GAMEPAD_MODULE

#include <Dabble.h>

int x = 0;
bool turnLeft = 0;
bool turnRight = 0;
const int FOR = 8;
const int BACK= 9;
const int LEFT = 10;
const int RIGHT = 11;


void setup() {
  Serial.begin(2000000);     // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);    //Change this baudrate as per your bluetooth baudrate. Connect bluetooth on digital pin 2(RX) and 3(TX) for Uno/Nano and on Serial3 pins for Mega.
  pinMode(FOR, OUTPUT);
  pinMode(BACK, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  //Intially all relay outputs 
  digitalWrite(FOR, LOW);
  digitalWrite(BACK, LOW);
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, LOW);
}

void loop()
{
  Dabble.processInput(); //To input signal from Dabble IPhone app
  mainCode();
  delay(20);
}

void mainCode()
{
  //Recieves tilt value based on phone accelerometer
  x = Sensor.getAccelerometerXaxis();
  Serial.print(x); //Prints x value to Serial monitor for testing purposes
  Serial.println(); 

  //Motor Forward
  if(GamePad.isLeftPressed())
  {
    Serial.print("Forward");
    digitalWrite(FOR, HIGH);
  }
  else
  {
    digitalWrite(FOR, LOW);
  }

  //Motor Backward
  if(GamePad.isRightPressed())
  {
    Serial.print("Backward");
    digitalWrite(BACK, HIGH);
  }
  else
  {
      digitalWrite(BACK, LOW);
  }
  
  //Turning Left
  if(x < -2)
  {
    Serial.print("Left");
    digitalWrite(LEFT, HIGH);
  }
  else
  {
    digitalWrite(LEFT, LOW);
  }

  //Turning Right
  if(x > 2)
  {
    Serial.print("Right");
    digitalWrite(RIGHT, HIGH);
  }
  else
  {
    digitalWrite(RIGHT, LOW);
  }
}

//Cycles through each digital output to ensure wiring is correct.
void test()
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



