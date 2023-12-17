#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myservo;
void motor();
int pos = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 10;
const int echoPin = 9;
const int onPin = 3;
const int buzzer = 4;



long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  // SENSOR CODE
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(onPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  myservo.attach(11);
  Serial.begin(9600);

  // initialize the LCD
	// lcd.begin();

	// Turn on the blacklight and print a message.
	// lcd.print("Hello, world!");
}

void loop() {
  lcd.begin();
  lcd.backlight();
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delay(500);

  digitalWrite(trigPin, HIGH);
  delay(400);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  Serial.print("Distance is: ");
  Serial.println(distance);
  
  
	lcd.print("Distance:");
  lcd.print(distance);
  if(distance <= 20){
    digitalWrite(onPin, HIGH);
    tone(buzzer, 50);
    motor();
    // delay(500);
    digitalWrite(onPin, LOW);
    noTone(buzzer);
    
  }
    
}

void motor(){

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }

}
