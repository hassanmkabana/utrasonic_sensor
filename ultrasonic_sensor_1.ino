// defines pins numbers
const int pingPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 10; // Echo Pin of Ultrasonic Sensor
const int led = 7;
// define variables
long duration;
int distance;
int safetyDistance;
void setup() {
  Serial.begin(9600); // starting Serial Terminal
  pinMode(pingPin, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  // clears the trigpin
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  //sets the trigpin on high state for 10 microseconds
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  //duration
  duration = pulseIn(echoPin, HIGH);
  // calculate the distance
  distance = duration*0.034/2;
  safetyDistance = distance;

  if(safetyDistance<=20){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  //prints the distance on the serial monitor
  Serial.print("Distance:  ");
  Serial.print(distance);
}
 
