int greenLED = 10;
int redLED = 9;
int blueLED = 11;
int button = 2;

int ledColor = 0;
int buttonState = 0;
bool buttonPressed = false;
unsigned long previousMillis = 0;
const long interval = 1000;
bool ledColorOrder = true;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED,OUTPUT);
  pinMode(blueLED, OUTPUT);

  pinMode(button, INPUT);
}

void loop() {
  buttonState = digitalRead(button);
  if (buttonState == HIGH && !buttonPressed) {
    ledColorOrder = !ledColorOrder;
    buttonPressed = true;
  }
  if (buttonState == LOW && buttonPressed) {
    buttonPressed = false;
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledColorOrder == true) {
      ledColor = ledColor + 1;
      if (ledColor > 3) ledColor = 0;
    }
    else {
      ledColor = ledColor - 1;
      if (ledColor < 0) ledColor = 3; 
    }
  }

  if (ledColor == 0) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, HIGH);
  }
  else if (ledColor == 1) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
  }
  else if (ledColor == 2) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
  }
  if (ledColor == 3) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
  }
}
