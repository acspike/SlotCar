/*
  SlotCar.cpp - Library for tracking slot car lap statistics.
  Created by Aaron C Spike, June 10, 2012.
  Released into the public domain.
*/

#include "WProgram.h"
#include "SlotCar.h"

SlotCar::SlotCar(int pin, int threshold)
{
    _pin = pin;
    _threshold = threshold;
    _over_sensor = false;
    _read_level = 0;
    _lap_read_time = 0;
    _read_time = 0;
    _lap_count = 0;
    _total_time = 0;
    _lap_time = 0;
    _best_time = 4294967295;
}

void SlotCar::start()
{
    _lap_read_time = millis();
}

void SlotCar::read()
{
    _read_time = millis();
    _read_level = analogRead(_pin);
    if (_read_level > _threshold) {
        if (!_over_sensor) {
            _over_sensor = true;
            _lap_count++;
            _lap_time = _read_time - _lap_read_time;
            _lap_read_time = _read_time;
            _total_time += _lap_time;
            _best_time = min(_best_time, _lap_time);
        }
    } else {
        _over_sensor = false;
    }
}

int SlotCar::readLevel()
{
    return _read_level;
}

unsigned int SlotCar::lapCount()
{
    return _lap_count;
}

unsigned long SlotCar::totalTime()
{
    return _total_time;
}

float SlotCar::lapTime()
{
    return _lap_time / 1000.0;
}

float SlotCar::bestTime()
{
    if (_lap_count == 0) return 0.0;
    return _best_time / 1000.0;
}

float SlotCar::avgTime()
{
    if (_lap_count == 0) return 0.0;
    return (_total_time / float(_lap_count)) / 1000.0;
}



