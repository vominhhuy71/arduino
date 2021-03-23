const int LED = 13;
int input = 1000;

class Blink{
  public:
    void Blinking(int led, int timeInterval){
      digitalWrite(led,HIGH);
      delay(timeInterval);
      digitalWrite(led,LOW);
      delay(timeInterval);
    }
};

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blink blink;
  
  blink.Blinking(13,input);
}
