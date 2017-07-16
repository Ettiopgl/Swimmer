#include "Swimmer.h"

Adafruit_NeoPixel *Swimmer::strip;

Swimmer::Swimmer(unsigned int p_nLed, unsigned int p_pos, unsigned int p_step, unsigned int p_r, unsigned int p_g, unsigned int p_b){
  nLed = p_nLed;
  step = p_step;
  r = p_r;
  g = p_g;
  b = p_b;
}

unsigned int Swimmer::getNled(){
  return nLed;
}

void Swimmer::setStrip(Adafruit_NeoPixel * strip_new){
  strip = strip_new;
  strip->begin();
  strip->clear();
  strip->show();
}

void Swimmer::show(){
  strip->show();
}

void Swimmer::doStep(){  // incrementa in avanti
  int start_neg = pos;
  if (start_neg < 0)
    start_neg = 0;
  for (int i=start_neg; i<=pos+step-1; i++){
    strip->setPixelColor(i, 0,0,0);
  }
  pos += step;
  if (pos >= strip->numPixels()-1)
    nVasche++;
}

void Swimmer::undoStep(){  // decrementa
  int finish_neg = pos+nLed-1+step;
  if (finish_neg >= strip->numPixels())
    finish_neg = strip->numPixels()-1;
  for (int i=pos+nLed-1; i<finish_neg; i++){
    strip->setPixelColor(i, 0,0,0);
  }
  pos -= step;
  if (pos <= 0)
    nVasche++;
}

//void Swimmer::lightup(){
void Swimmer::lightup(){
  if (pos+nLed <= strip->numPixels()-1){
    for (int i=pos; i<pos+nLed; i++){
      strip->setPixelColor(i, r, g, b);
    }
  }
}

unsigned int Swimmer::getNvasche(){
  return nVasche;
}

unsigned int Swimmer::getPos(){
  return pos;
}


void Swimmer::autoStep(bool autoLightUp = false){
  if(nVasche %2 == 0){    //controlla se pari
    undoStep();
  }else {
    doStep();
  }
  if (autoLightUp)
    lightup();
}

void Swimmer::checkVasche();{ //controllo numero vasche (100/25=4 vasche poi ti fermi per trecripetizioni)
if(nVasche==vasche){
  nRipetizioni++;
  start =tRecripetizioni+millis();
}

}
