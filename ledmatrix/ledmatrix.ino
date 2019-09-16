#include "LedControl.h"

const int trigPin = 5;
const int echoPin = 6;
const int joystickPin = A0;

long duration;
int distance;
int joystickValue;

LedControl lc=LedControl(12,10,11,1);  // Pins: DIN,CLK,CS, # of Display connected

byte basic_eye[] = 
{ 
  B00111100,
  B01111110,
  B11111111,
  B11100111,
  B11100111,
  B11111111,
  B01111110,
  B00111100};



byte right_eye[] = 
{ 
  B00111100,
  B01111110,
  B11111111,
  B11111001,
  B11111001,
  B11111111,
  B01111110,
  B00111100};

byte left_eye[] = 
{ 
  B00111100,
  B01111110,
  B11111111,
  B10011111,
  B10011111,
  B11111111,
  B01111110,
  B00111100};

byte middle_left_eye[] = 
{ 
  B00111100,
  B01111110,
  B11111111,
  B11001111,
  B11001111,
  B11111111,
  B01111110,
  B00111100};

  byte middle_right_eye[] = { 
  B00111100,
  B01111110,
  B11111111,
  B11110011,
  B11110011,
  B11111111,
  B01111110,
  B00111100};



void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.setIntensity(0,5);  // Set intensity levels
  lc.clearDisplay(0);  // Clear Displays
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(joystickPin, INPUT);
  Serial.begin(9600);
}
void basic_eye_void()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,basic_eye[i]);
  }
}
void right_eye_void()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,right_eye[i]);
  }
}
void left_eye_void()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,left_eye[i]);
  }
}
void middle_left_eye_void()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,middle_left_eye[i]);
  }
}
void middle_right_eye_void()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,middle_right_eye[i]);
  }
}
void print_eye(int eye_number)
{
  switch (eye_number)
  {
  case 0:
    left_eye_void();
    break;
  case 1:
    middle_left_eye_void();
    break;
  case 2:
    basic_eye_void();
    break;
  case 3:
    middle_right_eye_void();
    break;
  case 4:
    right_eye_void();
    break;

  default:
  
    break;
  }
}
void loop()
{

    joystickValue = analogRead(joystickPin);
    int joystickValueMap = map(joystickValue, 0, 1023, 0, 4);

    Serial.println(joystickValueMap);

    //print_eye(joystickValueMap);
    print_eye(0);
    delay(100);
    print_eye(1);
    delay(100);
    print_eye(2);
    delay(100);
    print_eye(3);
    delay(100);
    print_eye(4);
    delay(100);
    print_eye(3);
    delay(100);
    print_eye(2);
    delay(100);
    print_eye(1);
    delay(100);

  }
