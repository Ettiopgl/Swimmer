
// ùANDREA GIUSTI //

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Swimmer.h>
#define DEBUG 0

unsigned int recupero = 1000;
unsigned int pausaSerie = 0;
unsigned int pausaRip = 0;

Adafruit_NeoPixel * strip = new Adafruit_NeoPixel(110, 30, NEO_GRB + NEO_KHZ800);

void debug(String s, bool new_line = true, bool enable = DEBUG){
  if (enable){
    Serial.print(s+( (new_line) ? ("\n") : ("") ));
  }
}

Swimmer s  (5, 0, 1, 255, 0, 0, 4, 2, 2);
Swimmer s2 (5, 0, 1, 0, 255, 0, 4 ,2, 2);
Swimmer s3 (5, 0, 1, 0, 0, 255, 4, 2, 2);
unsigned long timer1, timer2, timer3, start1, start2, start3 ;
bool is_terminated1 = false, is_terminated2 = false, is_terminated3 = false;


void setup(){
  Serial.begin(115200);
  Swimmer::setStrip(strip);
  timer1 = millis();
  timer2 = timer1;
  timer3 = timer1;
  start1 = millis();
  start2 = start1;
  start3 = start1;
  recupero = 0;
  pausaSerie = 0;
  pausaRip = 0;
}

void loop(){
  if (millis()-timer1 >5 && (millis() - start1) >= recupero && !is_terminated1){ // 20 è la velocità di scorrimento//
    s.autoStep(true);
    timer1 = millis();
  }
  Swimmer::show();
  //Singola serie finita.
  if(s.isFinishRip()){
    s.resetRip();
    timer1 = millis();
    start1 = timer1;
    recupero = 5000;
  }
}
