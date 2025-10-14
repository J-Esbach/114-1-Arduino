const int ledRed = 9; //orange
const int ledGreen = 10; //brown
const int ledBlue = 11; //yelllow

int ledState = LOW;
int ledColor = 0;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

void loop() {
  Serial.println(ledColor);
  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if(ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
      ledColor = ledColor + 1;
      if (ledColor > 6) ledColor = 0;
    }
  }

  if (ledColor == 0)  {
    if (ledState == LOW) {
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH); 
      digitalWrite(ledBlue, HIGH);
    } else {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, HIGH); 
    digitalWrite(ledBlue, HIGH);
    }
  }
  else if (ledColor == 1) {
    if (ledState == LOW) {
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW); 
      digitalWrite(ledBlue, HIGH);
    } else {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, HIGH); 
    digitalWrite(ledBlue, HIGH);
    }
  }
  else if (ledColor == 2) {
    if (ledState == LOW) {
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, HIGH); 
      digitalWrite(ledBlue, LOW);
    } else {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, HIGH); 
    digitalWrite(ledBlue, HIGH);
    }
  }     
  else if (ledColor == 3) {
    if (ledState == LOW) {
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, LOW); 
      digitalWrite(ledBlue, HIGH);
    } else {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, HIGH); 
    digitalWrite(ledBlue, HIGH);
    }
  }     
  else if (ledColor == 4) {
    if (ledState == LOW) {
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH); 
      digitalWrite(ledBlue, LOW);
    } else {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, HIGH); 
    digitalWrite(ledBlue, HIGH);
    }
  }  
  else if (ledColor == 5) {
    if (ledState == LOW) {
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW); 
      digitalWrite(ledBlue, LOW);
    } else {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, HIGH); 
    digitalWrite(ledBlue, HIGH);
    }
  }
  else if (ledColor == 6) {
    if (ledState == LOW) {
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, LOW); 
      digitalWrite(ledBlue, LOW);
    } else {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, HIGH); 
    digitalWrite(ledBlue, HIGH);
    }
  }
}
