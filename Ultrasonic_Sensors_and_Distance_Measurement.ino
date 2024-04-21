#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 3, 4, 5, 6);
const int trigPin = 8;
const int echoPin = 9;
long duration;
int distanceCm, distanceInch;

void setup() {
  lcd.begin(16,2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm= duration*0.034/2;
  distanceInch = duration * 0.01330 / 2;
  lcd.setCursor(0,0); 
  lcd.print("Distance: "); 
  lcd.print(distanceCm); 
  lcd.print(" cm");
  delay(10);
  lcd.setCursor(0,1);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" in ");
  delay(10);
}
