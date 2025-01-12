#define LED_BLINKER 13
#define LED_BLINKER2 11
#define POT 0


void setup() {
  pinMode(LED_BLINKER, OUTPUT);
  pinMode(LED_BLINKER2, OUTPUT);
  

}

void loop() {
  digitalWrite(LED_BLINKER, HIGH);
  delay(1000);
  digitalWrite(LED_BLINKER2, LOW);
  delay(1000);
  digitalWrite(LED_BLINKER, LOW);
  delay(1000);
  digitalWrite(LED_BLINKER2, HIGH);
  delay(1000);
  
}
