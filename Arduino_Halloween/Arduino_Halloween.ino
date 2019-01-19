int buttonPin = 8;  //buttonpin pourrait s’appeler bouton_yeux. À vous de choisir.
int LEDo = 9;    //Même chose ici. Au lieu de LED, on pourrait dire oeil_gauche.
int LEDd = 7;
void setup() {
   // Definir le port #12 comme une entrée (capteur) et activer la résistance interne.
   pinMode(buttonPin, INPUT_PULLUP);  // Si vous avez changé le nom de buttonpin plus haut, utiliser le même nom ici
   // Définir le port 13 comme une sortie. L’électricité ira vers la DEL.
   pinMode(LEDo, OUTPUT);
    pinMode(LEDd, OUTPUT);
}
void loop(){
   // Lire la veleur de buttonpin.  La réponse sera 0 ou 1. Enfoncé ou pas.
   int buttonValue = digitalRead(buttonPin);
   if (buttonValue == LOW){
      // SI le bouton est enfoncé, on allume la DEL. (HIGH)
      digitalWrite(LEDo,HIGH);
      digitalWrite(LEDd,HIGH);
   } else {
      // Sinon, on étain la DEL. (LOW)
      digitalWrite(LEDo, LOW);
      digitalWrite(LEDd, LOW);
   }
}
