
// ùANDREA GIUSTI //

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Swimmer.h>

Adafruit_NeoPixel * strip = new Adafruit_NeoPixel(300, 30, NEO_GRB + NEO_KHZ800);
Swimmer s (3, 0, 1, 255, 0, 0); //classe Swimmer oggetto s  (numero led Segmento=3,posizione=0,step=1,numero led=300,pin=30)
Swimmer s2 (3, 0, 1, 0, 255, 0);
Swimmer s3 (3, 0, 1, 0, 0, 255);
unsigned long timer1, timer2, timer3, start1, start2, start3 ;

void setup(){
  Serial.begin(115200);
  Serial.println("Fine setup");
  Swimmer::setStrip(strip);
  timer1 = millis();
  timer2 = timer1;
  timer3 = timer1;
  start1 = millis();
  start2 = start1;
  start3 = start1;
}

void loop(){
  if (millis()-timer1 > 500 && millis() - start1 > 1000){
    s.lightup();
    s.doStep();
    timer1 = millis();
    Swimmer::show();
  }
  if (millis()-timer2 > 500 && millis() - start2 > 2000){
    s2.lightup();
    s2.doStep();
    timer2 = millis();
    Swimmer::show();
  }
  if (millis()-timer3 > 500 && millis() - start3 > 2000){
    s3.lightup();
    s3.doStep();
    timer3 = millis();
    Swimmer::show();
  }

}
