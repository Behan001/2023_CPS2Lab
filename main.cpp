//Uses the measured z-acceleration to drive leds 2 and 3 of the mbed

#include "mbed.h"
#include "MMA7660.h"
#include <cmath>
#define PI 3.14159265358979323846

MMA7660 MMA(p28, p27);

DigitalOut connectionLed(LED1);
PwmOut Zaxis_p(LED2);
PwmOut Zaxis_n(LED3);


float calculateAngle(float x, float y, float z){
    float angle = 0;
    float bott_part = sqrt((y*y)+(z*z));
    float angle_rad = atan(x/bott_part);
    angle = (angle_rad*180/PI);
    return angle;   

}

int main() {  
    if (MMA.testConnection())
        connectionLed = 1;
        
    while(1) {
        ThisThread::sleep_for(1);
        printf("result %f \r\n", calculateAngle(MMA.x(), MMA.y(), MMA.z()));
    }

}