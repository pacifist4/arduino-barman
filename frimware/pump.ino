void pumpOn () {
  if (isPumpOn == false) {
    digitalWrite(mosfet, HIGH);
    isPumpOn = true;
    starter = millis();
  }
  if (mode == 1 ) {
    if (millis() - starter - myTimer >= 100) {
    myTimer = millis() - starter;
    displayInfo();
  }
  }
}

void pumpOff () {
  if (isPumpOn == true) {
    digitalWrite(mosfet, LOW);
    isPumpOn = false;
    if (mode == 1) {
      delay(1000);
      myTimer = 0;
    }
  }
}
