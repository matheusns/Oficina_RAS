#include <mbed.h>

DigitalOut led(LED2);

int main() 
{
    // put your setup code here, to run once:
    while(1) 
    {
        led =!led;
        wait(1);
        // put your main code here, to run repeatedly:
    }
}