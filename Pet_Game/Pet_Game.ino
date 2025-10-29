//Petting-Game
//Moods - red:sad(0 points) green:neutral(10 points) blue:happy(20 points) ->continuous color sprectrum
//Beginning = neutral mood and 10 points
//each press = 1 point (max. 20 points)
//if not pressing for 5 sec. ->1 sec. = -1 point

int redLED = 9;
int greenLED = 10;
int blueLED = 11;
int button = 2;

int mood = 0;
const int neutralMood = 10;
unsigned long previousMillis = 0;
int fadingDirection = 1;

int buttonState = 0;
bool buttonPressed = false;

unsigned long touchedTimer = 0;
unsigned long reducedTimer = 0;
const long unTouchedInterval = 5000;
const long reducedInterval = 1000;

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(button, INPUT);

  mood = neutralMood;
}

void loop() {
  //MoodColor
  moodLight(mood);
  Serial.println(mood);

  //Patting
  Serial.print(buttonState);
  buttonState = digitalRead(button);
  if (buttonState == HIGH && !buttonPressed) {
    mood = mood + 1;
    if (mood > 20) {
      mood = 20;
    }
    touchedTimer = millis();
    buttonPressed = true;
  }
  if (buttonState == LOW && buttonPressed) {
    buttonPressed = false;
  }

  //Time
  unsigned long currentMillis = millis();
  if (currentMillis - touchedTimer > unTouchedInterval) {
    if (currentMillis - reducedTimer > reducedInterval) {
      mood = mood -1;
      if (mood < 0) {
        mood = 0;
      }
      reducedTimer = currentMillis;
    }
  }
}

void moodLight(int state) {
  float brightnessInterval = 255 / 10.0;
  if (state >= neutralMood) {
    analogWrite(redLED, 255);
    analogWrite(greenLED, brightnessInterval * (state - neutralMood));
    analogWrite(blueLED, 255 - brightnessInterval * (state - neutralMood));
  }
  else {
    analogWrite(redLED, 255 - brightnessInterval * (neutralMood - state));
    analogWrite(greenLED, brightnessInterval * (neutralMood - state));
    analogWrite(blueLED, 255);
  }
}