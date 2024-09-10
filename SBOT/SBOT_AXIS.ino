#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(); // MAIN

// Parameters for the servos
#define SERVO_MIN 150   
#define SERVO_MAX 600   

// Servo channels on PCA9685
#define SERVO1_CHANNEL 0
#define SERVO2_CHANNEL 1
#define SERVO3_CHANNEL 2 // LEG 1

#define SERVO4_CHANNEL 3
#define SERVO5_CHANNEL 4
#define SERVO6_CHANNEL 5 // LEG 2

#define SERVO7_CHANNEL 6
#define SERVO8_CHANNEL 7
#define SERVO9_CHANNEL 8 //LEG 3

#define SERVO10_CHANNEL 9
#define SERVO11_CHANNEL 10
#define SERVO12_CHANNEL 11  //LEG4




int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
}

void setup() {
  Serial.begin(9600);
  pca9685.begin();
  pca9685.setPWMFreq(60);  
}

void loop() {

  pca9685.setPWM(SERVO1_CHANNEL, 0, angleToPulse(140));      //L1A
  delay(100); 

  pca9685.setPWM(SERVO2_CHANNEL, 0, angleToPulse(40));     //L1B
  delay(100);  

  pca9685.setPWM(SERVO3_CHANNEL, 0, angleToPulse(30));     //L1C
  delay(100); 




    pca9685.setPWM(SERVO4_CHANNEL, 0, angleToPulse(100));    //L2A
  delay(100); 

  pca9685.setPWM(SERVO5_CHANNEL, 0, angleToPulse(60));     //L2B
  delay(100);  

  pca9685.setPWM(SERVO6_CHANNEL, 0, angleToPulse(60));     //L2C
  delay(100); 




    pca9685.setPWM(SERVO7_CHANNEL, 0, angleToPulse(160));    //L3A
  delay(100); 

  pca9685.setPWM(SERVO8_CHANNEL, 0, angleToPulse(140));     //L3B
  delay(100);  

  pca9685.setPWM(SERVO9_CHANNEL, 0, angleToPulse(130));     //L3C
  delay(100); 



    pca9685.setPWM(SERVO10_CHANNEL, 0, angleToPulse(60));   //L4A
  delay(100); 

  pca9685.setPWM(SERVO11_CHANNEL, 0, angleToPulse(120));     //L4B
  
  delay(100);  

  pca9685.setPWM(SERVO12_CHANNEL, 0, angleToPulse(120));      //L4C
  delay(2000); 


 ///////////////////////////////////////////////////////////////////////
 

    pca9685.setPWM(SERVO7_CHANNEL, 0, angleToPulse(70));    //L3A
  delay(100); 

   pca9685.setPWM(SERVO10_CHANNEL, 0, angleToPulse(140));   //L4A
  delay(100); 


  pca9685.setPWM(SERVO8_CHANNEL, 0, angleToPulse(140));     //L3B
  delay(500);  


  //pca9685.setPWM(SERVO11_CHANNEL, 0, angleToPulse(0));     //L4B
  
  delay(100); 


  pca9685.setPWM(SERVO1_CHANNEL, 0, angleToPulse(90));      //L1A
  delay(100); 

  pca9685.setPWM(SERVO2_CHANNEL, 0, angleToPulse(130));     //L1B
  delay(100);  

  pca9685.setPWM(SERVO3_CHANNEL, 0, angleToPulse(100));     //L1C
  delay(100); 




    pca9685.setPWM(SERVO4_CHANNEL, 0, angleToPulse(135));    //L2A
  delay(100); 

  pca9685.setPWM(SERVO5_CHANNEL, 0, angleToPulse(140));     //L2B
  delay(100);  

  pca9685.setPWM(SERVO6_CHANNEL, 0, angleToPulse(140));     //L2C
  delay(100); 




    pca9685.setPWM(SERVO7_CHANNEL, 0, angleToPulse(130));    //L3A
  delay(100); 

  pca9685.setPWM(SERVO8_CHANNEL, 0, angleToPulse(50));     //L3B
  delay(100);  

  pca9685.setPWM(SERVO9_CHANNEL, 0, angleToPulse(30));     //L3C
  delay(100); 



    pca9685.setPWM(SERVO10_CHANNEL, 0, angleToPulse(80));   //L4A
  delay(100); 

  pca9685.setPWM(SERVO11_CHANNEL, 0, angleToPulse(40));     //L4B
  
  delay(100);  

  pca9685.setPWM(SERVO12_CHANNEL, 0, angleToPulse(50));      //L4C
  delay(100); 






delay(1000);
}