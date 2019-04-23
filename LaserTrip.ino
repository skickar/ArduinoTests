/*
 * Project #3 - Laser Tripwire Security System with 3 second deactivation delay.
Code written by: Youri C. - RGBFreak
You're allowed to re-publish this code as long as you give me credits.
Video on how to connect all the wires: 
Video on how to build a tripwire secutiry system with less electronics: https://www.youtube.com/watch?v=eHrh5tnG4Wg

Don't forget to subscribe to my channel for more DIY projects! - https://www.youtube.com/channel/UCKp8cQWkiGGfAV5FM_Q0mxA
My Instructables profile page - http://www.instructables.com/member/RGBFreak/

How it works:
As soon as the laser beam gets interrupted the Laser Receiver Module will send out a signal that will trigger the alarm into the Arduino code below.
A LED will turn on and that means you have 3 seconds to press the reset button on your Arduino before the speaker will start buzzing.
After a short while the alarm will reset itself.
 */
 
#define NOTE_F6  1397
#define NOTE_G4  392

int LED = 13;
int LaserSensor = 4;
int SensorReading = HIGH;  // HIGH MEANS NO OBSTACLE
int Laser = 12;
int alarmSpeaker = 7;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(Laser, OUTPUT);
  pinMode(alarmSpeaker, OUTPUT);
  pinMode(LaserSensor, INPUT);
}

void alarmTone() {
  tone(7,  NOTE_F6, 400);
  delay(100);
  tone(7,  NOTE_G4, 400);
  delay(100);
}

void alarm() {
  delay(3000); //Time before alarm starts
  for i in range (30);
    alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  alarmTone();
  }

void loop() {
  digitalWrite(Laser, HIGH);
  delay(200);
  SensorReading = digitalRead(LaserSensor);
  if (SensorReading == LOW)
  {
    digitalWrite(LED, HIGH);
    alarm();
  }

  else
  {
    digitalWrite(LED, LOW);
  }
}
