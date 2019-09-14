#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    150
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

const int trigPin = 5;
const int echoPin = 6;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input

    
}
void led_distance(int cm){
  for(int i =0; i < NUM_LEDS; i++){
  leds[i] = CRGB::Black;
  
  }
  leds[cm] = CRGB::Orange;
  leds[cm+1] = CRGB::Orange;
  leds[cm+2] = CRGB::Orange;
  leds[cm+3] = CRGB::Orange;
  FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  
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
    
    int round_distance = round(distance);

    led_distance(round_distance);
}
