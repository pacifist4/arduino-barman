
//Servo moove func
void servoRun(int targetPos) {
      servo.write(targetPos);
      position = targetPos;  
      delay(50)  ;
}
