#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded Distance Measurement using Ultrasonic Sensor
 * @author rishabh-rb
 * @date 2026-02-20
 *
 * @details
 * Measures distance using HC-SR04 ultrasonic sensor
 * and displays structured output via Serial Monitor.
 */

// TODO 1:
// Define TRIG pin (Use pin 9)
#define TRIG_PIN 9

// TODO 2:
// Define ECHO pin (Use pin 10)
#define ECHO_PIN 10

// TODO 3:
// Create variable to store duration
long duration;

// TODO 4:
// Create variable to store calculated distance
float distance;

void setup() {

    // TODO 5:
    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // TODO 6:
    // Configure TRIG as OUTPUT
    pinMode(TRIG_PIN, OUTPUT);

    // TODO 7:
    // Configure ECHO as INPUT
    pinMode(ECHO_PIN, INPUT);

    // TODO 8:
    // Print system initialization message
    Serial.println("HC-SR04 Ultrasonic Distance Measurement System");
    Serial.println("System Initializing...");
    delay(1000);
}

void loop() {

    // TODO 9:
    // Set TRIG LOW for 2 microseconds
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // TODO 10:
    // Send 10 microsecond pulse on TRIG
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW) ;

    // TODO 11:
    // Measure pulse duration on ECHO using pulseIn()
    duration = pulseIn(ECHO_PIN, HIGH);

    // TODO 12:
    // Calculate distance in cm
    distance = duration * 0.0343 / 2;

    // TODO 13:
    // Print calculated distance
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // TODO 14:
    // Add delay (500ms)
    delay(500);
}