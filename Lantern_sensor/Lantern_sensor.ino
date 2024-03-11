#include <FastLED.h>
int state=0;
int trigger=0;
CRGB leds[1];
uint8_t hue;
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, 3>(leds, 1);
pinMode(13,OUTPUT);
pinMode(12,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(trigger>0){
    trigger--;
    state=1-state;
    leds[0]=CHSV(hue++,0,255*state); 
  FastLED.show();
    delay(30);
  }
    else{  
  state=digitalRead(12);
  trigger=(1-state)*256;
digitalWrite(13, state);  
leds[0]=CHSV(hue++,255,255*state); 
FastLED.show();
  // Send the updated pixel colors to the hardware.

    delay(100);}
}
