const int trigPin = 2;        // Connect the trigger pin of the ultrasonic sensor to digital pin 2
const int echoPin = 3;        // Connect the echo pin of the ultrasonic sensor to digital pin 3
const int redLedPin = 4;      // Connect the red LED to digital pin 4
const int yellowLedPin = 5;   // Connect the yellow LED to digital pin 5
const int blueLedPin = 6;     // Connect the blue LED to digital pin 6

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  long duration, distance;

  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Change LED color based on distance
  if (distance < 20) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
  } else if (distance >= 20 && distance < 50) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(blueLedPin, LOW);
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(blueLedPin, HIGH);
  }

  delay(500);  // Adjust the delay as needed for your project
}
