#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int redLED = 12;
int blueLED = 9;
int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTTON_1 0x18E758A7
#define BUTTON_2 0xFF18E7
void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600);
  digitalWrite(blueLED, HIGH);
}
void loop() {

  if(irrecv.decode(&results)){
  
    Serial.print(results.value, HEX);
    if (results.value == BUTTON_1)
    {
      Serial.print(results.value, HEX);
     digitalWrite(blueLED, LOW);
    
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
      digitalWrite(blueLED, HIGH);
    }
    
    else{
      Serial.print("Rien");
      }
    
    irrecv.resume();
  }
  }
