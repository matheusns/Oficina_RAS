#ifndef MOTOR_MOTOR_HPP
#define MOTOR_MOTOR_HPP

#include <mbed.h>

namespace ras
{
class Motor
{
  public:
    explicit Motor();
    virtual ~Motor();

    void moveForward();
    void moveBack();
    void stop();

    void setPinInA(PinName inA);
    void setPinInB(PinName inB);
    void setPinPwm(PinName pwm);

    void accelerate(const float accelerataion_value);
    
  private:
    DigitalOut *inA_, *inB_;
    PwmOut *pwm_;
    Serial serial_monitor_;   
};
}  //namespace ras
#endif