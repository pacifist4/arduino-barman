//Display info func
void displayInfo () {
  
  lcd.clear();
  switch (mode) 
  {
    case 1:  {
      //Time calculate
      int seconds = myTimer/1000;
      int santiSeconds = (myTimer-seconds*1000)/100;
      //Displaying 
      lcd.print("Hand mode");
      lcd.setCursor(0, 1);
      lcd.print("Pos:");
      lcd.print(position);     
      lcd.setCursor(8, 1);
      lcd.print("T:");
      lcd.print(seconds);
      lcd.print(".");
      lcd.print(santiSeconds);
      lcd.print("s");
      break;
    }
    case 2: {
      lcd.print("Standart mode"); 
      lcd.setCursor(0, 1);
      lcd.print("Vol:");
      lcd.print(vol);
      lcd.print("ml");
      break;
    }
     case 3: {
      lcd.print("Auto mode"); 
      lcd.setCursor(0, 1);
      lcd.print("Vol:");
      lcd.print(vol);
      lcd.print("ml");
      break;
    }  
     case 4: {
      //Time calculate
      int seconds = fullVolTime/1000;
      int santiSeconds = (fullVolTime-seconds*1000)/100;
      //Display      
      lcd.print("Settings"); 
      lcd.setCursor(0, 1);
      lcd.print("40ml T:");
      lcd.print(seconds);
      lcd.print(".");
      lcd.print(santiSeconds);
      lcd.print("s");
      break;
    }    
  };
};
