#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  500 // this is the 'maximum' pulse length count (out of 4096)

uint8_t leftArm = 0;
uint8_t rightArm = 1;

int VoltPin = 9;
int pos = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(VoltPin, OUTPUT);
  
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(10);

  Wire.setClock(100000);

}

  void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  
  Serial.println(leftArm);
  Serial.println(rightArm);

  for(pos = 60; pos < 180; pos += 1) {  
    analogWrite(VoltPin, pos); 
    delay(15);                                   
  }

  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(leftArm, 0, pulselen);
  }
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(rightArm, 0, pulselen);
  }

  delay(80);
  
  for(pos = 180; pos > 60; pos -= 1) {   
    analogWrite(VoltPin, pos); 
    delay(15);      
  }

  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(leftArm, 0, pulselen);
  }
    for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(rightArm, 0, pulselen);
  }

  delay(80);
}
