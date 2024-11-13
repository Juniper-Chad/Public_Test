

#define encoder0PinA 35
#define encoder0PinB 36

#define encoder1PinA 37
#define encoder1PinB 38

#define motorPin1 11
#define motorPin2 10
#define motorPin3 12
#define motorPin4 13
#define pwmPin1 9
#define pwmPin2 14

volatile long encoder0Pos = 0;
volatile long encoder1Pos = 0;

const int freq = 500;
const int ledChannel1 = 1;
const int ledChannel2 = 2;
const int resolution = 8;

byte Output1, Output2;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(pwmPin1, OUTPUT);

  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(pwmPin2, OUTPUT);

  ledcSetup(ledChannel1, freq, resolution);
  ledcSetup(ledChannel2, freq, resolution);

  ledcAttachPin(pwmPin1, ledChannel1);
  ledcAttachPin(pwmPin2, ledChannel2);

  pinMode(encoder0PinA, INPUT_PULLUP);
  pinMode(encoder0PinB, INPUT_PULLUP);
  pinMode(encoder1PinA, INPUT_PULLUP);
  pinMode(encoder1PinB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoder0PinA), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder0PinB), doEncoderB, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder1PinA), doEncoderC, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder1PinB), doEncoderD, CHANGE);

  delay(2000);

  Serial.begin(115200);
}

void loop() {

  for (int ramp = 0; ramp <= 255; ramp += 5) {
    ledcWrite(ledChannel1, ramp);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    ledcWrite(ledChannel2, ramp);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);

    Serial.print(encoder0Pos);
    Serial.print(", ");
    Serial.print(encoder1Pos);
    Serial.print(", ");
    Serial.println(ramp);
    delay(100);
  }

  for (int ramp = 255; ramp >= 0; ramp -= 5) {
    ledcWrite(ledChannel1, ramp);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    ledcWrite(ledChannel2, ramp);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);

    Serial.print(encoder0Pos);
    Serial.print(", ");
    Serial.print(encoder1Pos);
    Serial.print(", ");
    Serial.println(ramp);
    delay(100);
  }
    for (int ramp = 0; ramp <= 255; ramp += 5) {
    ledcWrite(ledChannel1, ramp);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    ledcWrite(ledChannel2, ramp);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);

    Serial.print(encoder0Pos);
    Serial.print(", ");
    Serial.print(encoder1Pos);
    Serial.print(", ");
    Serial.println(ramp);
    delay(100);
  }
    for (int ramp = 255; ramp >= 0; ramp -= 5) {
    ledcWrite(ledChannel1, ramp);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    ledcWrite(ledChannel2, ramp);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);

    Serial.print(encoder0Pos);
    Serial.print(", ");
    Serial.print(encoder1Pos);
    Serial.print(", ");
    Serial.println(ramp);
    delay(100);
  }
}


void doEncoderA() {
  if (digitalRead(encoder0PinA) == HIGH) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos = encoder0Pos + 1;
    } else {
      encoder0Pos = encoder0Pos - 1;
    }
  } else {
    if (digitalRead(encoder0PinB) == HIGH) {
      encoder0Pos = encoder0Pos + 1;
    } else {
      encoder0Pos = encoder0Pos - 1;
    }
  }
}
void doEncoderB() {
  if (digitalRead(encoder0PinB) == HIGH) {
    if (digitalRead(encoder0PinA) == HIGH) {
      encoder0Pos = encoder0Pos + 1;
    } else {
      encoder0Pos = encoder0Pos - 1;
    }
  } else {
    if (digitalRead(encoder0PinA) == LOW) {
      encoder0Pos = encoder0Pos + 1;
    } else {
      encoder0Pos = encoder0Pos - 1;
    }
  }
}

//****encoder 2

void doEncoderC() {
  if (digitalRead(encoder1PinA) == HIGH) {
    if (digitalRead(encoder1PinB) == LOW) {
      encoder1Pos = encoder1Pos + 1;
    } else {
      encoder1Pos = encoder1Pos - 1;
    }
  } else {
    if (digitalRead(encoder1PinB) == HIGH) {
      encoder1Pos = encoder1Pos + 1;
    } else {
      encoder1Pos = encoder1Pos - 1;
    }
  }
}
void doEncoderD() {
  if (digitalRead(encoder1PinB) == HIGH) {
    if (digitalRead(encoder1PinA) == HIGH) {
      encoder1Pos = encoder1Pos + 1;
    } else {
      encoder1Pos = encoder1Pos - 1;
    }
  } else {
    if (digitalRead(encoder1PinA) == LOW) {
      encoder1Pos = encoder1Pos + 1;
    } else {
      encoder1Pos = encoder1Pos - 1;
    }
  }
}
