void loop() {
  joystick();
  cupStand();
  if ( mode == 3 ) {
    autoMode();
  }
  //TODO Romove display info from here
  displayInfo();
  delay(50);

}
