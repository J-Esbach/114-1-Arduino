int ledRed = 3;
int ledGreen = 5;
int ledBlue = 6;

void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    setColor(255-i, i, 0);
    delay(10);
  }
 for (int i = 0; i <= 255; i++) {
    setColor(0, 255-i, i);
    delay(10);
  }
  for (int i = 0; i <= 255; i++) {
    setColor(i, 0, 255-i);
    delay(10);
  }
}

void setColor(int r, int g, int b) {
  analogWrite(ledRed, 255 - r);
  analogWrite(ledGreen, 255 - g);
  analogWrite(ledBlue, 255 - b);

}
