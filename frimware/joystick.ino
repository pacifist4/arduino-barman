
//Joystick 
void joystick () {

//Servo controll
if (mode == 1) {  
  if ((analogRead(joystikY_pin) > 900) && position < 176 )
  {
    servoRun(position+5);
  }
  if ((analogRead(joystikY_pin) > 900) && position == 176 )
  {
    servoRun(position+4);
  }
  if ((analogRead(joystikY_pin) < 150) && position == 180)
  {
    servoRun(position-4);
  }
  if ((analogRead(joystikY_pin) < 150) && position > 1)
  {
    servoRun(position-5);
  }
} else if ((mode == 2) || (mode == 3)) {
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
  } else if (mode == 4) {
        if ((analogRead(joystikY_pin) > 900) && vol > 0 )
    {
      fullVolTime-=100;
      displayInfo();
      delay(200);
    }
    if ((analogRead(joystikY_pin) < 150) && vol < 40)
    {
      fullVolTime+=100;
      displayInfo();
      delay(200);
    }
  }

  //X-axis mode change
  if ((analogRead(joystikX_pin) > 900) && vol > 0 )
  {
    if (mode < 4) {
      mode++;
    } else if (mode == 4) {
      mode = 1;
    }
    if (position != 1) {
      servoRun(1);
    }
    displayInfo();
      delay(500);
  }
  if ((analogRead(joystikX_pin) < 150) && vol < 40)
  {
    if (mode > 1) {
      mode--;
    } else if (mode == 1) {
      mode = 4;
    }
     if (position != 1) {
      servoRun(1);
    }
    displayInfo();
      delay(500);
  }


//Go button
  if ( digitalRead(joystikD) == 0 ) {
    if (mode == 1) {
      pumpOn();      
    } else if (mode == 2) {
      standartStart();
    }
  } else {
    pumpOff();
  }
}
