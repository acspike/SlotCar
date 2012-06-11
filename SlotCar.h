/*
  SlotCar.h - Library for tracking slot car lap statistics.
  Created by Aaron C Spike, June 10, 2012.
  Released into the public domain.
*/
#ifndef SlotCar_h
#define SlotCar_h

#include "WProgram.h"

class SlotCar
{
  public:
    SlotCar(int pin, int threshold);
    void start();
    void read();
    int readLevel();
    unsigned int lapCount();
    unsigned long totalTime();
    float lapTime();
    float bestTime();
    float avgTime();
  private:
    int _pin;
    int _threshold;
    boolean _over_sensor;
    int _read_level;
    unsigned long _read_time;
    unsigned long _lap_read_time;
    unsigned int _lap_count;
    unsigned long _total_time;
    unsigned long _lap_time;
    unsigned long _best_time;
};

#endif
