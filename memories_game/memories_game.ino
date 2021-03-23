const int button1 = 2;
const int button2 = 4;
const int button3 = 7;

const int led1 = 13;
const int led2 = 12;
const int led3 = 10;

int press1;
int pre1;

int press2;
int pre2;

int press3;
int pre3;

int state1;
int state2;
int state3;

int switch1;
int switch2;
int switch3;


int ranNum;

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);
  
  ranNum = random(0,4);
  Serial.println(ranNum);
  delay(1000);
  if(ranNum == 1){
    digitalWrite(led1,HIGH);
    delay(10);
    digitalWrite(led1,LOW);
  }
  else if(ranNum == 2){
    digitalWrite(led2,HIGH);
    delay(10);
    digitalWrite(led2,LOW);
  }
  else if(ranNum == 3){
    digitalWrite(led3,HIGH);
    delay(10);
    digitalWrite(led3,LOW);
  }  
}

void loop() {
  // put your main code here, to run repeatedly:
 
  press1 = digitalRead(button1);
  press2 = digitalRead(button2);
  press3 = digitalRead(button3);
  
  //LED1
  if((press1 == HIGH)&&(pre1==LOW))
  {
    switch1 = HIGH;
    Serial.println("button 1 was pressed!");
  }
  else{
    switch1 = LOW;
  }
  if (switch1 == HIGH)
  {
    if(state1 == LOW)
     {
      state1 = HIGH;
     }
  }

  
  //LED2
  if((press2 == HIGH)&&(pre2==LOW))
  {
    switch2 = HIGH;
    Serial.println("button 2 was pressed!");
  }
  else
  {
    switch2 = LOW;
  }
  if (switch2 == HIGH)
  {
    if(state2 == LOW)
     {
      state2 = HIGH;
     }
  }

  
  //LED3
  if((press3 == HIGH)&&(pre3==LOW))
  {
    switch3 = HIGH;
    Serial.println("button 3 was pressed!");
  }
  else{
    switch3 = LOW;
  }
  if (switch3 == HIGH)
  {
    if(state3 == LOW)
     {
      state3 = HIGH;
     }
  }


  digitalWrite(led1,state1);
  digitalWrite(led2,state2);
  digitalWrite(led3,state3);

  pre1 = press1;
  pre2 = press2;
  pre3 = press3;
  
  bool correct = false;
  if((ranNum == 1)&&(state1 == HIGH))
  {
    correct = true;
  }
  else if  ((ranNum == 2)&&(state2 == HIGH))
  {
    correct = true;
  }
  else if ((ranNum == 3)&&(state3 == HIGH))
  {
    correct = true;
  }

  bool switch_state= false;

  if((switch1==HIGH)||(switch2==HIGH)||(switch3==HIGH))
  {
    switch_state = true;
  }
  
  if ((correct == true)&&(switch_state==true)){
    state1 = HIGH;
    state2 = HIGH;
    state3 = HIGH;
  }
  else if ((correct == false)&&(switch_state==true)){
    if(ranNum == 1){
      state1 = HIGH;
      state2 = LOW;
      state3 = LOW;
    }
    else if(ranNum == 2){
      state1 = LOW;
      state2 = HIGH;
      state3 = LOW;
    }
    else if(ranNum == 3){
      state1 = LOW;
      state2 = LOW;
      state3 = HIGH;
    }  
  }

}
