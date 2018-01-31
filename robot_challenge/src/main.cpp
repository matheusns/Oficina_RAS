#include <mbed.h>
#include <Robot.hpp>

int x;

int main() 
{
    // mouse_robot(front_sensor_pin, right_sensor_pin,  left_sensor_pin)
    ras::Robot mouse_robot(A0,A1,A2);
    mouse_robot.setSensorsLimiar(0.86f);
    // setRightMotorPin(inA, pwm, inB)
    mouse_robot.setRightMotorPin(D8,D9,D10);
    // setLeftMotorPin(inA,pwm, inB)
    mouse_robot.setLeftMotorPin(D11,D12,D13);
    
    while(true) 
    {
        mouse_robot.move();
        wait(0.5);
    }
}