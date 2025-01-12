#define LED_BLINKER2 11
#define POT 0


void setup() {
  pinMode(LED_BLINKER2, OUTPUT);
  
}

void loop() {
  for(int i=0; i<255; i++){
    analogWrite(LED_BLINKER2, i);
    delay(5);
  }
  for (int i=255; i>0; i--){
    analogWrite(LED_BLINKER2, i); {
      delay(5);
    }
    
  }
}