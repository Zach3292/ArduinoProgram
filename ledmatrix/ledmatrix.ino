#include "LedControl.h"


const int trigPin = 5;
const int echoPin = 6;

long duration;
int distance;

LedControl lc=LedControl(12,10,11,1);  // Pins: DIN,CLK,CS, # of Display connected


// Put values in arrays
byte basic_eye[] = { 
  B00111100,
  B01111110,
  B11111111,
  B11100111,
  B11100111,
  B11111111,
  B01111110,
  B00111100};



byte right_eye[] = { 
  B00111100,
  B01111110,
  B11111111,
  B11111001,
  B11111001,
  B11111111,
  B01111110,
  B00111100};

byte left_eye[] = { 
  B00111100,
  B01111110,
  B11111111,
  B10011111,
  B10011111,
  B11111111,
  B01111110,
  B00111100};

byte middle_left_eye[] = { 
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
  Serial.begin(9600);
}


//  Take values in Arrays and Display them
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


void loop()
{

    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    switch (distance)
    {
    case 10:
      left_eye_void();
      break;
    case 20:
        middle_left_eye_void();
      break;
    case 30:
      basic_eye_void();
      break;
    case 40:
      middle_right_eye_void();
      break;
    case 50:
      right_eye_void();
      break; 
    
    default:
      break;
    }
  }
