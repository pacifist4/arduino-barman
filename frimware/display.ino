//Display info func
void displayInfo () {
  lcd.clear();
  switch (mode) 
  {
    case 1:  { 
      lcd.print("Hand mode");
      lcd.setCursor(0, 1);
      lcd.print("Pos:");
      lcd.print(position);     
      lcd.setCursor(8, 1);
      lcd.print("Vol:");
      lcd.print(vol);
      lcd.print("ml");
      break;
    }
    case 2: {
      lcd.print("Auto mode"); 
      lcd.setCursor(0, 1);
      lcd.print("Vol:");
      lcd.print(vol);
      break;
    }    
  };
};
