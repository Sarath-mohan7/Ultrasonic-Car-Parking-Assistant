const int trigPin=4;
const int echoPin=5;
const int led=2;
const int buzz=18;
float distance;
unsigned long duration;
void setup()
 {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);

}

void loop() 
{

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance<=9)
  {
    digitalWrite(led,HIGH);
    digitalWrite(buzz,HIGH);
  }
  if((distance>=9) && (distance<=20))
  {
    digitalWrite(led,HIGH);
    digitalWrite(buzz,HIGH);
    delay(50);
    digitalWrite(led,LOW);
    digitalWrite(buzz,LOW);
    delay(50);
  }
  if((distance>=20) && (distance<=30))
  {
    digitalWrite(led,HIGH);
    digitalWrite(buzz,HIGH);
    delay(200);
    digitalWrite(led,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  }
  if(distance>30)
  {
    digitalWrite(led,LOW);
    digitalWrite(buzz,LOW);
  }

}
