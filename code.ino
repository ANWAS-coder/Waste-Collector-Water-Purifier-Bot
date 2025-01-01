#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL65suP-UJ-"
#define BLYNK_TEMPLATE_NAME "Protject4"
#define BLYNK_AUTH_TOKEN "lv4hd8Hz5O34MpWaYm6FM9_QYtWdo0jk"

#include <Servo.h>  
#include <SPI.h>
#include <WiFiS3.h>
#include <BlynkSimpleWifi.h>


const int motorLeft1 = 0;  // IN1
const int motorLeft2 = 1;  // IN2
const int motorRight1 = 2; // IN3
const int motorRight2 = 3; // IN4
const int enableA = 9;     // ENA (PWM)
const int enableB = 10;    // ENB (PWM)

const int motor2Left1 = 4;  // IN1
const int motor2Left2 = 5;  // IN2
const int motor2Right1 = 8; // IN3
const int motor2Right2 = 7; // IN4
const int enable2A = 12;     // ENA (PWM)
const int enable2B = 13;    // ENB (PWM)

Servo servo1;  
Servo servo2;  


char ssid[] = "Nathan_Ip";
char pass[] = "aabbccdd12";


BLYNK_WRITE(V0) {
  int val = param.asInt();
  if (val == 1) {
    digitalWrite(motorLeft1, HIGH);
    digitalWrite(motorLeft2, LOW);
    digitalWrite(motorRight1, HIGH);
    digitalWrite(motorRight2, LOW);

    digitalWrite(motor2Left1, HIGH);
    digitalWrite(motor2Left2, LOW);
    digitalWrite(motor2Right1, HIGH);
    digitalWrite(motor2Right2, LOW);
  } else {
    digitalWrite(motorLeft1, LOW);
    digitalWrite(motorRight1, LOW);

    digitalWrite(motor2Left1, LOW);
    digitalWrite(motor2Right1, LOW);
  }
}

BLYNK_WRITE(V1) {
  int val = param.asInt();
  if (val == 1) {
    digitalWrite(motorLeft1, LOW);
    digitalWrite(motorLeft2, HIGH);
    digitalWrite(motorRight1, HIGH);
    digitalWrite(motorRight2, LOW);

    digitalWrite(motor2Left1, LOW);
    digitalWrite(motor2Left2, HIGH);
    digitalWrite(motor2Right1, HIGH);
    digitalWrite(motor2Right2, LOW);
  } else {
    digitalWrite(motorLeft2, LOW);
    digitalWrite(motorRight1, LOW);
    digitalWrite(motor2Left2, LOW);
    digitalWrite(motor2Right1, LOW);
  }
}

BLYNK_WRITE(V2) {
  int val = param.asInt();
  if (val == 1) {
    digitalWrite(motorLeft1, HIGH);
    digitalWrite(motorLeft2, LOW);
    digitalWrite(motorRight1, LOW);
    digitalWrite(motorRight2, HIGH);

    digitalWrite(motor2Left1, HIGH);
    digitalWrite(motor2Left2, LOW);
    digitalWrite(motor2Right1, LOW);
    digitalWrite(motor2Right2, HIGH);
  } else {
    digitalWrite(motorLeft1, LOW);
    digitalWrite(motorRight2, LOW);

    digitalWrite(motor2Left1, LOW);
    digitalWrite(motor2Right2, LOW);
  }
}


BLYNK_WRITE(V3) {
  int val = param.asInt();
  if (val == 1) {

    for (int pos = 0; pos <= 180; pos++) {
    servo1.write(pos);
    }
    for (int pos = 0; pos <= 180; pos++) {
    servo2.write(pos);
    }
  }
    
  else {
    for (int pos = 180; pos >= 0; pos--) {
    servo1.write(pos);  
    }
    for (int pos = 180; pos >= 0; pos--) {
    servo2.write(pos);
    }

  }
}

void setup() {
  pinMode(motorLeft1, OUTPUT);
  pinMode(motorLeft2, OUTPUT);
  pinMode(motorRight1, OUTPUT);
  pinMode(motorRight2, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);

  pinMode(motor2Left1, OUTPUT);
  pinMode(motor2Left2, OUTPUT);
  pinMode(motor2Right1, OUTPUT);
  pinMode(motor2Right2, OUTPUT);
  pinMode(enable2A, OUTPUT);
  pinMode(enable2B, OUTPUT);
  
  analogWrite(enableA, 200);
  analogWrite(enableB, 200);

  analogWrite(enable2A, 200);
  analogWrite(enable2B, 200);
  
  servo1.attach(6);
  servo2.attach(11);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}
