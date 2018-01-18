#include <Robot.hpp>

namespace ras
{
Robot::Robot(PinName front_sensor_pin, PinName right_sensor_pin, PinName left_sensor_pin)
    : serial_monitor_(USBTX, USBRX)
    , front_sensor_(front_sensor_pin)
    , left_sensor_(left_sensor_pin)
    , right_sensor_(right_sensor_pin)
{

}
Robot::~Robot()
{

}

void Robot::setRightMotorPin(PinName control1, PinName pwm, PinName control2)
{

}

void Robot::setLeftMotorPin(PinName control1, PinName pwm, PinName control2)
{

}

void Robot::setLimiar(float limiar)
{
    this->limiar_ = limiar;
}

Direction Robot::move()
{
    if (front_sensor_ < limiar_)
    {
        serial_monitor_.printf("Front value %f !\n", front_sensor_);    
        moveFront();
        return ras::FRONT;
    }

    else if (right_sensor_ < limiar_)
    {
        serial_monitor_.printf("Right value %f !\n", right_sensor_);    
        moveRight();
        return ras::RIGHT;
    }

    else if (left_sensor_ < limiar_)
    {
        serial_monitor_.printf("Left value %f !\n", left_sensor_);    
        moveLeft();
        return ras::LEFT;
    }

    else
    {
        moveBack();
        return ras::BACK;
    } 
}

void Robot::moveFront()
{
    // serial_monitor_.printf("Front!\n");
}
void Robot::moveLeft()
{
    // serial_monitor_.printf("Left!\n");
}
void Robot::moveRight()
{
    // serial_monitor_.printf("Right!\n");
}
void Robot::moveBack()
{
    // serial_monitor_.printf("Back!\n");
}

}