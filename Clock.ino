  int firstD = 0;
  int secondD = 1;
  int thirdD = 2;
  int fourthD = 3;
  int tLeft =5;
  int tTop = 6;
  int tRight = 7;
  int bLeft = 8;
  int bBottom = 9;
  int bPeriod = 10;
  int bRight = 11;
  int bMiddle= 12;
  
  int buttonHour = 16;
  int buttonMinute = 15;

  int timer = 13;
  
  int slot1=0;
  int slot2=0;
  int slot3=7;
  int slot4=0;
  
  int second = 0;
  int t=0;
void setup() {
 
  pinMode(firstD,OUTPUT);
  pinMode(secondD,OUTPUT);
  pinMode(thirdD,OUTPUT);
  pinMode(fourthD,OUTPUT);
  pinMode(tLeft,OUTPUT);
  pinMode(tTop,OUTPUT);
  pinMode(tRight,OUTPUT);
  pinMode(bMiddle,OUTPUT);
  pinMode(bLeft,OUTPUT); 
  pinMode(bBottom,OUTPUT);
  pinMode(bRight,OUTPUT);
  pinMode(bPeriod,OUTPUT);

  pinMode(timer,INPUT);
  pinMode(buttonHour,INPUT);
  pinMode(buttonMinute,INPUT);

}

void loop() {

  if(digitalRead(buttonMinute) == HIGH ){
   delay(30);
    
    if(digitalRead(buttonMinute) == LOW){
      slot1++; 
    }
  }
 
  if(digitalRead(buttonHour) == HIGH){
    delay(30);
    
    if(digitalRead(buttonHour) == LOW){
      slot3++;
    }
  }
  
  if((digitalRead(timer) == HIGH)&&(t==0)){
    t=1;
    second++;
  }
  if((digitalRead(timer) == LOW)&&(t==1)){
    t=0;
  }
  
  if(second>=63){
    second=0;
    slot1++;
    }
  if(slot1>9){
    slot1=0;
    slot2++;
  }
  
  if(slot4==1&&slot3==2&&slot2==6){
    slot4=0;
    slot3=1;
    slot2=0;
  }
  if(slot2>5){
    slot2=0;
    slot3++;
  }
  
  if(slot3>9){
    slot3=0;
    slot4++;
  }
  if(slot4==1&&slot3>2){
    slot4=0;
    slot3=1;
    //slot2=0;
    //slot1=0;
    }
  
    
  cTime(slot4,slot3,slot2,slot1);
 

}
void cTime (int one, int two, int three, int four){
  numberDisplay(firstD,one);
  delay(1);
  numberDisplay(secondD,two);
  delay(1);
  numberDisplay(thirdD,three);
  delay(1);
  numberDisplay(fourthD,four);
  delay(1);
}
void numberDisplay(int location,int number){
  digitalWrite(firstD,HIGH);
  digitalWrite(secondD,HIGH);
  digitalWrite(thirdD,HIGH);
  digitalWrite(fourthD,HIGH);
  digitalWrite(tTop,LOW);
  digitalWrite(tLeft,LOW);
  digitalWrite(tRight,LOW);
  digitalWrite(bMiddle,LOW);
  digitalWrite(bLeft,LOW);
  digitalWrite(bRight,LOW);
  digitalWrite(bBottom,LOW);
  switch(number){
    case 0:
    digitalWrite(location,LOW);
    digitalWrite(tTop,HIGH);
    digitalWrite(tLeft,HIGH);
    digitalWrite(tRight,HIGH);
    digitalWrite(bLeft,HIGH);
    digitalWrite(bRight,HIGH);
    digitalWrite(bBottom,HIGH);
    break;
    case 1:
    digitalWrite(location,LOW);
    digitalWrite(tRight,HIGH);
    digitalWrite(bRight,HIGH);
    break;
    case 2:
    digitalWrite(location,LOW);
    digitalWrite(tTop,HIGH);
    digitalWrite(tRight,HIGH);
    digitalWrite(bMiddle,HIGH);
    digitalWrite(bLeft,HIGH);
    digitalWrite(bBottom,HIGH);
    break;
    case 3:
    digitalWrite(location,LOW);
    digitalWrite(tTop,HIGH);
    digitalWrite(tRight,HIGH);
    digitalWrite(bMiddle,HIGH);
    digitalWrite(bRight,HIGH);
    digitalWrite(bBottom,HIGH);
    break;
    case 4:
    digitalWrite(location,LOW);
    digitalWrite(tLeft,HIGH);
    digitalWrite(tRight,HIGH);
    digitalWrite(bMiddle,HIGH);
    digitalWrite(bRight,HIGH);
    break;
    case 5:
    digitalWrite(location,LOW);
    digitalWrite(tTop,HIGH);
    digitalWrite(tLeft,HIGH);
    digitalWrite(bMiddle,HIGH);
    digitalWrite(bRight,HIGH);
    digitalWrite(bBottom,HIGH);
    break;
    case 6:
    digitalWrite(location,LOW);
    digitalWrite(tTop,HIGH);
    digitalWrite(tLeft,HIGH);
    digitalWrite(bMiddle,HIGH);
    digitalWrite(bRight,HIGH);
    digitalWrite(bLeft,HIGH);
    digitalWrite(bBottom,HIGH);
    break;
    case 7:
    digitalWrite(location,LOW);
    digitalWrite(tTop,HIGH);
    digitalWrite(tRight,HIGH);
    digitalWrite(bRight,HIGH);
    break;
    case 8:
    digitalWrite(location,LOW);
    digitalWrite(tTop,HIGH);
    digitalWrite(tLeft,HIGH);
    digitalWrite(tRight,HIGH);
    digitalWrite(bLeft,HIGH);
    digitalWrite(bRight,HIGH);
    digitalWrite(bBottom,HIGH);
    digitalWrite(bMiddle,HIGH);
    break;
    case 9:
    digitalWrite(location,LOW);
    digitalWrite(tTop,HIGH);
    digitalWrite(tLeft,HIGH);
    digitalWrite(tRight,HIGH);
    digitalWrite(bRight,HIGH);
    digitalWrite(bBottom,HIGH);
    digitalWrite(bMiddle,HIGH);
    break;
    
    }
  }
