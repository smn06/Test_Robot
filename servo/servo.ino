#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(8);
}

void loop() {
  servo.write(0);
  delay(2000);
  servo.write(180);
  delay(2000);

}
