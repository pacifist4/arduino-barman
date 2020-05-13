#include <Servo.h>
#include <LiquidCrystal.h>

Servo myservo;
LiquidCrystal lcd(13, 8, 9, 10, 11, 12);
//servo positions  
byte position = 1;
byte target = 1;

//pins
const byte servoPin = 2;
const byte joystikD = 1;
const byte joystikX_pin = 0;
const byte joystikY_pin = 1;
const byte latchPin = 3;      //  ST_CP [RCK] on 74HC595
const byte clockPin = 4;      // SH_CP [SCK] on 74HC595
const byte dataPin = 5;     // DS [S1] on 74HC595
const byte cupPin[] = {2, 3, 4, 5};
const byte mosfet = 6;


//other vars
byte mode = 1; 
byte vol = 20;
byte led = 0;
byte cups[] = {0, 0, 0, 0};
const byte angles[] = {20, 80, 125, 165};

//Servo moove func
void servoRun(int targetPos) {
      myservo.write(targetPos);
      position = targetPos;  
      delay(50)  ;
}

//Display info func
void displayInfo () {
  lcd.clear();
  switch (mode) 
  {
    case 1:  { lcd.print("Hand mode");
    lcd.setCursor(0, 1);
    lcd.print("Pos:");
    lcd.print(position);
     lcd.print(cups[0]);
     lcd.print(cups[1]);
     lcd.print(cups[2]);
     lcd.print(cups[3]);
     lcd.setCursor(8, 1);
     lcd.print("Vol:");
     lcd.print(vol);
     lcd.print("ml");
    break;
    }
    case 2: lcd.print("Auto mode"); 
    lcd.setCursor(0, 1);
    lcd.print("Vol:");
    lcd.print(vol);
    break;
  };
}

//Joystick 
void joystick () {

if (mode == 1) {
  
  if ((analogRead(joystikX_pin) > 900) && target < 176 )
  {
    target+=5;
  }
  if ((analogRead(joystikX_pin) > 900) && target == 176 )
  {
    target+=4;
  }
  if ((analogRead(joystikX_pin) < 150) && target == 180)
  {
    target-=4;
  }
  if ((analogRead(joystikX_pin) < 150) && target > 1)
  {
    target-=5;
  }
}

  if ((analogRead(joystikY_pin) > 900) && vol > 0 )
  {
    vol-=5;
    displayInfo();
    delay(500);
  }
  if ((analogRead(joystikY_pin) < 150) && vol < 40)
  {
    vol+=5;
    displayInfo();
    delay(500);
  }  
  if ( digitalRead(joystikD) == 0 ) {
    if ( mode == 1 ) {
      mode = 2;
      target = 1;
    } else {
      mode = 1;
    }
    displayInfo();
    delay(500);
  }
}

//Cup detector
void cupStand () {
  displayInfo();
  delay(100);
  for (int i = 0; i<4; i++) {
    if ((analogRead(cupPin[i]) <= 5 ) && (cups[i] == 0)) {
      plusCup(i);   
     }
    if ((analogRead(cupPin[i]) > 5) && (cups[i] == 1) ) {
      minusCup(i);
    }
  } 
}

//Led on/off

void ledConfig () {
  for (int j = 0; j < 4; j++)
    {
      bitWrite(led, j+4, cups[j]);
    }
    
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, led);
  digitalWrite(latchPin, HIGH);
}

void plusCup (byte i) {
   cups[i] = 1;
   ledConfig();
}

void minusCup (byte i) {
  cups[i] = 0;
  ledConfig();
}

//Setup
void setup() {
  lcd.begin(16, 2);
  
  myservo.attach(servoPin);
  myservo.write(position);

  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);

  pinMode(joystikD, INPUT);
  digitalWrite(joystikD, HIGH);
  ledConfig();
  displayInfo();
  pinMode(mosfet, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  joystick();
  if (position != target)
  {
    servoRun(target); 
    displayInfo();   
  }
  cupStand();
Serial.print(analogRead(cupPin[0]));
Serial.print(" ");
Serial.print(analogRead(cupPin[1]));
Serial.print(" ");
Serial.print(analogRead(cupPin[2]));
Serial.print(" ");
Serial.print(analogRead(cupPin[3]));
  Serial.print("\n");
delay(50);
}
