const int buttonPin =2;
const int ledPin = 13;
int buttonState = 0;
int previousState = 0;
int ledState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if ((previousState == LOW) && (buttonState == HIGH)&& (ledState == LOW)){
    ledState = HIGH;
  }
  else if((previousState == LOW) && (buttonState == HIGH)&& (ledState == HIGH)){
    ledState = LOW;
  }
  previousState = buttonState;
  digitalWrite(ledPin,ledState);
}
