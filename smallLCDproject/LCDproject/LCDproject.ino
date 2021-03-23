#include <LiquidCrystal.h>  
#include<string.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   

const int Contrast= 20;

const int button1 = 7;
String inputString= "";

int pressed, pre;

signed short minutes, seconds;
char timeline[16];
//char stopped[16];
void setup() {
  // put your setup code here, to run once:
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.print("Press the button to reset!");
  pinMode(button1, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pressed = digitalRead(button1);

  if((pre == LOW) && (pressed== HIGH)){
    lcd.setCursor(0,1);
    sprintf(timeline,"%0.2d mins %0.2d secs", minutes, seconds);
    lcd.print(timeline);
    minutes = 0;
    seconds = 0;
  }

  lcd.setCursor(0, 0);
  sprintf(timeline,"%0.2d mins %0.2d secs", minutes, seconds);
  lcd.print(timeline);

  delay(1000);
  seconds++;
  
  if (seconds == 60)
  {
    seconds = 0;
    minutes ++;
  }
  pre = pressed;
}

void serialEvent3(){
  while(Serial.available()){
    char in = (char)Serial.read();
    inputString += in;
    if (inputString == "RESET"){
      pinMode(8, OUTPUT);  
      digitalWrite(8, LOW);
    }
  }
}
