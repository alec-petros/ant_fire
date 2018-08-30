#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
#define NUM_LEDS 150
#define DATA_PIN    6

DEFINE_GRADIENT_PALETTE( electricity_gp ) {
0  ,     0,  0,  0,
60,   255,  255,  0,   //red
180,   255,0,  0,   //bright yellow
255,   255,255,255 }; //full white

CRGBPalette16 myPal = electricity_gp;

int pos;
uint8_t gHue = 0; // rotating "base color" used by many of the patterns
bool posUp;
int spark_chance = 1;

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  uint32_t offset = 0.00;
  LEDS.setBrightness(150);
  pos = 0;
  posUp = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (posUp = true) {
    pos++;
  } else {
    pos--;
  }
  if (pos >= 255) {
    posUp = false;
  } else {
    posUp = true;
  }
  sinelon();
  FastLED.show();
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 2);
  int pos = beat16( 13 ) % 150;
  leds[pos] += ColorFromPalette(myPal, pos, 255, LINEARBLEND);
   if (random(100) <= spark_chance) {
    leds[random(NUM_LEDS)] = CRGB::White;
  }
//  leds[NUM_LEDS - pos] += ColorFromPalette(myPal, 255 - pos, 255, LINEARBLEND);
}

//void confetti() 
//{
//  // random colored speckles that blink in and fade smoothly
//  fadeToBlackBy( leds, NUM_LEDS, 20);
//  int pos = random16(NUM_LEDS);
//  int index = random16(255);
//  leds[pos] += ColorFromPalette(myPal, index, 255, LINEARBLEND);
//}
