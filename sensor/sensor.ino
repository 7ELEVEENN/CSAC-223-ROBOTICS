#define S1 2
#define S2 3
#define S3 4
#define S4 5
#define S5 6

void setup() {
  // put your setup code here, to run once:
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int sr1 = digitalRead(S1);
  int sr2 = digitalRead(S2);
  int sr3 = digitalRead(S3);
  int sr4 = digitalRead(S4);
  int sr5 = digitalRead(S5);
  
  Serial.begin(9600);
  Serial.print(sr1 + " ");
  Serial.print(sr2 + " ");
  Serial.print(sr3 + " ");
  Serial.print(sr4 + " ");
  Serial.println(sr5);

}
