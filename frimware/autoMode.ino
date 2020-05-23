void autoMode() {
  int time = fullVolTime/40*vol;
  
  for (int i=0; i<4; i++) {
    if ((cups[i] == 1) && (cupsDone[i] == 0)) {
      servoRun(angles[i]); 
      delay(200);
      pumpOn();
      delay(time);
      pumpOff();
      delay(500);
      cupsDone[i] = 1;
    }    
  } 
}
