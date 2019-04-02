#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int redLED = 12;  //initialize all pin on vest and the Ir sensor
int blueLED = 9;
int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTTON_1 0x18E758A7 // define the button ir code in hexadecimal
#define BUTTON_2 0xFF18E7
void setup()
{
  pinMode(redLED, OUTPUT);  //set the pinmode of the led and start the serial monitor and sensor
  pinMode(blueLED, OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600);
  digitalWrite(blueLED, HIGH);
}
void loop() {

  if(irrecv.decode(&results)){  //if the sensor see something
  
    Serial.print(results.value, HEX); //print the value in hexadecimal value
    if (results.value == BUTTON_1)  // if someone shoot you then:
    {
      Serial.print(results.value, HEX);
     digitalWrite(blueLED, LOW); // make the two led flash
    
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
      Serial.print("Rien"); //else print RIEN
      }
    
    irrecv.resume();  // Restart the sensor
  }
  }
