const int pushButton = 2;
const int rLedPin = 3;
const int gLedPin = 4;
const int bLedPin = 5;

int buttonState = 0;
int lastButtonState = HIGH;
bool buttonPressed = false;

unsigned long lastClickTime = 0;
const unsigned long doubleClickDelay = 400;
bool ledEnabled = true;

int ledColor = 0;
String color;

void setup() {
  Serial.begin(9600);

  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
  pinMode(pushButton, INPUT);
}

void loop() {
  buttonState = digitalRead(pushButton);

  if (lastButtonState == HIGH && buttonState == LOW) {
    unsigned long now = millis();

    if(now - lastClickTime <= doubleClickDelay) {
      ledEnabled = !ledEnabled;
      lastClickTime = 0;
    } else {
      ledColor = ledColor + 1;
      if (ledColor > 6) ledColor = 0;
      lastClickTime = now;
    }
  }
  lastButtonState = buttonState;

  if (ledEnabled) {
    if (ledColor == 0) { //red
      color = "red";
      digitalWrite(rLedPin, LOW);
      digitalWrite(gLedPin, HIGH);
      digitalWrite(bLedPin, HIGH);
    }  else if (ledColor == 1) { //green
      color = "green";
      digitalWrite(rLedPin, HIGH);
      digitalWrite(gLedPin, LOW);
      digitalWrite(bLedPin, HIGH);
    }  else if (ledColor == 2) { //blue
      color = "blue";
      digitalWrite(rLedPin, HIGH);
      digitalWrite(gLedPin, HIGH);
      digitalWrite(bLedPin, LOW);
    } else if (ledColor == 3) { //yellow
      color = "yellow";
      digitalWrite(rLedPin, LOW);
      digitalWrite(gLedPin, LOW);
      digitalWrite(bLedPin, HIGH);
    } else if (ledColor == 4) { //purple
      color = "purple";
      digitalWrite(rLedPin, LOW);
      digitalWrite(gLedPin, HIGH);
      digitalWrite(bLedPin, LOW);
    } else if (ledColor == 5) { //cyan
      color = "cyan";
      digitalWrite(rLedPin, HIGH);
      digitalWrite(gLedPin, LOW);
      digitalWrite(bLedPin, LOW);
    } else if (ledColor == 6) { //white
      color = "white";
      digitalWrite(rLedPin, LOW);
      digitalWrite(gLedPin, LOW);
      digitalWrite(bLedPin, LOW);
    }
  } else {
    color = "off";
    digitalWrite(rLedPin, HIGH);
    digitalWrite(gLedPin, HIGH);
    digitalWrite(bLedPin, HIGH);
  }

  Serial.print("Current Color: ");
  Serial.println(color);
}
