#include <Servo.h>
#include <LiquidCrystal.h>


const int gate1=A0;
const int gate2=A1;

int gate1_val,gate2_val,count1=0,count2=0,check=0,check1=0;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int a;
int servoPin1 = 8;
int servoPin2=9; 
Servo servo1,servo2;   
int servoAngle1=0;
int servoAngle2=0; 

 void open1()
 {
  for(servoAngle1 = 0; servoAngle1 < 120; servoAngle1++) 
  {                                  
    servo1.write(servoAngle1);              
    delay(20);                  
  }
 }
 
 
 void close1()
 {
    
    for(servoAngle1 = 120; servoAngle1 > 0; servoAngle1--)  {                                
    servo1.write(servoAngle1);          
    delay(20);      
  }
 }
 
 
 
 void open2()
 {
  for(servoAngle2 = 0; servoAngle2 < 120; servoAngle2++) 
  {                                  
    servo2.write(servoAngle2);              
    delay(30);                  
  }
 }


void close2()
{
  for(servoAngle2 = 120; servoAngle2 > 0; servoAngle2--) 
  {                                  
    servo2.write(servoAngle2);              
    delay(30);                  
  }
}

void ga1()
{
 
 if(gate1_val<160 && check==0) {
  open1(); 
  check=1;
  }
 delay(100); 
  if(gate1_val>160 &&  check==1)
    {
      close1();
    count1++;
  lcd.setCursor(0, 0);
 lcd.print(count1);
 lcd.print(" vehicle in");
  check=0;
    }  
}


void ga2()
{
  if(gate2_val<160 && check1==0)
  {
    open2();
    check1=1;
  }
delay(100);
 //Serial.println("after open");
  
 //Serial.println(check1);
  
  if(gate2_val>160 && check1==1)
  {
    close2();
    count2++;
  lcd.setCursor(0, 0);
  lcd.print(count2);
  lcd.print(" vehicle out");
  check1=0;
  
  }

}



void setup()
{
  Serial.begin(9600);  
  
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo1.write(servoAngle1);
  servo2.write(servoAngle2);
  lcd.begin(16,2);
  
}
 
  
void loop()
{
 
   gate1_val=analogRead(gate1);
   gate2_val=analogRead(gate2);

   Serial.println(a);
   //Serial.println(gate2_val);
  a=count1-count2;
   
  if(a<=10)
  { //delay(100);
  //delay(1000);
  ga1();
  ga2();
  }
  
  //Serial.println(count1);

 else if(a>10){

      servo1.write(001b0+
      2);
      servo2.write(0);
      lcd.setCursor(0, 0);
  
  lcd.print(" Vehicle Full");
   
 }
 // lcd.println(millis() / 1000);*/ 
  }
