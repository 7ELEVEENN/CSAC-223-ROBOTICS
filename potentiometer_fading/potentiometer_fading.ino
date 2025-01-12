//Programming the Arduino to adjust the LED’s brightness using potentiometer and code
int led_pin = 6;
int pot_pin = A0;
int output;
int led_value;

void setup()
{
  pinMode(led_pin, OUTPUT);
}

void loop(){
  //reading from potentiometer
  output = analogRead(pot_pin);
  //mapping the values between 0 to 255 bcos we can give output
  //from 0 - 255 using the analog function
  led_value = map(output, 0, 1023, 0, 255);
  analogWrite(led_pin, led_value);
  delay(1);
}