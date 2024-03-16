#include <FastLED.h>
int state=0;//
int trigger=0;
int StartPin=3;
int numSensors=5;
uint8_t flicker=0;
int numLeds=60;
int colors[]={50,50,50,50,50};//color pick array
CRGB leds[2][60];
//CRGB leds[60];
uint8_t hue;
unsigned long myTime;
int shortTime;
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, 9>(leds[0], numLeds);
   FastLED.addLeds<NEOPIXEL, 10>(leds[1], numLeds);
   //FastLED.addLeds<NEOPIXEL, 9>(leds, numLeds);
pinMode(13,OUTPUT);
for(int i=0;i<numSensors;i++){
pinMode(i+StartPin,INPUT_PULLUP);
}
// for(int n=0;n<2;n++){
// for(int m=0;m<numLeds;m++){
//   leds[n][m]=0;
// }}

}



void loop() {
myTime = millis();
shortTime=(myTime/3000)%2;
  if(trigger>0){
    FastLED.clearData();
    trigger--;
    //flicker--;
    flicker=1-flicker;
    for(int n=0;n<numLeds;n++){
      leds[0][n]=CHSV(colors[state-1],255,flicker*255);}// write to pixels on strip
    //leds[n]=CHSV(state*50,255,flicker*255); }
    //digitalWrite(13, flicker);  
  FastLED.show();
    delay(100);
  }
    else{  
     state=0; 
      for(int i=0;i<numSensors;i++){

state+=(1-digitalRead(i+StartPin))*(i+1);
}
  if(state>0){ trigger=60;}
 
//digitalWrite(13, state); 
FastLED.clearData(); 
//leds[0]=CHSV(hue++,255,255); 
if(shortTime==0){
leds[1][0]=CHSV(hue++,255,255);} //write to brigh single pixel
if(shortTime==1){
leds[1][0]=CHSV(0,100,255);}
FastLED.show();
  // Send the updated pixel colors to the hardware.

    delay(20);}
}
