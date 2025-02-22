 //sensor pins;
const int sensorLeftMost = 2;
const int s1 = 3;
const int sensorMiddle = 13;
const int s2 = 4;
const int sensorRightMost = 5;

//const int potPin = A0;

int potValue=0;
//int motorSpeed = 0;

//DC motor speed controller
const int enA = 12;
const int enB = 7;

const int in1 = 11;
const int in2 = 10;
const int in3 = 9;
const int in4 = 8;

int IRvalueLeftMost = 0;
int IRvalue2 = 0;
int IRvalueMiddle = 0;
int IRvalue3 = 0;
int IRvalueRightMost = 0;

void setup()
{
  //Serial.begin(9600);
  pinMode(sensorLeftMost,INPUT);
  pinMode(s1,INPUT);
  pinMode(sensorMiddle,INPUT);
  pinMode(s2,INPUT);
  pinMode(sensorRightMost,INPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  delay(2000);
  forwardRun();
  
}

void loop()
{


  // Reading values
  IRvalueLeftMost = digitalRead(sensorLeftMost);
  IRvalue2 = digitalRead(s1);
  IRvalueMiddle = digitalRead(sensorMiddle);
  IRvalue3 = digitalRead(s2);
  IRvalueRightMost = digitalRead(sensorRightMost);
  //IRvalue4 = digitalRead(s3);
 
  

  //potValue = 20;  // variable to store the value coming from the sensor
  //potValue = analogRead(potPin);
  //Serial.println(potValue);
  //motorSpeed = map(potValue, 0, 1023, 0, 255);
  //Serial.println(speedMotor);
  /*
   Serial.print("Digital Reading=");
   Serial.print(IRvalueLeftMost);
   Serial.print(IRvalue2);
   Serial.print(IRvalueMiddle);
   Serial.print(IRvalue3);
   Serial.println(IRvalueRightMost);
   Serial.println(""); 
   */
  // read the value from the potentiometer:
 
if (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==0 && IRvalue3==1 && IRvalueRightMost==1) // run forward
 {
  moveForward();
 }
 if (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) // run forward
 {
  moveForward();
 }
 //-------- instance to move right
 else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==0 && IRvalueRightMost==1) //nudge to the right a little bit
 {
  moveRight();
 }
 else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==0 && IRvalue3==0 && IRvalueRightMost==1) //nudge to the right
 {
  moveRight();
 }
 else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==0 && IRvalueRightMost==0) //turn right sharply //nudge to the right a little harder
 {
  //moveRight();
  sharpRightTurn();
 }
  else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==0) //turn right sharply //nudge to the right a little harder
 {
  sharpRightTurn();

 }
 //instace to move left-----------------------------------------------------------------------------------------------------------------------
 //-------- instance to left right
 else if  (IRvalueLeftMost==1 && IRvalue2==0 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) //nudge to the left a little bit
 {
  moveLeft();
 }
 else if  (IRvalueLeftMost==1 && IRvalue2==0 && IRvalueMiddle==0 && IRvalue3==1 && IRvalueRightMost==1) //nudge to the left
 {
  moveLeft();
 }
 else if  (IRvalueLeftMost==0 && IRvalue2==0 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) //turn right sharply //nudge to the right a little harder
 {
  //moveLeft();
  sharpLeftTurn();
 }
  else if  (IRvalueLeftMost==0 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) //turn right sharply //nudge to the right a little harder
 {
  //moveLeft(FORWARD_SPEED * 0);
  sharpLeftTurn();
 }
 else if (IRvalueLeftMost==0 && IRvalue2==0 && IRvalueMiddle==0 && IRvalue3==0 && IRvalueRightMost==0) // stop
 {
  moveStop();
 }
  //delay(3000);
}

void sharpLeftTurn(){
  int middleSensorValue, sensor3Value, sensorRight;
  
  middleSensorValue = digitalRead(sensorMiddle);
  sensor3Value = digitalRead(s2);
  sensorRight = digitalRead(sensorRightMost);
  //reverseMotor2();
  while (middleSensorValue == 1 && sensor3Value==1 && sensorRight==1){
  forwardMotor1();
  //reverseMotor2(); //try this
  stopMotor2();
   middleSensorValue = digitalRead(sensorMiddle);
   sensor3Value = digitalRead(s2);
   sensorRight = digitalRead(sensorRightMost);
   
   /*
   Serial.print("middleSensorValue: ");
   Serial.println(middleSensorValue);
   Serial.print("sensor3Value: ");
   Serial.println(sensor3Value);
   Serial.print("sensorRightMost: ");
   Serial.print(sensorRightMost);
   delay(100); */
   //delay(200);
  }
  moveStop();
  forwardMotor2();
  delay(30);
  moveForward();
}

void sharpRightTurn(){
  int middleSensorValue, sensor1Value, sensorLeft;
  
  middleSensorValue = digitalRead(sensorMiddle);
  sensor1Value = digitalRead(s1);
  sensorLeft = digitalRead(sensorLeftMost);
  //reverseMotor1();
  while (middleSensorValue == 1 && sensor1Value==1 && sensorLeft==1){
   forwardMotor2();
   //reverseMotor1();
   stopMotor1();
   middleSensorValue = digitalRead(sensorMiddle);
   sensor1Value = digitalRead(s1);
   sensorLeft = digitalRead(sensorLeftMost);
   /*
   Serial.print("middleSensorValue: ");
   Serial.println(middleSensorValue);
   Serial.print("sensor3Value: ");
   Serial.println(sensor3Value);
   Serial.print("sensorRightMost: ");
   Serial.print(sensorRightMost);
   //delay(1000); */
   //delay(200);
  }
  moveStop();
  forwardMotor1();
  delay(30);
  moveForward();
}

void forwardRun(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void reverseRun(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void reverseMotor1(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void reverseMotor2(){
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopMotor1(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void stopMotor2(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void forwardMotor1(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void forwardMotor2(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moveForward(){
  forwardMotor1();
  forwardMotor2();
}

void moveStop() {
  stopMotor1();
  stopMotor2();
 }

void moveLeft(){
  forwardMotor1();
  stopMotor2();
 }
 
 void moveRight(){
  /*int boostSpeed = speedMotor + booster;
  if (boostSpeed > 255)
  {
    boostSpeed = 255;
  } */
  forwardMotor2();
  stopMotor1();
 }

 
 
