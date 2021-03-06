#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

// the first pin of the 5 sequential pins connected to buttons


// the first pin of the 5 sequential pins connected to buttons



int buttonPin = 12;  //buttonpin pourrait s’appeler bouton_yeux. À vous de choisir.
int LED = 13;    //Même chose ici. Au lieu de LED, on pourrait dire oeil_gauche.
IRsend irsend;
void setup() {
 Serial.begin(9600);
   // Definir le port #12 comme une entrée (capteur) et activer la résistance interne.
   pinMode(buttonPin, INPUT_PULLUP);  // Si vous avez changé le nom de buttonpin plus haut, utiliser le même nom ici
   // Définir le port 13 comme une sortie. L’électricité ira vers la DEL.
   pinMode(LED, OUTPUT);
    
}
void loop(){
   // Lire la veleur de buttonpin.  La réponse sera 0 ou 1. Enfoncé ou pas.
   int buttonValue = digitalRead(buttonPin);
    
   if (buttonValue == LOW){
      // SI le bouton est enfoncé, on allume la DEL. (HIGH)
      digitalWrite(LED,HIGH);
       irsend.sendSony(0x18E758A7, 32);
                Serial.println("Sending");
                delay(15);
   } else {
      // Sinon, on étain la DEL. (LOW)
      digitalWrite(LED, LOW);
   }
}
