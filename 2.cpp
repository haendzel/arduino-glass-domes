#include <VarSpeedServo.h> 

VarSpeedServo myservo1;    
VarSpeedServo myservo2;

   int trigPin = 9;
   int echoPin = 10;
   float pingTime; 
   float targetDistance; 
   float speedOfSound=776.5; //Speed of sound in miles per hour when temp is 77 degrees.
   
void setup() {
  myservo1.attach(8);
  myservo2.attach(7);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
    int duration, distance,pos=0,i;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(1);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = abs((duration/2) / 29);

    Serial.print(distance);
    Serial.println(" cm");
    
    if (distance <= 150)
    {
    myservo1.write(0);
    delay(15);
    myservo2.write(90);
    delay(15);      
    myservo1.write(180);
    delay(15);
    myservo2.write(150);
    delay(15);       
    }
    else {
    delay(0);
    }         
}          
