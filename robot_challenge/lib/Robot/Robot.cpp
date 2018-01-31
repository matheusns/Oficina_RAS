#include <Robot.hpp>

namespace ras
{
Robot::Robot(PinName front_sensor_pin, PinName right_sensor_pin, PinName left_sensor_pin)
    : serial_monitor_(USBTX, USBRX)
    , right_motor_(NULL)
    , left_motor_(NULL)
    , front_sensor_(front_sensor_pin)
    , left_sensor_(left_sensor_pin)
    , right_sensor_(right_sensor_pin)
{

}
Robot::~Robot()
{
    if (right_motor_ != NULL) delete right_motor_; 
    if (left_motor_ != NULL) delete left_motor_; 
}

void Robot::setRightMotorPin(PinName inA, PinName pwm, PinName inB)
{
    right_motor_ = new Motor();
    right_motor_->setPinInA(inA);
    right_motor_->setPinInB(inB);
    right_motor_->setPinPwm(pwm);
}
void Robot::setLeftMotorPin(PinName inA, PinName pwm, PinName inB)
{
    left_motor_ = new Motor();
    left_motor_->setPinInA(inA);
    left_motor_->setPinInB(inB);
    left_motor_->setPinPwm(pwm);
}

void Robot::setSensorsLimiar(const float limiar)
{
    this->limiar_ = limiar;
}

Direction Robot::move()
{
    if (front_sensor_.read() > limiar_)
    {
        // serial_monitor_.printf("Front value %f !\n", front_sensor_.read());    
        moveFront();
        return ras::FRONT;
    }

    else if (right_sensor_.read() > limiar_)
    {
        // serial_monitor_.printf("Right value %f !\n", right_sensor_.read());    
        moveRight();
        return ras::RIGHT;
    }

    else if (left_sensor_.read() > limiar_)
    {
        // serial_monitor_.printf("Left value %f !\n", left_sensor_.read());    
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
    if (right_motor_ != NULL && left_motor_ != NULL)
    {
        // serial_monitor_.printf("Moving to Front\n");    
        // serial_monitor_.printf("Left Forward - Right Forward\n");    
        
        right_motor_->accelerate( float(front_sensor_.read()) );
        left_motor_->accelerate( float(front_sensor_.read()) );

        right_motor_->moveForward();
        left_motor_->moveForward();
    }
}

void Robot::moveLeft()
{
    if (right_motor_ != NULL && left_motor_ != NULL)
    {
        // serial_monitor_.printf("Moving to Left\n");    
        // serial_monitor_.printf("Left Stop - Right Forward\n");    

        right_motor_->accelerate( float(right_sensor_.read()) );
        left_motor_->accelerate( float(right_sensor_.read()) );

        right_motor_->moveForward();
        left_motor_->stop();
    }
}

void Robot::moveRight() 
{
    if (right_motor_ != NULL && left_motor_ != NULL)
    {
        // serial_monitor_.printf("Moving to Right\n");    
        // serial_monitor_.printf("Right Stop - Left Forward\n");    

        right_motor_->accelerate( float(left_sensor_.read()));
        left_motor_->accelerate( float(left_sensor_.read()));

        right_motor_->stop();
        left_motor_->moveForward();
    }
}

void Robot::moveBack() 
{
    if (right_motor_ != NULL && left_motor_ != NULL)
    {
        // serial_monitor_.printf("Moving to Back\n");    

        right_motor_->accelerate( float(left_sensor_.read())/2.0 );
        left_motor_->accelerate( float(left_sensor_.read())/2.0 );

        right_motor_->moveBack();
        left_motor_->moveBack();
    }
}

}