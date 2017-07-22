#ifndef SWIMMER_H
#define SWIMMER_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

//Qua bisogna fare il commento della classe.
class Swimmer{
  private:
    static Adafruit_NeoPixel * strip;
    unsigned int nLed, pos, step, r, g, b, nVasche = 1, nRipetizioni = 0, nSerie = 0, vascheRagg, nRipRagg=0,
      nSerieRagg;
    bool isSerieRagg = false;
  public:

    // Swimmer(Segmento,posizione,step,r,g,b,nvascheragg, nripragg,ntotripetizioni, nserieragg, ntotserie)
    Swimmer(unsigned int p_nLed, unsigned int p_pos, unsigned int p_step, unsigned int p_r, unsigned int p_g,
       unsigned int p_b, unsigned int nvascheragg, unsigned int nripragg, unsigned int nserieragg,
      unsigned int ntotvasche, unsigned int ntotripetizioni,   unsigned int ntotserie);

unsigned int nTotVasche, nTotRipetizioni, nTotSerie, pausaRip, pausaSerie; // INPUT VISIBILI DALL'ESTERNO
    unsigned int getNled();

    unsigned int getLength();

    unsigned int getPos();

    static void setStrip(Adafruit_NeoPixel * strip_new);

    static void show();

    //void lightup();

    void lightup();

    unsigned int doStep();

    unsigned int undoStep();

    void start();


    //unsigned int getNvasche(unsigned int vasche);

      unsigned int getNvasche();

    bool isFinish();

    void reset();


    void autoStep(bool autoLightUp);



//unsigned long checkVasche(unsigned int nVasche);

};

#endif
