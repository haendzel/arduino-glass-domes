#include <Servo.h>

Servo myservo1;
Servo myservo2;// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int trigPin = 11;
int echoPin = 12;
float pingTime; 
float targetDistance; 
float speedOfSound=776.5; //Speed of sound in miles per hour when temp is 77 degrees.

void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 }

void loop() {
    int duration, distance,pos=0,i;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = abs((duration/2) / 29);

    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= 50)
    {
     myservo1.write(180);
     myservo2.write(180);    
    delay(200);
     myservo1.write(0);
     myservo2.write(0);       
    delay(200);
    }
    if (distance <= 20)
    {
     myservo1.write(180);
     myservo2.write(180);    
    delay(300);
     myservo1.write(0);
     myservo2.write(0);       
    delay(300);
    }
    
    else {
    delay(0);
    }
}