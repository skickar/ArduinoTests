// Script to blink an LEDs from a button
// By Kody Kinzie, Null Byte 2019

// Variable definitions
const int bLED = 3;
const int gLED = 4;
const int rLED = 5;
const int wLED = 6;
int onDelay = 500;
int offDelay = 500;
bool boolState = 1;

//Blink pattern functions

void blue(){
  digitalWrite(3, HIGH); 
}
void green(){
  digitalWrite(4, HIGH); 
}
void red(){
  digitalWrite(5, HIGH); 
}
void white(){
  digitalWrite(6, HIGH);
}
void alloff(){ // we use a little loop to turn off all pins from 1 to 6 so we can run it between color functions. 
    for (int i = 3; i <= 6; i++) { // By adding this function, the colors can be stacked on top of eachother!
      digitalWrite(i, LOW); // Turn the pin off, i is which round of the loop we are on, starting at 1 and going to 6
    }
}

void spacer(){ // This is to turn off all the pins. We can adjust the delay to change how long they stay on for
  delay(onDelay); // padding because computers are TOO fast
  alloff(); // run our turnoff function in a nice little spacer. Now we are turning it off and can define the length.
  delay(offDelay); // defense against fast computer, but maybe redundant
}

void setup() {
  //start serial connection
  Serial.begin(9600); // now we can see on our computer if this is working
  //configure pin 2 as an input and enable the internal pull-up resistor and other pins for output
  pinMode(7, INPUT_PULLUP); // we connect this to the button and the other end of the button to ground. Now it will read 1 normally, 0 when pressed.
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
  int sensorVal = digitalRead(7);  // Read the pushbutton value into a variable
  Serial.println(sensorVal); // Printing the value of the sensor
  if (sensorVal == HIGH) { // checking if the sensor is HIGH, its normal state
    digitalWrite(13, LOW); // Writing to the internal LED pin, LOW, turning it off (if it was on)
  } else { // if the button is connecting the pullup to ground, then we'll see a zero and get this condition
    digitalWrite(13, HIGH); // Turn this right back on here and then do some colors!
    blue();
    spacer();
    blue(), green();
    spacer();
    blue(), green(), red();
    spacer();
    blue(), green(), red(), white();
    spacer();
  }
}
