#include <FastLED.h>
#define LED_PIN 7
#define RED_KNOB A4
#define GREEN_KNOB A3
#define BLUE_KNOB A2
#define BRIGHTNESS A1
#define NUM_LEDS 8
int RED_VAL,BLUE_VAL,GREEN_VAL,BRIGHTNESS_VAL;
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  //LED Callibration
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5,500);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  RED_VAL = map(analogRead(RED_KNOB),0,1023,255,0);
  GREEN_VAL = map(analogRead(GREEN_KNOB),0,1023,255,0);
  BLUE_VAL = map(analogRead(BLUE_KNOB),0,1023,255,0);
  BRIGHTNESS_VAL = map(analogRead(BRIGHTNESS),0,1023,255,0);
  Serial.println(RED_VAL);
  for(int i=0;i<NUM_LEDS;i++){
    leds[i]=CRGB(RED_VAL,BLUE_VAL, GREEN_VAL);
    FastLED.setBrightness(BRIGHTNESS_VAL);
    FastLED.show();
  }
  delay(30);
}
