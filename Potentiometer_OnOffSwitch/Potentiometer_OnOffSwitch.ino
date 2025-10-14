int redLED = 9;
int greenLED = 10;
int blueLED = 11;
int sensor = A0;

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensor);
  Serial.println(sensorValue);

  if (sensorValue > 500) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
  }
  else {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, HIGH);
  }
  delay(1);
}
