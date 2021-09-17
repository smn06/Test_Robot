
#define LS 10      
#define ls1 11
#define rs1 12
#define RS 13      

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(ls1,INPUT);
  pinMode(rs1,INPUT);
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
  Serial.println();  delay(100);}
