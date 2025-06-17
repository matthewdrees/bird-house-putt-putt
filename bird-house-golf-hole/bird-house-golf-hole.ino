// Converted a birdhouse into a putt putt golf hole. When the ball goes through
// a notch in the front a buzzer sounds and a LED strip lights up.

// Input pin, connected to 5V via 10Kohm resistor. Connected to the mechanical
// swing arm in the house to detect golf ball.
const int golfInputPin = 2;

// LED strip has separate blue, red, and green LED controls. Each draws 2-3
// milliamps. Inverse logic: LOW = on, HIGH = off.
const int blueLedPin = 4;
const int redLedPin = 5;
const int greenLedPin = 6;

const int buzzerPin = 7;

void setup() {
  // inputs
  pinMode(golfInputPin, INPUT);
  
  // outputs
  pinMode(buzzerPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  // the LEDs on the house are inverse logic (HIGH is off)
  digitalWrite(blueLedPin, HIGH);
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, HIGH);
}

void doPinsOnOff(int pin, unsigned long msOn, unsigned long msOff) {
    digitalWrite(pin, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(msOn);
    digitalWrite(pin, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(msOff);  
}

void doAllPinsOnOff(unsigned long msOn, unsigned long msOff) {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(blueLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    delay(msOn);

    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(blueLedPin, HIGH);
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, HIGH);
    delay(msOff);  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(golfInputPin) == LOW) {
    
    doPinsOnOff(blueLedPin, 100, 50);
    doPinsOnOff(redLedPin,100, 50);
    doPinsOnOff(greenLedPin, 100, 50);
    doAllPinsOnOff(500, 0);
  }
}
