const int redLED = 9;
const int greenLED = 10;
const int blueLED = 11;

int brightness = 0; //max. 255
int fadeAmount = 5;
int ledColor = 0;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {

  if (ledColor == 0) {
    analogWrite(redLED, brightness);
    analogWrite(greenLED, 255);
    analogWrite(blueLED, 255);
  }
  if (ledColor == 1) {
    analogWrite(redLED, 255);
    analogWrite(greenLED, brightness);
    analogWrite(blueLED, 255);
  }
  if (ledColor == 2) {
    analogWrite(redLED, 255);
    analogWrite(greenLED, 255);
    analogWrite(blueLED, brightness);
  }

  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    if (brightness >= 225) {
      ledColor = ledColor + 1;
      if (ledColor > 2) ledColor = 0;
    }
  }
 
  
  delay(30);
}
