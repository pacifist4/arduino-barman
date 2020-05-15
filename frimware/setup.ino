//Setup
void setup() {
  //Display start
  lcd.begin(16, 2);
  displayInfo();
  //Servo start
  servo.attach(servoPin);
  servo.write(position);
  //Leds start
  pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
  pinMode(leds[3], OUTPUT);
  //Joystick start
  pinMode(joystikD, INPUT);
  //digitalWrite(joystikD, HIGH);
  //Pupm start
  pinMode(mosfet, OUTPUT);
  ledConfig();
  
  
}
