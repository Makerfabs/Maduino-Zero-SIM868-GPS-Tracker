#include<stdio.h>
#include<string.h>
#define DEBUG true

//www.makerfabs.com
//Fuction: Maduino Zero SIMI868 test: you can send AT Command via serial tool to know how to use SIM868 Module, 
//you can program to control it as your wish after you know how to use it.
//version:v1.0
//author:Charlin
//date:2023/10/07

int GSM_PWR_KEY = 9; //Power Key of SIM808

int GSM_RI = 3;

//D0 as RXD and D1 as TXD
//A1 for battery voltage
//A2 for 4.2V(DC-DC) voltage
//D4 for microSD card select pin

void setup()
{
  SerialUSB.begin(115200);//USB Serial
  Serial1.begin(115200);// serial connect to SIM808
  delay(1000);
  
  pinMode(GSM_PWR_KEY, OUTPUT);
  digitalWrite(GSM_PWR_KEY, LOW);
  delay(1100);
  digitalWrite(GSM_PWR_KEY, HIGH);//A pulse to turn on or turn off SIM808 
  delay(10000);

  //while (!SerialUSB)
  {
    ; // wait for Arduino serial Monitor port to connect
  }

  SerialUSB.println("Maduino Zero SIM868 Test Start!");
  digitalWrite(GSM_PWR_KEY, LOW);
}

void loop()
{
  //get what form serial send to USB serial
  while (Serial1.available() > 0) {
    SerialUSB.write(Serial1.read());
    yield();
  }
  //get what form USB serial send to serial
  while (SerialUSB.available() > 0) {
    Serial1.write(SerialUSB.read());
    yield();
  }
}
