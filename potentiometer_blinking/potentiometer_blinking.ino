const int in1 = 11;
const int in2 = 10;
const int in3 = 9;
const int in4 = 8;

int counter = 1;

void setup() {
  // put your setup code here, to run once:
  delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:
  forwardRun();
  delay(3000);
  motorStop();
  delay(2000);
  backwardRun();
  delay(3000);
  motorStop();
  delay(2000);
  forwardRun();
  delay(3000);
  moveRight();
  delay(2000);
  backwardRun();
  delay(3000);
  moveLeft();
  delay(3000);
  motorStop();
  delay(2000);

}
void backwardRun(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}
void forwardRun(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

}
void stopMotors(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
  
}

void moveLeft(){
  forwardMotor2 ();
  stopMotor1 ();
}
void moveRight(){
  forwardMotor1 ();
  stopMotor2 ();
}
void forwardMotor1(){
  digitalWrite(in1,LOW);
  digitalWrite(in2, HIGH);
}
void forwardMotor2(){
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void motorStop(){
  stopMotor1();
  stopMotor2();
}
void stopMotor1(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
void stopMotor2(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}