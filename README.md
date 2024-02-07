# Distance-Based LED Color Changer

#### Video Demo: [Video Link](https://www.youtube.com/watch?v=cyLgNR1naG4)

#### Description:

This project utilizes an Arduino Nano along with an ultrasonic sensor to create a distance-based LED color changer. The objective is to demonstrate how the color of LEDs changes based on the proximity of an object detected by the ultrasonic sensor.

The main components used in this project are:
- Arduino Nano
- Ultrasonic sensor (HC-SR04)
- Red, yellow, and blue LEDs
- Jumper wires

The code for this project is written in the Arduino programming language (based on C/C++). It uses the digitalWrite() function to control the state of the LEDs connected to the Arduino pins.

The project's workflow is as follows:
1. The ultrasonic sensor measures the distance between itself and an object.
2. Based on the measured distance, the Arduino determines which color LED to light up.
3. The red LED lights up when an object is within 20 centimeters, the yellow LED lights up when the object is between 20 and 50 centimeters away, and the blue LED lights up when the object is farther than 50 centimeters away.

Here's a breakdown of the files in this project:
- **distance_led_color_changer.ino**: This is the main Arduino sketch file. It contains the setup() and loop() functions. The setup() function initializes the pin modes, and the loop() function reads the distance from the ultrasonic sensor and controls the LEDs accordingly.
- **README.md**: This file you're currently reading. It provides an overview of the project, its components, and how it works.

I decided to use only red, yellow, and blue LEDs to keep the project simple and focused. These colors are commonly used in traffic signals, making it easy to understand the behavior of the LEDs based on distance. Additionally, using fewer LEDs simplifies the wiring and code.

In terms of design choices, I opted to use the HC-SR04 ultrasonic sensor due to its ease of use and reliability. The Arduino Nano was chosen for its compact size and compatibility with the project's requirements. Overall, the goal was to create a straightforward yet educational project that demonstrates basic concepts of sensor input and LED output control with Arduino.

I hope this project inspires you to explore further and create your own Arduino-based projects!

## Explanation of the Code

The code for the distance-based LED color changer may seem complex at first glance, but let's break it down into simpler terms.

### 1. Setting Up the Components
In the setup() function, we tell the Arduino what each pin will be used for. Pins are like little switches on the Arduino board that we can turn on or off. We set some pins to be used as outputs, which means they will control things like LEDs, and others to be inputs, which means they will receive information from sensors.

```cpp
void setup() {
  pinMode(trigPin, OUTPUT);  // Set the ultrasonic sensor trigger pin as an output
  pinMode(echoPin, INPUT);   // Set the ultrasonic sensor echo pin as an input
  pinMode(redLedPin, OUTPUT);      // Set the red LED pin as an output
  pinMode(yellowLedPin, OUTPUT);   // Set the yellow LED pin as an output
  pinMode(blueLedPin, OUTPUT);     // Set the blue LED pin as an output
}
```

### 2. Looping and Checking Distance
The loop() function runs over and over again as long as the Arduino is powered on. Here, we trigger the ultrasonic sensor to send out sound waves and wait for them to bounce back. Based on the time it takes for the sound waves to return, we can calculate the distance to an object in front of the sensor.

```cpp
void loop() {
  // Trigger the ultrasonic sensor to send out sound waves
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the time it takes for the sound waves to bounce back
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;
}
```

### 3. Controlling LEDs Based on Distance
Now that we know the distance to the object, we can decide which LED to turn on. If the distance is less than 20 centimeters, we turn on the red LED. If it's between 20 and 50 centimeters, we turn on the yellow LED. Otherwise, we turn on the blue LED.

```cpp
// Change LED color based on distance
if (distance < 20) {
  digitalWrite(redLedPin, HIGH);     // Turn on the red LED
  digitalWrite(yellowLedPin, LOW);   // Turn off the yellow LED
  digitalWrite(blueLedPin, LOW);     // Turn off the blue LED
} else if (distance >= 20 && distance < 50) {
  digitalWrite(redLedPin, LOW);      // Turn off the red LED
  digitalWrite(yellowLedPin, HIGH);  // Turn on the yellow LED
  digitalWrite(blueLedPin, LOW);     // Turn off the blue LED
} else {
  digitalWrite(redLedPin, LOW);      // Turn off the red LED
  digitalWrite(yellowLedPin, LOW);   // Turn off the yellow LED
  digitalWrite(blueLedPin, HIGH);    // Turn on the blue LED
}
```

### 4. Repeating the Process
After controlling the LEDs based on the distance, we wait for a short period before starting the process again. This delay allows us to see the LED's color change clearly.

```cpp
delay(500);  // Wait for 500 milliseconds (0.5 seconds)
```

By understanding how each part of the code works, we can see how the Arduino communicates with the ultrasonic sensor, calculates distances, and controls the LEDs to create a cool color-changing effect based on the object's proximity.

