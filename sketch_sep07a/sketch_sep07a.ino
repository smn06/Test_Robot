#define LS 10      
#define ls1 11
#define rs1 12
#define RS 13      

#define LM1 3   //c   // left motor
#define LM2 4   //d   // left motor
#define RM1 5   //a    // right motor
#define RM2 6   //b    // right motor

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(ls1,INPUT);
  pinMode(rs1,INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
   Serial.begin(9600);
}

void loop()
{ 
  int a=digitalRead(LS);
  
  int b=digitalRead(ls1);
  int c=digitalRead(rs1);
  int d=digitalRead(RS);
  
  Serial.print(a);
  Serial.print(" ");
  
  Serial.print(b);
  Serial.print(" " );
  
  Serial.print(c);
  Serial.print(" ");
  
  Serial.print(d);
  Serial.println();  delay(100);
  
  if((digitalRead(rs1)) && (digitalRead(ls1)))     // Move Forward
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
  if(!(digitalRead(LS)) && digitalRead(ls1) && digitalRead(rs1) && digitalRead(RS))     // Turn right
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
  if(digitalRead(LS) && digitalRead(rs1) && digitalRead(ls1) && !(digitalRead(RS)))     // turn left
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}
