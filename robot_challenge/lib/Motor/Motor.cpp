#include <Motor.hpp>

namespace ras
{
Motor::Motor()
    : serial_monitor_(USBTX, USBRX)
    , inA_(NULL)    
    , inB_(NULL)
    , pwm_(NULL)
{

}
Motor::~Motor()
{
    if (inB_ != NULL) delete inB_; 
    if (inA_ != NULL) delete inA_; 
    if (pwm_ != NULL) delete pwm_; 
}

void Motor::moveForward()
{
    if (inB_ != NULL && inA_ != NULL)
    {
        *inA_ = 1;    
        *inB_ = 0;
    }
}

void Motor::moveBack()
{
    if (inB_ != NULL && inA_ != NULL)
    {
        *inA_ = 0;    
        *inB_ = 1;
    }
}

void Motor::stop()
{
    if (inB_ != NULL && inA_ != NULL)
    {
        *inA_ = 0;    
        *inB_ = 0;
    }
}

void Motor::setPinInA(PinName inA)
{
    inA_ = new DigitalOut(inA);

}
void Motor::setPinInB(PinName inB)
{
    inB_ = new DigitalOut(inB);
}

void Motor::setPinPwm(PinName pwm)
{
    pwm_ = new PwmOut(pwm);
    pwm_->period(0.001f);
    *pwm_ = 0.1f; 
}

void Motor::accelerate(const float accelerataion_value)
{
    *pwm_ = accelerataion_value;
}

} // namespace ras