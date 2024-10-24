const int buttonPin = 8;
const int redLedPin = 13;
const int greenLedPin = 12;
const int yellowLedPin = 11;

int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);

}

void loop() {
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH){
    digitalWrite(redLedPin, HIGH);
    delay(500);
    digitalWrite(redLedPin, LOW);

    digitalWrite(greenLedPin, HIGH);
    delay(500);
    digitalWrite(greenLedPin, LOW);

    digitalWrite(yellowLedPin, HIGH);
    delay(500);
    digitalWrite(yellowLedPin, LOW);
  }
  else{
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
  }
}


    
      
