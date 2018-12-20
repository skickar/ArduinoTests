// defines pins numbers
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3

// defines variables
long duration;
int distance;
int trigger = 1900;
int cooldown = 0;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
pinMode(D5, OUTPUT); 

}
void turnon() {
  digitalWrite(D5, HIGH); }  // Turn the LED on by making the voltage HIGH
void turnoff() {
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
if (int(distance)<trigger)
{
  cooldown = 50;
}
else if (int(distance)>trigger)
{
  cooldown--;
}
if (cooldown > 0) {
  turnon(), cooldown--; }
else if (cooldown < 1) {
  turnoff(),cooldown--; }

delay(100);
}
