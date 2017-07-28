
// ùANDREA GIUSTI //

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Swimmer.h>

//#define PAUSA_SERIE 30000
unsigned int PAUSA_SERIE = 0;


Adafruit_NeoPixel * strip = new Adafruit_NeoPixel(110, 30, NEO_GRB + NEO_KHZ800);
//classe Swimmer oggetto s  (numero led Segmento=3,posizione=0,step=1,r,g,b,totVasche,totRip,totSerie)
Swimmer s  (5, 0, 1, 255, 0, 0, 4, 3, 2);
Swimmer s2 (5, 0, 1, 0, 255, 0, 4,3, 2);
Swimmer s3 (5, 0, 1, 0, 0, 255, 4, 3, 2);
unsigned long timer1, timer2, timer3, start1, start2, start3 ;
bool is_terminated1 = false;
/*  bool firstTime = false; //è la prima volta che parte
*/
/// ciao
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
  /*firstTime = true;
*/
  PAUSA_SERIE = 1000;
}

void loop(){
  if (millis()-timer1 >15 && (millis() - start1) > PAUSA_SERIE && !is_terminated1){ // 20 è la velocità di scorrimento//
/*qando arriva alla fine della rip passa per la riga 52 o 81 del .cpp
quindi passa per la riga 52 del main.cpp start1 diventa grande start1 = millis()-PAUSA_SERIE
bisogna SOMMARE a millis PAUSA_SERIE
*/
    s.autoStep(true);
    timer1 = millis();
  }
/*  if (millis()-timer2 > 40 && millis() - start2 > 2000){
    s2.autoStep(true);
    timer2 = millis();

  }
  if (millis()-timer3 >40 && millis() - start3 > 3000){
    s3.autoStep(true);
    timer3 = millis();

  }
*/
  Swimmer::show();
  //Singola serie finita.
  if (s.isFinishSerie()){
    s.resetSerie();
    start1 = millis();
    PAUSA_SERIE = 15000;

  }
  if (s.isFinishSerieTot()){
    s.resetSerieTot();
    is_terminated1 = true;
  }

}
