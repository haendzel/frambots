#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  180 // this is the 'maximum' pulse length count (out of 4096)

uint8_t servonum = 0;

int VoltPin = 9;
int pos = 0;

void setup() {
  pinMode(VoltPin, OUTPUT);
  Serial.begin(9600);

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(10);

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
  
  Serial.println(servonum);

  //first cycle
  
  for(pos = 50; pos < 210; pos += 1) {  
    analogWrite(VoltPin, pos);              
    delay(5);                       
  }

  for (uint16_t pulselen = 150; pulselen < 170; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(10);
  
  for(pos = 210; pos > 50; pos -= 1) {   
    analogWrite(VoltPin, pos);       
    delay(5);
  }

  for (uint16_t pulselen = 170; pulselen > 150; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(10);

  //second 

  for(pos = 50; pos < 210; pos += 1) {  
    analogWrite(VoltPin, pos);              
    delay(5);                       
  }

  for (uint16_t pulselen = 150; pulselen < 180; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(50);
  
  for(pos = 210; pos > 50; pos -= 1) {   
    analogWrite(VoltPin, pos);       
    delay(5);
  }

  for (uint16_t pulselen = 180; pulselen > 150; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(50);

  //third

  for(pos = 50; pos < 210; pos += 1) {  
    analogWrite(VoltPin, pos);              
    delay(5);                       
  }

  for (uint16_t pulselen = 180; pulselen < 200; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(100);
  
  for(pos = 210; pos > 50; pos -= 1) {   
    analogWrite(VoltPin, pos);       
    delay(5);
  }

  for (uint16_t pulselen = 200; pulselen > 180; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(100);

  //4

  for(pos = 50; pos < 210; pos += 1) {  
    analogWrite(VoltPin, pos);              
    delay(5);                       
  }

  for (uint16_t pulselen = 220; pulselen < 240; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(2);
  
  for(pos = 210; pos > 50; pos -= 1) {   
    analogWrite(VoltPin, pos);       
    delay(5);
  }

  for (uint16_t pulselen = 240; pulselen > 150; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(2);

  //5

  for(pos = 50; pos < 210; pos += 1) {  
    analogWrite(VoltPin, pos);              
    delay(5);                       
  }

  for (uint16_t pulselen = 150; pulselen < 170; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(3);
  
  for(pos = 210; pos > 50; pos -= 1) {   
    analogWrite(VoltPin, pos);       
    delay(5);
  }

  for (uint16_t pulselen = 170; pulselen > 150; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(3);

  //6

  for(pos = 50; pos < 210; pos += 1) {  
    analogWrite(VoltPin, pos);              
    delay(5);                       
  }

  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(1000);
  
  for(pos = 210; pos > 50; pos -= 1) {   
    analogWrite(VoltPin, pos);       
    delay(5);
  }

  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(1000);

  //7

  for(pos = 50; pos < 210; pos += 1) {  
    analogWrite(VoltPin, pos);              
    delay(5);                       
  }

  for (uint16_t pulselen = SERVOMIN; pulselen < 300; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(20);
  
  for(pos = 210; pos > 50; pos -= 1) {   
    analogWrite(VoltPin, pos);       
    delay(5);
  }

  for (uint16_t pulselen = 300; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(1);

  //8

  for(pos = 50; pos < 210; pos += 1) {  
    analogWrite(VoltPin, pos);              
    delay(5);                       
  }

  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(3);
  
  for(pos = 210; pos > 50; pos -= 1) {   
    analogWrite(VoltPin, pos);       
    delay(5);
  }

  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(3);

  //9

  for(pos = 50; pos < 210; pos += 1) {  
    analogWrite(VoltPin, pos);              
    delay(5);                       
  }

  for (uint16_t pulselen = SERVOMIN; pulselen < 400; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(50);
  
  for(pos = 210; pos > 50; pos -= 1) {   
    analogWrite(VoltPin, pos);       
    delay(5);
  }

  for (uint16_t pulselen = 400; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(3000);
  
}


