int buzzer = 13;
int RLED = 3;
int GLED = 5;
int YLED = 4;
int sensor = 6;
int detect,f=0;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(YLED, OUTPUT);
  
  pinMode(sensor, INPUT);
}

void loop()
{
  detect = digitalRead(sensor);
  if (detect == 0)
  {
    digitalWrite(YLED,HIGH);
    delay(100);
    digitalWrite(YLED,LOW);
    delay(100);
    digitalWrite(YLED,HIGH);
    delay(100);
    digitalWrite(YLED,LOW);
    digitalWrite(buzzer, HIGH);
    digitalWrite(RLED, HIGH);
    delay(50);
    digitalWrite(RLED, LOW);
     delay(50);
  digitalWrite(RLED, HIGH);
    delay(50);
    digitalWrite(RLED, LOW);
     delay(50);
  
   }
  else
  {
    digitalWrite(buzzer, LOW);
    digitalWrite(GLED,HIGH);
    delay(100);
    digitalWrite(GLED,LOW);
    delay(100);
  }
  delay(1000);
}
