const int buttonPin1 = 5; 
const int buttonPin2 = 6;
const int buttonPin3 = 7;  
const int redLedPin = 13; 
const int yellowLedPin = 12;  
const int greenLedPin = 11;   

bool button1Pressed = false;
bool button2Pressed = false;
bool button3Pressed = false;

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(redLedPin, OUTPUT);  
  pinMode(yellowLedPin, OUTPUT);   
  pinMode(greenLedPin, OUTPUT);    
}

void loop() {
  if (digitalRead(buttonPin1) == HIGH && !button1Pressed) {
    button1Pressed = true; 
    ledSequence(redLedPin, yellowLedPin, greenLedPin); 
  } 
  else if (digitalRead(buttonPin2) == HIGH && !button2Pressed) {
    button2Pressed = true; 
    ledSequence(greenLedPin, yellowLedPin, redLedPin); 
  } 
  else if (digitalRead(buttonPin3) == HIGH && !button3Pressed) {
    button3Pressed = true; 
    ledSequence(redLedPin, yellowLedPin, greenLedPin); 
    ledSequence(greenLedPin, yellowLedPin, redLedPin); 
  } 
  else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }

  
  resetFlags();
}

void ledSequence(int led1, int led2, int led3) {
  digitalWrite(led1, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(200);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(200);
  digitalWrite(led3, LOW);
}

void resetFlags() {
  if (digitalRead(buttonPin1) == LOW) button1Pressed = false;
 if (digitalRead(buttonPin2) == LOW) button2Pressed = false;
  if (digitalRead(buttonPin3) == LOW) button3Pressed = false;
}
