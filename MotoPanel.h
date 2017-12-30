//============================================================================
// Name        : MotoPanel.h
// Author      : Greg Green <gpgreen@gmail.com>
// Version     : 1.0
// Copyright   : GPL v3
// Description : Display values on LCD for motorcycle gauge
//============================================================================

#ifndef MOTOPANEL_H_
#define MOTOPANEL_H_

#include <Adafruit_GFX.h>

class MotoPanel
{
public:
    enum Mode {NORMAL, SECONDARY};
    
    explicit MotoPanel(Adafruit_GFX& display);

    // initialize beginning state
    void begin(int rpm_range, int start_mileage);

    // send values to panel to draw
    void setSpeed(int spd);
    void setMileage(int mileage);
    void setTrip1Mileage(int mileage);
    void setTrip2Mileage(int mileage);
    void setRPM(int rpm);
    void setVoltage(float v);
    
    // called once each loop
    // returns true if panel needs a display update, false if not
    bool loopUpdate();

    // called when the button is pressed and released
    void buttonPressed();

    // called when the button is long-pressed and released
    void buttonLongPressed();
    
private:
    void drawSpeed();
    void drawMileageCore(int mileage, int len);
    void drawMileage();
    void drawTrip1Mileage();
    void drawTrip2Mileage();
    void drawRPM();
    void drawVoltage();

    Adafruit_GFX& _display;
    Mode _mode;
    int _last_speed;
    int _last_mileage;
    int _trip1_mileage;
    int _trip2_mileage;
    int _last_rpm;
    float _last_volt;
    int _rpm_range;
    bool _update_display;
};

#endif /* MOTOPANEL_H_ */
