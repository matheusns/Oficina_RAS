#ifndef MOTOR_MOTOR_HPP
#define MOTOR_MOTOR_HPP

#include <mbed.h>

namespace ras
{
class Motor
{
  public:
    Motor();
    ~Motor();

    void setPinControl1(PinName control1);
    void setPinControl2(PinName control2);
    void setPinPwm(PinName pwm);

    void moveForward();
    void moveBack();
    void stop();
    
  private:
    Serial serial_monitor_;   
};
}  //namespace ras
#endif