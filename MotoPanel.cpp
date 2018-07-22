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
#include <Adafruit_PCD8544.h>

// The constructor
MotoPanel::MotoPanel(Adafruit_GFX& display)
    : _display(display), _mode(NORMAL),
      _last_speed(0), _last_mileage(0L), _trip1_mileage(0L), _trip2_mileage(0L),
      _last_rpm(0), _last_volt(0.0f), _last_temp(0.0f),
      _rpm_range(10),  _update_display(false)
{
    // does nothing more
}

void MotoPanel::begin(int rpm_range, unsigned long start_mileage)
{
    _rpm_range = rpm_range;
    _last_mileage = start_mileage;
}

bool MotoPanel::loopUpdate()
{
    if (_update_display) {
        _display.fillRect(0, 0, LCDWIDTH, LCDHEIGHT, WHITE);
        switch (_mode) {
        case NORMAL:
            drawSpeed();
            drawRPM();
            drawMileage();
            break;
        case SECONDARY:
            drawVoltage();
            drawTemp();
            drawTrip1Mileage();
            drawTrip2Mileage();
            break;
        };
        _update_display = false;
        return true;
    }
    return false;
}

void MotoPanel::setSpeed(int spd)
{
    if (spd == _last_speed)
        return;
    _last_speed = spd;
    if (_mode == NORMAL)
        _update_display = true;
}

void MotoPanel::drawSpeed()
{
    _display.setCursor(24, 10);
    _display.setTextColor(BLACK);
    _display.setTextSize(4);
    _display.print(_last_speed, DEC);
}

void MotoPanel::setMileage(unsigned long mileage)
{
    if (_last_mileage == mileage)
        return;
    _last_mileage = mileage;
    if (_mode == NORMAL)
        _update_display = true;
}

void MotoPanel::setTrip1Mileage(unsigned long mileage)
{
    if (_trip1_mileage == mileage)
        return;
    _trip1_mileage = mileage;
    if (_mode == SECONDARY)
        _update_display = true;
}

void MotoPanel::setTrip2Mileage(unsigned long mileage)
{
    if (_trip2_mileage == mileage)
        return;
    _trip2_mileage = mileage;
    if (_mode == SECONDARY)
        _update_display = true;
}

void MotoPanel::drawMileageCore(unsigned long mileage, int len)
{
    long tens = 1;
    for (int i=0; i<len; ++i)
        tens *= 10;

    unsigned long m = mileage;
    long digit;
    for (int i=0; i<len; ++i) {
        digit = m / tens;
        m -= digit * tens;
        _display.print(digit, DEC);
        tens /= 10;
    }
    _display.print(".");
    _display.print(m, DEC);
}

void MotoPanel::drawMileage()
{
    _display.setCursor(24, 40);
    _display.setTextColor(BLACK);
    _display.setTextSize(1);
    drawMileageCore(_last_mileage, 6);
}

void MotoPanel::drawTrip1Mileage()
{
    _display.setCursor(2, 30);
    _display.setTextColor(BLACK);
    _display.setTextSize(1);
    _display.print("  T1:");
    drawMileageCore(_trip1_mileage, 5);
}

void MotoPanel::drawTrip2Mileage()
{
    _display.setCursor(2, 40);
    _display.setTextColor(BLACK);
    _display.setTextSize(1);
    _display.print("  T2:");
    drawMileageCore(_trip2_mileage, 5);
}

void MotoPanel::setRPM(int rpm)
{
    if (_last_rpm == rpm)
        return;
    _last_rpm = rpm;
    if (_mode == NORMAL)
        _update_display = true;
}

void MotoPanel::drawRPM()
{
    int delta = _last_rpm / (_rpm_range/(47 - 12));
    int triy = 47 - delta;
    int trix = _last_rpm / (_rpm_range/10);
    _display.fillTriangle(0, 47, 0, triy, trix, triy, BLACK);
    _display.drawLine(0, triy, 0, 12, BLACK);
    _display.drawLine(0, 12, 10, 12, BLACK);
    _display.drawLine(10, 12, trix, triy, BLACK); 
  
    _display.setCursor(1, 1);
    _display.setTextColor(BLACK);
    _display.setTextSize(1);
    _display.print(_last_rpm, DEC);
}

void MotoPanel::setVoltage(float v)
{
    if (v == _last_volt)
        return;
    _last_volt = v;
    if (_mode == SECONDARY)
        _update_display = true;
}

void MotoPanel::drawVoltage()
{
    _display.setCursor(2, 10);
    _display.setTextColor(BLACK);
    _display.setTextSize(1);
    _display.print("   V:");
    _display.print(_last_volt, 1);
}

void MotoPanel::setTemp(float t)
{
    if (t == _last_temp)
        return;
    _last_temp = t;
    if (_mode == SECONDARY)
        _update_display = true;
}

void MotoPanel::drawTemp()
{
    _display.setCursor(2, 20);
    _display.setTextColor(BLACK);
    _display.setTextSize(1);
    _display.print("Temp:");
    _display.print(_last_temp, 1);
}

void MotoPanel::buttonPressed()
{
    // switch mode
    _mode = (_mode == NORMAL) ? SECONDARY : NORMAL;
    // flag for redrawing
    _update_display = true;
}

void MotoPanel::buttonLongPressed()
{
    buttonPressed();
}
