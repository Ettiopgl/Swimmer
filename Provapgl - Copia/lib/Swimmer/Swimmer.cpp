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

void Swimmer::doStep(){
  int start_neg = pos-nLed;
  if (start_neg < 0)
    start_neg = 0;
  for (int i=start_neg; i<pos; i++){
      strip->setPixelColor(i, 0,0,0);
  }
  pos += step;
}

void Swimmer::lightup(){
  if (pos+nLed <= strip->numPixels()-1){
    for (int i=pos; i<pos+nLed; i++){
        strip->setPixelColor(i, r, g, b);
    }
  }
}
