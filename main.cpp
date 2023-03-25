//Uses the measured z-acceleration to drive leds 2 and 3 of the mbed

#include "mbed.h"    // include the header file "mbed.h"
#include "MMA7660.h" // include the header file "MMA7660.h"
#include <cmath>     // include the math library
#define PI 3.14159265358979323846  // define PI

MMA7660 MMA(p28, p27); // create MMA7660 object "MMA" with pins p28 and p27

DigitalOut connectionLed(LED1); // create a DigitalOut and 2 PwmOut objects to LED's 1,2 and 3
PwmOut Zaxis_p(LED2);
PwmOut Zaxis_n(LED3);

// This function takes input x, y, and z, and returns the angle in degrees
float calculateAngle(float x, float y, float z){
    float angle = 0;
    float bott_part = sqrt((y*y)+(z*z));
    float angle_rad = atan(x/bott_part);
    angle = (angle_rad*180/PI);
    return angle;   

}

int main() {  // tests the connection to the mbed with the LEDs
    if (MMA.testConnection())
        connectionLed = 1;
        
    while(1) { //loop waits 1 and prints the calculated angle
        ThisThread::sleep_for(1);
        printf("result %f \r\n", calculateAngle(MMA.x(), MMA.y(), MMA.z()));
    }

}