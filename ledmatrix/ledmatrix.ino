#include "LedControl.h"





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

byte bottom_right_eye[] = { 
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B11111111,
  B11110011,
  B01110010,
  B00111100};


byte bottom_left_eye[] = { 
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B11111111,
  B11001111,
  B01001110,
  B00111100};


byte top_right_eye[] = { 
  B00111100,
  B01110010,
  B11110011,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100};

byte top_left_eye[] = { 
  B00111100,
  B01001110,
  B11001111,
  B11111111,
  B11111111,
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

byte top_eye[] = { 
  B00111100,
  B01100110,
  B11100111,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100};

byte bottom_eye[] = { 
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B11111111,
  B11100111,
  B01100110,
  B00111100};

void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.setIntensity(0,5);  // Set intensity levels
  lc.clearDisplay(0);  // Clear Displays
  Serial.begin(9600);
}


//  Take values in Arrays and Display them
void basiceye_void()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,basic_eye[i]);
  }
}

void bottom_right_eye_void()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,bottom_right_eye[i]);
  }
}
void bottom_left_eye_void()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,bottom_left_eye[i]);
  }
}
void top_right_eye_void()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,top_right_eye[i]);
  }
}
void top_left_eye_void()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,top_left_eye[i]);
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
void top_eye_void()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,top_eye[i]);
  }
}
void bottom_eye_void()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,bottom_eye[i]);
  }
}


void loop()
{

   left_eye_void();
   delay(100);
   top_left_eye_void();
   delay(100);
   top_eye_void();
   delay(100);
   top_right_eye_void();
   delay(100);
   right_eye_void();
   delay(100);
   bottom_right_eye_void();
   delay(100);
   bottom_eye_void();
   delay(100);
   bottom_left_eye_void();
   delay(100);
  }
