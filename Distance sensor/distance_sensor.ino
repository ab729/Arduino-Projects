const int ledpin1 = 4;
const int ledpin2 = 13;
const int trigpin = 8;
const int echopin = 10;

long duration;
int distance ;
int safetyDistance;


void setup()
{
  pinMode (trigpin , OUTPUT);
  pinMode (echopin , INPUT);
  pinMode (ledpin1 , OUTPUT);
  pinMode (ledpin2 , OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  digitalWrite(trigpin , LOW);
  delayMicroseconds (2);

  digitalWrite(trigpin , HIGH);
  delayMicroseconds(5);
  digitalWrite(trigpin , LOW);

  duration = pulseIn(echopin , HIGH );
  
  distance = duration *0.034/2;
  safetyDistance = distance;

  if(safetyDistance <= 10)
  {
    digitalWrite(ledpin1 , LOW);
    digitalWrite(ledpin2 , HIGH);
  }

  else
  {
    digitalWrite(ledpin2 , LOW);
    digitalWrite(ledpin1 , HIGH);
  }
  

  Serial.print ("Distance = ");
  Serial.print (distance);





  
}
