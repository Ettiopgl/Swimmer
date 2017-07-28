#ifndef SWIMMER_H
#define SWIMMER_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

//Qua bisogna fare il commento della classe.
class Swimmer{
  private:
    static Adafruit_NeoPixel * strip;
    unsigned int nLed, pos, step, r, g, b, nVasche = 1, nRipetizioni = 0, nSerie = 0, totVasche , totRip, nSerieTotRag, totSerie;
    bool isSerieRagg = false, isSerieTotRagg = false, firsTime = false;

  public:


    bool downStart = false; //parte dalla vasca di ritorno

    Swimmer(unsigned int p_nLed, unsigned int p_pos, unsigned int p_step, unsigned int p_r, unsigned int p_g, unsigned int p_b, unsigned int totvasche, unsigned int totrip, unsigned int totserie);

    unsigned int getNled();

    unsigned int getLength();

    unsigned int getPos();

    static void setStrip(Adafruit_NeoPixel * strip_new);

    static void show();

    //void lightup();

    void lightup();

    void doStep();

    void undoStep();

    void start();

    unsigned int getNvasche();

    bool isFinishSerie();

    void resetSerie();

    bool isFinishSerieTot();

    void resetSerieTot();

    void autoStep(bool autoLightUp);

    void isFirstTime(); // f. è la prima volta che parte

};

#endif
