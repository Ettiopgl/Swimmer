#ifndef SWIMMER_H
#define SWIMMER_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Swimmer{
  private:
    static Adafruit_NeoPixel * strip;
    unsigned int nLed, pos, step, r, g, b, nVasche = 1;

  public:

    Swimmer(unsigned int p_nLed, unsigned int p_pos, unsigned int p_step, unsigned int p_r, unsigned int p_g, unsigned int p_b);

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

    void autoStep(bool autoLightUp);

};

#endif
