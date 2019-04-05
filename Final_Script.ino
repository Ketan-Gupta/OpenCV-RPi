#include "NewPing.h"
#include <Servo.h>
 
#define TRIGGER_PIN  10
#define ECHO_PIN     13
#define MAX_DISTANCE 400
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;
int pos = 0;
float distance;
 
void setup() {
  Serial.begin (9600);
  myservo.attach(9);
}
 
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); // waits 15ms for the servo to reach the position
    distance = sonar.ping_cm();
  
  // Send results to Serial Monitor
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); 
    distance = sonar.ping_cm();
  
  // Send results to Serial Monitor
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(15);
    
  }
  }
