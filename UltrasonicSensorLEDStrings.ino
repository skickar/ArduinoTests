// defines pins numbers
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3

// defines variables
long duration; 
int distance; // distance to the sensor of an object
int trigger = 1900; // The range at which we say there is an object detected (infinity is past 2000)
int cooldown = 0; // Creating the cooldown timer, which we can add to when we detect something. This is checked later.

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication so we can debug and position the sensor
pinMode(D5, OUTPUT); 

}
void turnon() { // A function to turn the LED strips on
  digitalWrite(D5, HIGH); }  // Turn the LED on by making the voltage HIGH
void turnoff() { // A function to turn the LED strips off
  digitalWrite(D5, LOW); }  // Turn the LED off by making the voltage LOW

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
// Checks if the distance indicates someone is near by comparing against the trigger value
if (int(distance)<trigger) // Adds 50 to the cooldown timer if a person is detected
{
  cooldown = 50;
}
else if (int(distance)>trigger) // If no one is there, we subtract one from the timer. 
// Was worried this could make the cooldown increasingly negative, but doesn't seem to be a problem in testing
{
  cooldown--;
}
if (cooldown > 0) { // Turn on the lights and subtract one from cooldown if the value of cooldown is positive
  turnon(), cooldown--; }
else if (cooldown < 1) { // Turn off the lights 
  turnoff()//,cooldown--; } // Why am I subtracting another from the cooldown timer? 
//Should change this but doesn't seem to be a problem
Serial.print("Cooldown: ");
Serial.println(cooldown);
delay(100);
}
