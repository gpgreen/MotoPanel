//============================================================================
// Name        : MotoPanel.cpp
// Author      : Greg Green <gpgreen@gmail.com>
// Version     : 1.0
// Copyright   : GPL v3
// Description : Display values on LCD for motorcycle gauge
//============================================================================

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "MotoPanel.h"

const int BLACK=1;
const int WHITE=0;

// The constructor
MotoPanel::MotoPanel(Adafruit_GFX& display)
    : _display(display), _last_speed(-1), _last_mileage(-1),
      _last_rpm(0), _rpm_range(10), _update_display(false)
{
    // does nothing more
}

void MotoPanel::begin(int rpm_range)
{
    _rpm_range = rpm_range;
}

bool MotoPanel::update()
{
    bool retval = _update_display;
    _update_display = false;
    return retval;
}

void MotoPanel::drawSpeed(int spd)
{
    if (spd == _last_speed)
	return;
    _last_speed = spd;

    // blank speed
    _display.fillRect(24, 10, 5*2*4, 10*4, WHITE);
  
    _display.setTextSize(4);
    _display.setTextColor(BLACK);
    _display.setCursor(24, 10);
    _display.print(spd, DEC);

    _update_display = true;
}

void MotoPanel::drawMileage(int mileage)
{
    if (_last_mileage == mileage)
	return;
    _last_mileage = mileage;

    // blank mileage
    _display.fillRect(24, 40, 5*8, 10, WHITE);

    _display.setTextSize(1);
    _display.setTextColor(BLACK);
    _display.setCursor(24, 40);

    int x = mileage;
    int digit = mileage / 1000000;
    x -= digit * 1000000;
    _display.print(digit, DEC);
    digit = x / 100000;
    x -= digit * 100000;
    _display.print(digit, DEC);
    digit = x / 10000;
    x -= digit * 10000;
    _display.print(digit, DEC);
    digit = x / 1000;
    x -= digit * 1000;
    _display.print(digit, DEC);
    digit = x / 100;
    x -= digit * 100;
    _display.print(digit, DEC);
    digit = x / 10;
    x -= digit * 10;
    _display.print(digit, DEC);
    _display.print(".");
    _display.print(x, DEC);

    _update_display = true;
}

void MotoPanel::drawRPM(int rpm)
{
    if (_last_rpm == rpm)
	return;
    _last_rpm = rpm;

    // blank rpm
    _display.fillRect(0, 12, 10, 47, WHITE);
    _display.fillRect(1, 1, 5*6, 10, WHITE);
  
    int delta = rpm / (_rpm_range/(47 - 12));
    int triy = 47 - delta;
    int trix = rpm / (_rpm_range/10);
    _display.fillTriangle(0, 47, 0, triy, trix, triy, BLACK);
    _display.drawLine(0, triy, 0, 12, BLACK);
    _display.drawLine(0, 12, 10, 12, BLACK);
    _display.drawLine(10, 12, trix, triy, BLACK); 
  
    _display.setTextSize(1);
    _display.setTextColor(BLACK);
    _display.setCursor(1, 1);
    _display.print(rpm, DEC);

    _update_display = true;
}

