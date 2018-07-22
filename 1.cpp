
#include <Servo.h> 

Servo myservo1;    

   int trigPin = 9;
   int echoPin = 10;
   float pingTime; 
   float targetDistance; 
   float speedOfSound=776.5; //Speed of sound in miles per hour when temp is 77 degrees.
   
void setup() {
  myservo1.attach(8);
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
    myservo1.write(90);    
    delay(300);
    myservo1.write(0);       
    delay(300);

    if (distance <= 20)
    {
    myservo1.write(90);    
    delay(10);
    myservo1.write(0);       
    delay(10);
    }
    }
    else {
    delay(0);
    }         
}