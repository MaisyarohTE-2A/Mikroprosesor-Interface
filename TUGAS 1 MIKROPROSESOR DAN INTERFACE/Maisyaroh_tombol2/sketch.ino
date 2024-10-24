const int button1 = 7;
const int button2 = 6;
const int greenLedPin = 13;
const int yellowLedPin = 12;
const int redLedPin = 11;

int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, LOW);

}

void loop() {
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);

  if(buttonState1 == HIGH){
    digitalWrite(greenLedPin, HIGH);
    delay(300);
    digitalWrite(greenLedPin, LOW);

    digitalWrite(yellowLedPin, HIGH);
    delay(300);
    digitalWrite(yellowLedPin, LOW);

    digitalWrite(redLedPin, HIGH);
    delay(300);
    digitalWrite(redLedPin, LOW);
  }
 if(buttonState2 == HIGH){
    digitalWrite(redLedPin, HIGH);
    delay(300);
    digitalWrite(redLedPin, LOW);

    digitalWrite(yellowLedPin, HIGH);
    delay(300);
    digitalWrite(yellowLedPin, LOW);

    digitalWrite(greenLedPin, HIGH);
    delay(300);
    digitalWrite(greenLedPin, LOW);
  }
}
