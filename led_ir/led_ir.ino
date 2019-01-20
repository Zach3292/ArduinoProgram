#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTTON_1 0xFF30CF
#define BUTTON_2 0xFF18E7
#define BUTTON_3 0xFF7A85
#define BUTTON_4 0xFF10EF
#define BUTTON_5 0xFF38CF
#define BUTTON_6 0xFF5AA5
#define BUTTON_7 0xFF42BD
#define BUTTON_8 0xFF4AB5
#define BUTTON_9 0xFF52AD

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  
  irrecv.enableIRIn();
}
void loop() {

  if (irrecv.decode(&results))
  {
    if (results.value == BUTTON_1)
    {
      setColor(148, 0, 211);  
    }
    if (results.value == BUTTON_2)
    {
     setColor(75, 0, 130);  
    }
    if (results.value == BUTTON_3)
    {
      setColor(0, 0, 255);  
    }
    if (results.value == BUTTON_4)
    {
     setColor(0, 255, 0);  
    }
    if (results.value == BUTTON_5)
    {
      setColor(255, 255, 0);  
    }
    if (results.value == BUTTON_6)
    {
      setColor(255, 127, 0);  
    }
    if (results.value == BUTTON_7)
    {
      setColor(255, 0, 0);  
    }
    if (results.value == BUTTON_8)
    {
      setColor(0, 255, 0);  
    }
    if (results.value == BUTTON_9)
    {
      setColor(0, 255, 0);  
    }
    irrecv.resume();
  }
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
