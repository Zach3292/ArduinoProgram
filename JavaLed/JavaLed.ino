#include <FastLED.h>
#define NUM_LEDS    150
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
#define LED_PIN 3

   int startindex = 0;   
   int bright = 64;
   int speedw = 3;
   int barlength = 1;
   String current;
   int RECV_PIN = 11;
   
CRGBPalette16 currentPalette;
TBlendType    currentBlending;


void setup() {
   delay( 1000 ); // power-up safety delay
   FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
   FastLED.setBrightness(bright);
   BlackPalette();
   current = (" Rainbow ");
   currentBlending = LINEARBLEND;
   Serial.begin (9600);
  Serial.setTimeout(50);

   
}

void loop()
{
  
   FillLEDsFromPaletteColors(startindex); //Fills the LED array
   startindex = startindex + speedw; //Controls the speed of pattern
   changePalette();//Changes the pattern colors
   ShowLED ();  //Displays the LED array
   
}   

void changePalette() { //Changes pattern color based on IR signal
  String text = Serial.readString();
  if(text.length() > 0){
   if (text=="Cyan") {
    CyanPalette();
     current = "Cyan";
   }
    if (text=="Blue") {
    BluePalette();
     current = "Blue";
   }

   if (text=="Green") {
    GreenPalette();
     current = "Green";
   }
    if (text=="Yellow") {
    YellowPalette();
     current = "Yellow";
   }
    if (text=="Orange") {
    OrangePalette();
     current = "Orange";
   }
    if (text=="Red") {
    RedPalette();
     current = "Red";
   }
    if (text=="Pink") {
    PinkPalette();
     current = "Pink";
   }
   if (text=="Purple") {
    PurplePalette();
     current = "Purple";
   }
    if (text=="Black") {
    BlackPalette();
     current = "Black";
   }
    
 }
}


void ShowLED (){  //Displays the current pattern
   FastLED.setBrightness( bright ); //Controls brightness globally
   FastLED.show();
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
   uint8_t brightness = 255;
   for( int i = 0; i < NUM_LEDS; i++) { //selects which LED to fill
       leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
       colorIndex = colorIndex - barlength; }
}


//This creates a pattern of one solid color, that has the option of being changed
void YellowPalette()
{
   // 'black out' all 16 palette entries...
   fill_solid( currentPalette, 16, CRGB::Yellow);
   
}
void BluePalette()
{
   // 'black out' all 16 palette entries...
   fill_solid( currentPalette, 16, CRGB::Blue);
   
}

void GreenPalette()
{
   // 'black out' all 16 palette entries...
   fill_solid( currentPalette, 16, CRGB::Green);
   
}
void OrangePalette()
{
   // 'black out' all 16 palette entries...
   fill_solid( currentPalette, 16, CRGB::Orange);
   
}
void RedPalette()
{
   // 'black out' all 16 palette entries...
   fill_solid( currentPalette, 16, CRGB::Red);
   
}
void PinkPalette()
{
   // 'black out' all 16 palette entries...
   fill_solid( currentPalette, 16, CRGB::Pink);
   
}
void PurplePalette()
{
   // 'black out' all 16 palette entries...
   fill_solid( currentPalette, 16, CRGB::Purple);
   
}
void CyanPalette()
{
   // 'black out' all 16 palette entries...
   fill_solid( currentPalette, 16, CRGB::Cyan);
   
}
void BlackPalette()
{
   // 'black out' all 16 palette entries...
   fill_solid( currentPalette, 16, CRGB::Black);
   
}
