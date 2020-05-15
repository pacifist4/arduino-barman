#include <Servo.h>
#include <LiquidCrystal.h>

//Define servo
Servo servo;
//Define lcd
LiquidCrystal lcd(13, 8, 9, 10, 11, 12);

//Pins

//Digital
const byte servoPin = 7;
const byte joystikD = 0;
const byte mosfet = 6;
const byte leds[] = {2, 3, 4, 5};

//Analog
const byte joystikX_pin = 0;
const byte joystikY_pin = 1;
const byte cupPin[] = {2, 3, 4, 5};

//Other vars
//Mode (1- hand mode, 2-Standart mode, 3- auto mode)
byte mode = 1; 
//Volume would poured (max 40 ml)
byte vol = 20;
//Is cup stand on position?
byte cups[] = {0, 0, 0, 0};
//Angels of cups on board for servo
const byte angles[] = {20, 80, 125, 165};

//Servo positions  (from 1 to 180)
byte position = 1;
byte target = 1;
