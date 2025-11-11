//Light Stick
//short-press = change color 
//long-press = Switching Mode
//->Constant Light mode: led is always on
//->Blink mode: led is blinking
//->Breathing Light mode: led is fading in and out

const int redLED = 9;
const int greenLED = 10;
const int blueLED = 11;
const int button = 2;

int buttonState = 0;
int lastButtonState = HIGH;
bool buttonPressed = false;
unsigned long pressingTime = 0;
const int longPress = 1500;

unsigned long lastDebounceTime = 0;
const int debounceDelay = 50;

unsigned long blinkTimer = 0;
const int blinkInterval = 500;
bool blinkOn = true;

int brightness = 0;
int fadeAmount = 5;
unsigned long fadeTimer = 0;
const int fadeDelay = 30;

int color = 0;
int currentMode = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  checkButton();
  update();
}

void checkButton() {
   buttonState = digitalRead(button);
   if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
   }

   if ((millis() - lastDebounceTime) > debounceDelay) {
    if (buttonState == LOW && !buttonPressed) {
      pressingTime = millis();
      buttonPressed = true;
    }
    if (buttonState == HIGH && buttonPressed) {
      unsigned long currentTime = millis() - pressingTime;
      if (currentTime < longPress) {
        Serial.println("short click");
        color = color + 1;
        if (color > 6) color = 0;
      } else {
        Serial.println("long press");
        changeMode();
      }
      buttonPressed = false;
    }
   }
   lastButtonState = buttonState;
}

void setRGBColor(int r, int g, int b) {
  analogWrite(redLED, r);
  analogWrite(greenLED, g);
  analogWrite(blueLED, b);
}

void colorList() {
  if (color == 0) {
    setRGBColor(brightness, 255, brightness);//purple
  } else if (color == 1) {
    setRGBColor(brightness, 255, 255);//red
  } else if (color == 2) {
    setRGBColor(brightness, brightness, 255);//yellow
  } else if (color == 3) {
    setRGBColor(255, brightness, 255);//green
  } else if (color == 4) {
    setRGBColor(255, brightness, brightness);//cyan
  } else if (color == 5) {
    setRGBColor(255, 255, brightness);//blue
  } else if (color == 6) {
    setRGBColor(brightness, brightness, brightness);//white
  }
}

void changeMode() {
  currentMode = currentMode + 1;
  if (currentMode >= 3) {
    currentMode = 0;
  }

  if (currentMode == 0) {
    Serial.println(" -> Steady Mode");
  }

  if (currentMode == 1) {
    blinkTimer = 0;
    blinkOn = true;
    Serial.println(" -> Blink Mode");
  }

   if (currentMode == 2) {
    Serial.println(" -> Fade Mode");
  }
}

void update() {
  unsigned long currentTime = millis();

  if (currentMode == 0) {
    brightness = 0;
    colorList();
  }

  if (currentMode == 1) {
    if (currentTime - blinkTimer > blinkInterval) {
      blinkOn = !blinkOn;
      blinkTimer = currentTime;
    }
    if (blinkOn) {
      colorList();
    } else {
      setRGBColor(255, 255, 255);
    }
  }

  if (currentMode == 2) {
    if(currentTime -fadeTimer >= fadeDelay) {
      fadeTimer = currentTime;
      brightness += fadeAmount;
      if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    colorList();
    }
  }
}