#include <LiquidCrystal.h>



/*
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
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int redLED = 13;
int blueLED = 9;
int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTTON_1 0x18E758A7
#define BUTTON_2 0xFF18E7
#define BUTTON_3 0xFF7A85
#define BUTTON_4 0xFF10EF
#define BUTTON_5 0xFF38CF
#define BUTTON_6 0xFF5AA5
#define BUTTON_7 0xFF42BD
#define BUTTON_8 0xFF4AB5
#define BUTTON_9 0xFF52AD


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
void setup()
{
  lcd.begin(16, 2);// initialize the lcd
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  irrecv.enableIRIn();
}
void loop() {

  if (irrecv.decode(&results))
  {
    Serial.print(results.value);
    if (results.value == BUTTON_1)
    {
     digitalWrite(blueLED, LOW);
      lcd.setCursor(0,0); // Column, line
      lcd.print("killed by");
      lcd.setCursor(0,1);
      lcd.print("Sniper");
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
      lcd.clear();
      digitalWrite(blueLED, HIGH);
    }
    if (results.value == BUTTON_2)
    {
     digitalWrite(blueLED, LOW);
      lcd.setCursor(0,0); // Column, line
      lcd.print("killed by");
      lcd.setCursor(0,1);
      lcd.print("Administrator");
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
      lcd.clear();
      digitalWrite(blueLED, HIGH);
    }
    irrecv.resume();
  }
}
