#include <mbed.h>

DigitalOut ledOut(LED2);
DigitalIn button(BUTTON1);

int main()
{
    while(1)
    {
        if (!button)
        {
            ledOut = !ledOut;
            wait(0.25);
        }
    }
}