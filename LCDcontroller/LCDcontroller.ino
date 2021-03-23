#include <LiquidCrystal.h>  
#include<string.h>

const int button = 7;

int press1;

int state ;

int pre1;

int Contrast=20;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   

void setup()
{ 
  analogWrite(6,Contrast);
  lcd.begin(16, 2);

  pinMode(button, INPUT);  
  const char* str = "This is a very long string";
  lcd.print(str);
  delay(1000);

}  

void loop()
{    
  press1 = digitalRead(button);

  if((press1 == HIGH)&&(pre1==LOW))
  {
    if (state == LOW){
      state = HIGH;  
    }   
    else if (state == HIGH){
      state = LOW;  
    }
  }

  if (state == HIGH)
  {
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
      lcd.scrollDisplayRight();
      delay(200);
    }
  }
  if (state == LOW){
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(200);
    }
  }
  
  pre1 = press1;
}
