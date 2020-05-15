
//Joystick 
void joystick () {

//Servo controll
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

//Volume controll
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
//Change mode    
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
