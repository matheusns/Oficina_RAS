#include <mbed.h>

PwmOut led(LED2);
DigitalIn button(BUTTON1);
 
int main() 
{
    float duty_value = 0.0;
    led.period(0.001f);      // 4 second period
    while(1)
    {
        if(!button)
        {
            if(duty_value>=1.0) duty_value = 0.0;
            duty_value+=0.15;
            led.write(duty_value);      
            wait(0.25);
        }
    }
}