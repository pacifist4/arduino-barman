//Cup detector
void cupStand () {
  for (int i = 0; i<4; i++) {
    if ((analogRead(cupPin[i]) == 1023 ) && (cups[i] == 0)) {
      plusCup(i);   
     }
    if ((analogRead(cupPin[i]) == 0) && (cups[i] == 1) ) {
      minusCup(i);
    }
  } 
}

//Led on/off

void ledConfig () {
  for (int j = 0; j < 4; j++)
    {
      if (cups[j] == 0) {
        digitalWrite(leds[j], LOW);
      } else {
        digitalWrite(leds[j], HIGH);
      }
    }
}

void plusCup (byte i) {
   cups[i] = 1;
   ledConfig();
}

void minusCup (byte i) {
  cups[i] = 0;
  ledConfig();
}
