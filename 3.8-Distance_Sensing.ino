long duration;
int distance;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);
  duration=pulseIn(2, HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm ");
  
  
  if (distance < 5) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    tone(11, 1000);
   
  }
  else if (distance < 10 && distance >= 5) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    noTone(11);
  }
  else if (distance >= 10 && distance <= 30) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    noTone(11);
  }
  else if (distance > 30) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    noTone(11);
  }
  delay(750);

}
