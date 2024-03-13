#include <FastLED.h>
int state=0;
int trigger=0;
int StartPin=3;
int numSensors=5;
uint8_t flicker=0;
CRGB leds[1];
uint8_t hue;
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, 3>(leds, 1);
pinMode(13,OUTPUT);
for(int i=0;i<numSensors;i++){
pinMode(i+StartPin,INPUT_PULLUP);

}


}

void loop() {

  if(trigger>0){
    trigger--;
    flicker--;
    flicker=1-flicker;
    leds[0]=CHSV(state*50,255,flicker); 
  FastLED.show();
    delay(10);
  }
    else{  
     state=0; 
      for(int i=0;i<numSensors;i++){

state+=(1-digitalRead(i+StartPin))*(i+1);
}
  if(state>0){ trigger=2048;}
 
//digitalWrite(13, state);  
leds[0]=CHSV(hue++,255,255); 
FastLED.show();
  // Send the updated pixel colors to the hardware.

    delay(100);}
}
