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
  explicit MotoPanel(Adafruit_GFX& display);

  // initialize all state
  void begin(int rpm_range);

  // send values to panel to draw
  void drawSpeed(int spd);
  void drawMileage(int mileage);
  void drawRPM(int rpm);

  // returns true if panel needs a display update, false if not
  bool update();
  
private:

  Adafruit_GFX& _display;
  int _last_speed;
  int _last_mileage;
  int _last_rpm;
  int _rpm_range;
  bool _update_display;
};

#endif /* MOTOPANEL_H_ */
