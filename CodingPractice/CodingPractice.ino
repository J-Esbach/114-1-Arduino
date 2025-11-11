const int buttonPin = 2;
const int ledPin = 3;

int buttonState = 0;
int lastButtonState = HIGH;
bool buttonPressed = false;
unsigned long pressingTime = 0;

unsigned long lastDebounceTime = 0;
const int debounceDelay = 50;

unsigned long previousMillis = 0;
unsigned long blinkInterval = 250;
bool blinkOn = true;

int mode = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // interner Pull-up
  digitalWrite(ledPin, HIGH);       // Start steady ON
  Serial.begin(9600);
}

void loop() {
  checkButton();

  // LED Verhalten steuern
  if (mode == 0) {
    digitalWrite(ledPin, LOW); // steady ON
  } else {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;
      blinkOn = !blinkOn;
      digitalWrite(ledPin, blinkOn ? HIGH : LOW);
    }
  }
}

void checkButton() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (buttonState == LOW && !buttonPressed) {
      pressingTime = millis();
      buttonPressed = true;
    }

    if (buttonState == HIGH && buttonPressed) {
      buttonPressed = false;
      Serial.println("clicked");
      changeMode();
    }
  }

  lastButtonState = buttonState;
}

void changeMode() {
  mode = (mode + 1) % 4; // 0 -> 1 -> 2 -> 3 -> 0

  // Blink-Intervalle setzen
  if (mode == 1) blinkInterval = 1000;  // slow
  else if (mode == 2) blinkInterval = 600; // medium
  else if (mode == 3) blinkInterval = 250; // fast
  else if (mode == 0) digitalWrite(ledPin, LOW); // steady
}
