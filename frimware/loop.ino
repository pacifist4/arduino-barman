void loop() {
  joystick();
  if (position != target)
  {
    servoRun(target); 
    displayInfo();   
  }
  cupStand();
  displayInfo();
  delay(50);
}
