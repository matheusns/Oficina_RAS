#include <mbed.h>
#include <Robot.hpp>


int main() 
{
    ras::Robot my_robot(A0,A1,A2);
    my_robot.setLimiar(0.5);
    while(1) 
    {
        my_robot.move();
        wait(0.25);
    }
}