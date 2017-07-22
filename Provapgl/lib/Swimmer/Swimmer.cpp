#include "Swimmer.h"

Adafruit_NeoPixel *Swimmer::strip;

// Swimmer(Segmento,posizione,step,r,g,b, nripragg,ntotripetizioni, nserieragg, ntotserie)

Swimmer::Swimmer(unsigned int p_nLed, unsigned int p_pos, unsigned int p_step, unsigned int p_r, unsigned int p_g, unsigned int p_b, unsigned int vascheragg, unsigned int nripragg, unsigned int nserieragg, unsigned int ntotvasche, unsigned int ntotripetizioni, unsigned int ntotserie){
vascheRagg = vascheragg;
  nRipRagg = nripragg;  // PASSO AL PARAMETRO PRIVATO nRipRagg il valore di nripragg PUBBLICO
  nSerieRagg = nserieragg;
 nTotVasche = ntotvasche;
 nTotRipetizioni = ntotripetizioni;
  nTotSerie = ntotserie;
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

unsigned int  Swimmer::doStep(){  // incrementa in avanti
  int start_neg = pos;
  if (start_neg < 0)
    start_neg = 0;
  for (int i=start_neg; i<=pos+step-1; i++){
    strip->setPixelColor(i, 0,0,0);
  }
  pos += step;
  if (pos >= strip->numPixels()-1)
    //nVasche++;
    vascheRagg++;

    if (vascheRagg == nTotVasche){
//nRipetizioni++;

          nRipRagg++;
          pausaRip=15000
          return pausaRip;
          if(nRipRagg == nTotRipetizioni){
            nSerieRagg++;
            pausaSerie=60000;
            return pausaSerie;
            }
            if(nSerieRagg == nTotSerie){
              isSerieRagg =true;
            }

        //  if(nVasche ==nTotVasche){
          //        nRipetizioni++;
// return pausa ripetizioni
//if (nRipetizioni == ntotripetizioni){
//nSerie++;
//return pausa Serie
  //if (nSerie ==nTotSerie){
    //isSerieRagg = true;
    //}
//}
        //  if (nRipetizioni == nSerie){
          //  nSerie++;
        //    if (nSerie == nTotSerie){
        //      isSerieRagg = true;
          //  }

      //    }
        }


}

unsigned int Swimmer::undoStep(){  // decrementa
  int finish_neg = pos+nLed-1+step;
  if (finish_neg >= strip->numPixels())
    finish_neg = strip->numPixels()-1;
  for (int i=pos+nLed-1; i<finish_neg; i++){
    strip->setPixelColor(i, 0,0,0);
  }
  pos -= step;
  if (pos <= 0)
    vascheRagg++;

    if (vascheRagg == nTotVasche){
        nRipRagg++;
        pausaRip=15000;
        return pausaRip;
        if (nRipRagg == nTotRipetizioni){
          pausaSerie=60000;
          nSerieRagg++;
          if (nSerieRagg == nTotSerie){
            isSerieRagg = true;
          }

        }
      }

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

bool Swimmer::isFinish(){
  return isSerieRagg;
}

void Swimmer::autoStep(bool autoLightUp = false){

  //if(nVasche %2 == 0){    //controlla se pari
if(nvascheRagg %2 ==0){
    undoStep();
  }else {
    doStep();
  }
  if (autoLightUp)
    lightup();
}



void Swimmer::reset(){
  nVasche = 1;
  nRipetizioni = 0;
  nSerie = 0;
  isSerieRagg = false;
}
