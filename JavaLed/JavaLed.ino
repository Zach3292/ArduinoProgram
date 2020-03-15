#include <FastLED.h>
#define NUM_LEDS    150
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
#define LED_PIN 3

   int startindex = 0;   
   int bright = 40;
   int speedw = 3;
   int barlength = 1;
   String text = "";
   
CRGBPalette16 currentPalette;
TBlendType currentBlending;


void setup() {
   delay( 1000 ); // power-up safety delay
   FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
   FastLED.setBrightness(bright);
   BlackPalette();
   currentBlending = LINEARBLEND;
   Serial.begin(9600);
}

void loop()
{
   FillLEDsFromPaletteColors(startindex); //Fills the LED array
   startindex = startindex + speedw; //Controls the speed of pattern
   changePalette();//Changes the pattern colors
   ShowLED();  //Displays the LED array
   
}   

void changePalette() { //Changes pattern color based on IR signal
  
    
    if(Serial.available()){
        while(text ==""){
          delay(10);
          text = Serial.readString();
          text.trim();
        }
        
      
     if (text == "Cyan") {
      CyanPalette();
      Serial.println("Cyan");
     }else if (text == "Blue") {
      BluePalette();
       Serial.println("Blue");
     }else if (text == "Green") {
      GreenPalette();
      Serial.println("Green");
     }else if (text == "Yellow") {
      YellowPalette();
      Serial.println("Yellow");
     }else if (text == "Orange") {
      OrangePalette();
      Serial.println("Orange");
     }else if (text == "Red") {
      RedPalette();
      Serial.println("Red");
     }else if (text == "Pink") {
      PinkPalette();
      Serial.println("Pink");
     }else if (text == "Purple") {
      PurplePalette();
      Serial.println("Purple");
     }else if (text == "Black") {
      BlackPalette();
      Serial.println("Black");
     }else if (text == "White") {
        WhitePalette();
      Serial.println("White");
     }
      text = "";
   }
  
}

void ShowLED(){  //Displays the current pattern
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
void WhitePalette()
{
   // 'black out' all 16 palette entries...
   fill_solid( currentPalette, 16, CRGB::White);
   
}
