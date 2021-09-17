  int vSpeed = 100;        // MAX 255
  int turn_speed = 70;    // MAX 255 
  int turn_delay = 10;



  
  const int motorA1      = 8;  
  const int motorA2      = 10; 
  const int motorAspeed  = 9;
  const int motorB1      = 12; 
  const int motorB2      = 13; 
  const int motorBspeed  = 11;

  const int left_sensor_pin =A0;
  const int left_sensor_pin1=A2;
  const int right_sensor_pin =A1;
  const int right_sensor_pin1=A3;

  
  
  int left_sensor_state;
  int right_sensor_state;
  int right_sensor_state1;
  int left_sensor_state1;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);

  delay(1000);
  
}

void loop() {
  
left_sensor_state = analogRead(left_sensor_pin);
right_sensor_state = analogRead(right_sensor_pin);
right_sensor_state1 = analogRead(right_sensor_pin1);
left_sensor_state1 = analogRead(left_sensor_pin1);

Serial.print(left_sensor_state);
Serial.print("  ");
Serial.print(left_sensor_state1);
Serial.print("  ");
Serial.print(right_sensor_state1);
Serial.print("  ");
Serial.print(right_sensor_state);
Serial.println();






if(right_sensor_state > 500 && right_sensor_state1 > 500 && left_sensor_state1 > 500 && left_sensor_state < 500)
{
  Serial.println("turning right");

  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, turn_speed);

  delay(turn_delay);
  
  }
if(right_sensor_state < 500 && right_sensor_state1 > 500 && left_sensor_state1 > 500 && left_sensor_state > 500)
{
  Serial.println("turning left");
  
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, turn_speed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  }

if(right_sensor_state1 > 500 && left_sensor_state1 > 500)
{
  Serial.println("going forward");

  digitalWrite (motorA2,HIGH);
  digitalWrite(motorA1,LOW);                       
  digitalWrite (motorB2,HIGH);
  digitalWrite(motorB1,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  
  }

if(right_sensor_state < 500 && right_sensor_state1 < 500 && left_sensor_state1 < 500 && left_sensor_state < 500)
{ 
  Serial.println("stop");
  
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);
  
  }

 
}










 
