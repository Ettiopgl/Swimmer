
// ùANDREA GIUSTI //

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Swimmer.h>
#include <MsTimer2.h>
#define MCD 10
#define DEBUG 0
#define TIMER1 1

//volatile serve al compilatore per indicare che quella variabile viene gestita da una funzione "non standard".
//variabile che dice se sono passati effettivamente 10ms
volatile bool was_passed = false;
//variabile che conta i decimi di millesimo trascorsi.
volatile int cron = 0;

//Funzione che viene chiamata ogni MCD millisecondi.
void base_dei_tempi(){
  cron++;
  if (cron == TIMER1)
    was_passed = true;
}

Adafruit_NeoPixel * strip = new Adafruit_NeoPixel(110, 30, NEO_GRB + NEO_KHZ800);

Swimmer s  (5, 0, 1, 255, 0, 0, 4, 2, 2);
//Swimmer s2 (5, 0, 1, 0, 255, 0, 4 ,2, 2);
//Swimmer s3 (5, 0, 1, 0, 0, 255, 4, 2, 2);


void setup(){
  Serial.begin(115200);
  Swimmer::setStrip(strip);
  //Imposto i millesimi di secondo per chiamare base_dei_tempi.
  MsTimer2::set(MCD, base_dei_tempi);
  //Avvio la base dei tempi.
  MsTimer2::start();
}

void loop(){
  if (was_passed){
    s.autoStep(true);
    //Non sono passati più TIMER1 millisecondi.
    was_passed = false;
    cron = 0;
  }
  Swimmer::show();
  if(s.isFinishRip()){
    s.resetRip();
  }
}
