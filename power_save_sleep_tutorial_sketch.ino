/**
 * 
 * Modified by Kody Kinzie, plays light animation on interrupt
 * Based on:
 * Author:Ab Kurk
 * version: 1.0
 * date: 24/01/2018
 * Description: 
 * This sketch is part of the beginners guide to putting your Arduino to sleep
 * tutorial. It is to demonstrate how to put your arduino into deep sleep and
 * how to wake it up.
 * Link To Tutorial http://www.thearduinomakerman.info/blog/2018/1/24/guide-to-arduino-sleep-mode
 */

#include <avr/sleep.h>//this AVR library contains the methods that controls the sleep modes
#define interruptPin 2 //Pin we are going to use to wake up the Arduino
int bLED = 5;
int rLED = 10;
int gLED = 6;

void flashLED(int cLED, int numRep, int flashLength){
      for(int i = 0; i < numRep; i++){
      digitalWrite(cLED,HIGH);//turning LED on
      delay(flashLength);
      digitalWrite(cLED,LOW);//turning LED on
      delay(100);  }
}

void setup() {
  Serial.begin(115200);//Start Serial Comunication
  pinMode(LED_BUILTIN,OUTPUT);//We use the led on pin 13 to indecate when Arduino is A sleep
  pinMode(interruptPin,INPUT_PULLUP);//Set pin d2 to input using the buildin pullup resistor
  digitalWrite(LED_BUILTIN,HIGH);//turning LED on
  pinMode(rLED,OUTPUT);//We use the led on pin 13 to indecate when Arduino is A sleep
  pinMode(gLED,OUTPUT);//We use the led on pin 13 to indecate when Arduino is A sleep
  pinMode(bLED,OUTPUT);//We use the led on pin 13 to indecate when Arduino is A sleep
}

void loop() {
 delay(5000);//wait 5 seconds before going to sleep
 Going_To_Sleep();
}

void Going_To_Sleep(){
    sleep_enable();//Enabling sleep mode
    attachInterrupt(0, wakeUp, LOW);//attaching a interrupt to pin d2
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);//Setting the sleep mode, in our case full sleep
    digitalWrite(LED_BUILTIN,LOW);//turning LED off
    delay(1000); //wait a second to allow the led to be turned off before going to sleep
    sleep_cpu();//activating sleep mode
    Serial.println("just woke up!");//next line of code executed after the interrupt 
    digitalWrite(LED_BUILTIN,HIGH);//turning LED on
    for(int i = 0; i < 5; i++){
      flashLED(gLED, 5, 50);
      flashLED(rLED, 5, 50);
      flashLED(bLED, 5, 50);
    }
    
  }

void wakeUp(){
  Serial.println("Interrrupt Fired");//Print message to serial monitor
   sleep_disable();//Disable sleep mode
  detachInterrupt(0); //Removes the interrupt from pin 2;
}

