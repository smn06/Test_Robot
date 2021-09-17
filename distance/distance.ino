#define lp 7
#define ln 6
#define rp 5
#define rn 4

#define trig 11
#define echo 10

int sp=120;

int ir = B00000;
int irDigital[5] = {0, 0, 0, 0, 0};
int irPin[5] = {A0,A1,A2,A3,A4};
int distance,duration;

void dis(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);   
  digitalWrite(trig, HIGH);    
  delayMicroseconds(10);
  duration = pulseIn(echo, HIGH); 
  distance = duration / 58.2;   
  Serial.println(distance);
  
  if (distance < 14)
  {
    stopp();
  }
}

void setup() {
  
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  pinMode(irPin[0], INPUT);
  pinMode(irPin[1], INPUT);
  pinMode(irPin[2], INPUT);
  pinMode(irPin[3], INPUT);
  
  pinMode(irPin[4], INPUT);

  pinMode(lp, OUTPUT);
  pinMode(ln, OUTPUT);
  pinMode(rp, OUTPUT);
  pinMode(rn, OUTPUT);

}

void motor_forward(){
  digitalWrite(lp, HIGH);
  digitalWrite(ln, LOW);
  digitalWrite(rp, HIGH);
  digitalWrite(rn, LOW);
}

void motor_backward(){
  digitalWrite(lp, LOW);
  digitalWrite(ln, HIGH);
  digitalWrite(rp, LOW);
  digitalWrite(rn, HIGH);
}

void motor_left(){
  digitalWrite(lp, LOW);
  digitalWrite(ln, HIGH);
  digitalWrite(rp, HIGH);
  digitalWrite(rn, LOW);
}

void motor_right(){
  digitalWrite(lp, HIGH);
  digitalWrite(ln, LOW);
  digitalWrite(rp, LOW);
  digitalWrite(rn, HIGH);
}

void stopp(){
  digitalWrite(lp, LOW);
  digitalWrite(ln, LOW);
  digitalWrite(rp, LOW);
  digitalWrite(rn, LOW);
}
void loop() {
    
  for(int i=0; i<5; i++){
    bitWrite(ir, i, digitalRead(irPin[i]));
  }
 
  if(ir == 6 || ir == 0 || ir == 4 || ir == 2){
    motor_forward();
  }
  else if(ir == 1 || ir == 7 || ir == 3){

    motor_left();
  }
  else if(ir == 16 || ir==28 || ir == 24){
    motor_right();
  }
  dis();

}
