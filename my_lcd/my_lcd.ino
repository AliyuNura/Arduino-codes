#include <LiquidCrystal.h>




LiquidCrystal lcd(12,11,5,4,3,2);


void setup( )
{
  lcd.begin(16, 2);
  lcd.print( "Name: Aliyu nura" );
  lcd.setCursor(0, 1);
  lcd.print( "Dept: Electr Engr" );
//  
}

void loop() {
  // put your main code here, to run repeatedly:

}
