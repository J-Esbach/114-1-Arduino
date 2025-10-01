const int pushButton = 2;
const int rLedPin = 3;
const int gLedPin = 4;
const int bLedPin = 5;

int buttonState = 0;
int ledColor = 0;

String color;
bool pressed = false;

void setup() {
  Serial.begin(9600);

  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
  pinMode(pushButton, INPUT);
}

void loop() {
  buttonState = digitalRead(pushButton);
  
  if (buttonState == LOW) {
    ledColor = ledColor + 1;
    delay(100);
  }

  if (buttonState == LOW && !pressed) {
    pressed = true;
  } else if (buttonState == HIGH && pressed) {
    pressed = false;
    Serial.println(color);
  }

  if (ledColor == 0) { //no light
    color = "noLight";
    digitalWrite(rLedPin, HIGH);
    digitalWrite(gLedPin, HIGH);
    digitalWrite(bLedPin, HIGH);
  }  else if (ledColor == 1) { //red
  color = "red";
    digitalWrite(rLedPin, LOW);
    digitalWrite(gLedPin, HIGH);
    digitalWrite(bLedPin, HIGH);
  }  else if (ledColor == 2) { //green
  color = "green";
    digitalWrite(rLedPin, HIGH);
    digitalWrite(gLedPin, LOW);
    digitalWrite(bLedPin, HIGH);
  }  else if (ledColor == 3) { //blue
  color = "blue";
    digitalWrite(rLedPin, HIGH);
    digitalWrite(gLedPin, HIGH);
    digitalWrite(bLedPin, LOW);
  } else if (ledColor == 4) { //yellow
  color = "yellow";
    digitalWrite(rLedPin, LOW);
    digitalWrite(gLedPin, LOW);
    digitalWrite(bLedPin, HIGH);
  } else if (ledColor == 5) { //purple
  color = "purple";
    digitalWrite(rLedPin, LOW);
    digitalWrite(gLedPin, HIGH);
    digitalWrite(bLedPin, LOW);
  } else if (ledColor == 6) { //cyan
  color = "cyan";
    digitalWrite(rLedPin, HIGH);
    digitalWrite(gLedPin, LOW);
    digitalWrite(bLedPin, LOW);
  } else if (ledColor == 7) { //white
  color = "white";
    digitalWrite(rLedPin, LOW);
    digitalWrite(gLedPin, LOW);
    digitalWrite(bLedPin, LOW);
  } else if (ledColor == 8) {
    ledColor = 0;
  }
}
