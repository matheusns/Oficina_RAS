#include <Motor.hpp>

namespace ras
{
Motor::Motor()
    : serial_monitor_(USBTX, USBRX)
{
}

void Motor::moveForward()
{
   serial_monitor_.printf("Motor moveForward\n");
}

void Motor::moveBack()
{
    serial_monitor_.printf("Motor moveBack\n");
}

void Motor::stop()
{
   serial_monitor_.printf("Motor stop\n");
}

void setPinControl1(PinName control1)
{
    
}
void setPinControl2(PinName control2)
{
    
}
void setPinPwm(PinName pwm)
{
    
}

}