  int speed = 60;        
  int turn_speed = 30;     
  int turn = 10;

  const int mA1      = 8;  
  const int mA2      = 10; 
  const int mAspeed  = 9;
  const int mB1      = 12; 
  const int mB2      = 13; 
  const int mBspeed  = 11;


  const int left_sensor =A0;
  const int left_sensor1=A2;
  const int right_sensor =A1;
  const int right_sensor1=A3;
  
  
  int left_sensor_value;
  int left_sensor_value1;
  int right_sensor_value;
  int right_sensor_value1;

void setup() {
  pinMode(mA1, OUTPUT);
  pinMode(mA2, OUTPUT);
  pinMode(mB1, OUTPUT);
  pinMode(mB2, OUTPUT);

  Serial.begin(9600);

  delay(2000);
  
}

void loop() {

left_sensor_value = analogRead(left_sensor);
left_sensor_value1=analogRead(left_sensor1);
right_sensor_value = analogRead(right_sensor);
right_sensor_value1=analogRead(right_sensor1);

Serial.print(left_sensor_value);
Serial.print("  ");
Serial.print(left_sensor_value1);
Serial.print("  ");
Serial.print(right_sensor_value1);
Serial.print("  ");
Serial.print(right_sensor_value);
Serial.println();




if(left_sensor_value < 500 && left_sensor_value1 > 500 && right_sensor_value1 > 500 &&  right_sensor_value > 500)
{
  Serial.println("right");

  digitalWrite (mA1,LOW);
  digitalWrite(mA2,HIGH);                       
  digitalWrite (mB1,LOW);
  digitalWrite(mB2,HIGH);

  analogWrite (mAspeed, speed);
  analogWrite (mBspeed, turn_speed);

  delay(turn);
  
  }
if(left_sensor_value > 500 && left_sensor_value1 > 500 && right_sensor_value1 > 500 &&  right_sensor_value < 500)
{
  Serial.println("left");
  
  digitalWrite (mA1,LOW);
  digitalWrite(mA2,HIGH);                       
  digitalWrite (mB1,LOW);
  digitalWrite(mB2,HIGH);

  analogWrite (mAspeed, turn_speed);
  analogWrite (mBspeed, speed);

  delay(turn);
  }

if(right_sensor_value1 > 500 && left_sensor_value1 > 500)
{
  Serial.println("forward");

  digitalWrite (mA2,HIGH);
  digitalWrite(mA1,LOW);                       
  digitalWrite (mB2,HIGH);
  digitalWrite(mB1,LOW);

  analogWrite (mAspeed, speed);
  analogWrite (mBspeed, speed);

  delay(turn);
  
  }

if(left_sensor_value < 500 && left_sensor_value1 < 500 && right_sensor_value1 < 500 &&  right_sensor_value < 500)
{ 
  Serial.println("stop");
  
  analogWrite (mAspeed, 0);
  analogWrite (mBspeed, 0);
  
  }

 
}



