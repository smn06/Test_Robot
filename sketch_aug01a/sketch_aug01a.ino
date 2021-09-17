
#define ir_sensor_f1 A0 //front distance sensor 1 
#define ir_sensor_f2 A1 //frint distance sensor 2
#define ir_sensor_l A2 //left distance sensor 
#define ir_sensor_r A3 //right distance sensor
#define ir_sensor_b A4 //back distance sensor
#define in1 7 // left motor forward pin
#define in2 6 // left motor back pin
#define in3 5 // right motor forward pin
#define in4 4 // right motor back pin
#define irFL 22 //ir sensor front left
#define irFR 23 //ir sensor front right
#define irBL 24 //ir sensor back left
#define irBR 25 //ir sensor back right

#define black 0
#define white 1
int dis_f1,dis_f2, dis_l,dis_r,dis_b,front_left,front_right,back_left,back_right;

void motor_stop(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void setup() {
  pinMode(ir_sensor_f1, INPUT);
  pinMode(ir_sensor_f2, INPUT);
  pinMode(ir_sensor_l, INPUT);
  pinMode(ir_sensor_r, INPUT);
  pinMode(ir_sensor_b, INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(irFL, INPUT);
  pinMode(irFR, INPUT);
  pinMode(irBL, INPUT);
  pinMode(irBR, INPUT);
  Serial.begin(9600);

  motor_stop();
  delay(5000);
  
}

void motor_forward(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void motor_back(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void motor_left(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void motor_right(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void distance_sensor(){
  dis_f1 = analogRead(ir_sensor_f1);
  dis_f2 = analogRead(ir_sensor_f2);
  dis_l = analogRead(ir_sensor_l);
  dis_r = analogRead(ir_sensor_r);
  dis_b = analogRead(ir_sensor_b);
}
void ir_sensor(){
  front_left = digitalRead(irFL);
  front_right = digitalRead(irFR);
  back_left = digitalRead(irBL);
  back_right = digitalRead(irBR);
}

void loop() {
  distance_sensor();
  ir_sensor();
  if(dis_f1>150 && dis_f2>150) motor_forward();
  else if(dis_l>150) motor_left();
  else if(dis_r>150) motor_right();
  else if(dis_b>150) motor_back();
  else motor_right();

}
