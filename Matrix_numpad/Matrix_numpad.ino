#include "LedControl.h"
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

LedControl lc=LedControl(12,10,11,1);  // Pins: DIN,CLK,CS, # of Display connected


// Put values in arrays
byte droit1a[] =
{
   B00000000,  // First frame of invader #1
   B00001000,
   B00001100,
   B11111110,
   B11111111,
   B11111110,
   B00001100,
   B00001000
};

byte gauche1b[] =
{
   B00000000,  // First frame of invader #1
   B00010000,
   B00110000,
   B01111111,
   B11111111,
   B01111111,
   B00110000,
   B00010000
};



void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.setIntensity(0,5);  // Set intensity levels
  lc.clearDisplay(0);  // Clear Displays
  Serial.begin(9600);
}


//  Take values in Arrays and Display them
void sdroit1a()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,droit1a[i]);
  }
}

/*void sgauche1b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,gauche1b[i]);
  }
}


*/
void loop()
{
 char customKey = customKeypad.getKey();
 
 
   if (customKey="#"){
    sdroit1a();
    delay(2000);
    
} else{
    lc.clearDisplay(0);
    delay(2000);
 }
   
    
/*// Put #2 frame on both Display
if (customKey="*"){
    sgauche1b();
    
  } */
}
