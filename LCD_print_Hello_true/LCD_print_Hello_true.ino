/* material: - Arduino or Genuino Board
- LCD Screen (compatible with Hitachi HD44780 driver)
- Pin headers to solder to the LCD display pins
- 10k ohm potentiometer
- 220 ohm resistor
- hook-up wires
- breadboard
 */
 /*Circuit
 button pin = 7 and put a resistor of 10kohm
Before wiring the LCD screen to your Arduino or Genuino board
we suggest to solder a pin header strip to the 14 (or 16)
pin count connector of the LCD screen.
To wire your LCD screen to your board,
connect the following pins:

LCD VSS pin to Arduino GND
LCD VDD pin to Arduino 5V
LCD RS pin to digital pin 12
LCD RW pin to Arduino GND
LCD Enable pin to digital pin 11
LCD D4 pin to digital pin 5
LCD D5 pin to digital pin 4
LCD D6 pin to digital pin 3
LCD D7 pin to digital pin 2
Additionally, wire a 10k pot to +5V and GND, 
with it's wiper (output) to LCD screens VO pin (pin3).
A 220 ohm resistor is used to power the backlight of the display,
usually on pin 15 (A+) and 16 (K-) of the LCD connector.
  */
// include the library code:
#include<Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

int WhichScreen =1;   // This variable stores the current Screen number
boolean hasChanged = true;
const int buttonPin = 7;    // the number of the pushbutton pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
 
void setup()
{
  lcd.begin( 20, 4);// initialize the lcd
  
  pinMode(buttonPin, INPUT);
   
}
void loop()
{
 
  if (hasChanged == true) {
   
  switch(WhichScreen) {
    case 1:
    {
      firstScreen();
    }
      break;
   
    case 2:
      {
        secondScreen();
      }
      break;
   
    case 3:
      {
        thirdScreen();
      }
      break;
   
    case 4:
      {
        fourthScreen();
      }
      break;
   
    case 5:
      {
        fifthScreen();
      }
      break;
   
    case 6:
      {
        sixthScreen();
      }
      break;
    case 0:
      {
       
      }
      break;
    }
}
 
    //-------------------------------
    // BEGIN of the switch debouncing code
    int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
 
if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
 
    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
 
      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        hasChanged = true;
        WhichScreen++;
       
       
      }
    } else {
      hasChanged = false;
    }
  }
  lastButtonState = reading;
  // END of the switch Debouncing code
  // --------------------------------------
  if (WhichScreen > 6){
    WhichScreen = 1;
  }
}
 
void firstScreen()
  {
   lcd.clear();
   lcd.setCursor(3,0); // Column, line
   lcd.print("EarthTraining");
   lcd.setCursor(1,1);
   lcd.print("September 26th 2018");
   lcd.setCursor(3,2);
   lcd.print("Next Classes:");
   lcd.setCursor(2,3);
   lcd.print("Science and Tech");
  }
void secondScreen()
  {
    lcd.clear();
    lcd.setCursor(2,0); // Column, line
    lcd.print("Training to do:");
    lcd.setCursor(5,1);
    lcd.print("50 Push-Up");
    lcd.setCursor(1,2);
    lcd.print("Run 10 Kilometers");
    lcd.setCursor(5,3);
   lcd.print("50 Sit-Up");
  }
void thirdScreen()
  {
    lcd.clear();
    lcd.setCursor(2,0); // Column, line
    lcd.print("Today Schedule:");
    lcd.setCursor(6,1);
    lcd.print("English");
    lcd.setCursor(6,2);
    lcd.print("Science");
    lcd.setCursor(6,3);
    lcd.print("Sports");
  }
void fourthScreen()
  {
    lcd.clear();
    lcd.setCursor(5,0); // Column, line
    lcd.print("Homework:");
    lcd.setCursor(7,1);
    lcd.print("To Do:");
    lcd.setCursor(6,2);
    lcd.print("English");
    lcd.setCursor(4,3);
    lcd.print("Presentation");
  }
void fifthScreen()
  {
    lcd.clear();
    lcd.setCursor(6,0); // Column, line
    lcd.print("Options");
    lcd.setCursor(0,1);
    lcd.print("--------------------");
    lcd.setCursor(6,2);
    lcd.print("Settings");
    lcd.setCursor(0,3);
    lcd.print("--------------------");
  }
void sixthScreen()
  {
    lcd.clear();
    lcd.setCursor(2,0); // Column, line
    lcd.print("Project made by:");
    lcd.setCursor(4,1);
    lcd.print("Zacharie Roy");
    lcd.setCursor(8,2);
    lcd.print("And");
    lcd.setCursor(3,3);
    lcd.print("Anselme Poher");
  }
