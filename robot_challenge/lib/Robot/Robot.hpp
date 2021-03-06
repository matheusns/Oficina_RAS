#ifndef ROBOT_ROBOT_HPP
#define ROBOT_ROBOT_HPP

#include <mbed.h>
#include <Motor.hpp>

namespace ras 
{
enum Direction
{
    FRONT,
    RIGHT,
    LEFT,
    BACK 
};

class Robot
{
  public:
  
    explicit Robot(PinName front_sensor_pin_, PinName right_sensor_pin_, PinName left_sensor_pin_);
    virtual ~Robot();
    
    void setRightMotorPin(PinName control1, PinName pwm, PinName control2);
    void setLeftMotorPin(PinName control1, PinName pwm, PinName control2);

    void setSensorsLimiar(const float limiar);

    Direction move();

    void moveFront();
    void moveLeft() ;
    void moveRight();
    void moveBack() ;

  private:

    Motor  *right_motor_, *left_motor_;
    Serial serial_monitor_;   
    AnalogIn front_sensor_, left_sensor_, right_sensor_;   
    float limiar_;
};
} //namespace ras

#endif
    