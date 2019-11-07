

static unsigned long tempo_anterior = 0, tempo_atual;

#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif
#include <Servo.h>
Servo servo;
MPU6050 mpu;
#define OUTPUT_READABLE_YAWPITCHROLL

#include"math.h"
#include"stdio.h"
#include"stdlib.h"
#define pi 6.283185307179586


#define INTERRUPT_PIN 3 // use pin 2 on Arduino Uno & most boards
#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
int pwm = 0;

bool blinkState = false;
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

uint8_t teapotPacket[14] = { '$', 0x02, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, '\r', '\n' };

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady()
{
  mpuInterrupt = true;
}
long int k = 0;

int op = 0;



#define amp 255         //Bits PWM
#define freqMin 4       //Hz
#define freqPasso 0.5   //Incremento de troca de frequencia (uma senoide completa por frequencia)
#define freqMax 10      //Hz
#define taxAmo 0.02     //Periodo em segundos

#include"funcoes.h"
#include"sinais.h"

void setup()
{
    init();
    do{leiaAngulo();} while(!Serial.available());
    Serial.println();
    Serial.println();
    Serial.println("identificacao = [");
    executaDegraus(amp, freqMin, freqPasso, freqMax, taxAmo);
    executaSinVar (amp, freqMin, freqPasso, freqMax, taxAmo);
    Serial.println("];");
  }


  void loop()
  {
    delay(100);
  }
