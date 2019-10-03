#include <Wire.h>

int LED1 = 7;
int LED2 = 8;
int LED3 = 9;
int LED4 = 10;

int VoltPin1 = 11;
int VoltPin2 = 12;

int pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(VoltPin1, OUTPUT);
  pinMode(VoltPin2, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  Wire.setClock(100000);
}

void loop() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
}
