#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  400 // this is the 'maximum' pulse length count (out of 4096)

uint8_t servonum = 0;

int VoltPin = 9;
int pos = 0;

void setup() {
 
  Serial.begin(9600);
  pinMode(VoltPin, OUTPUT);
  
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

  void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 10000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 10000000;  // convert to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  
  Serial.println(servonum);

  for(pos = 60; pos < 140; pos += 1) {  
    analogWrite(VoltPin, pos);              
    delay(5);                       
  }

  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(servonum, 1, pulselen);
  }

delay(30);
  
  for(pos = 140; pos > 60; pos -= 1) {   
    analogWrite(VoltPin, pos);       
    delay(5);
  }

  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 1, pulselen);
  }

delay(30);
  
}
