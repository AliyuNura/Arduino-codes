#include <LiquidCrystal.h>




LiquidCrystal lcd(12,11,5,4,3,2);

/*
 * Display fixe text .
 */
void setup( )
{
  lcd.begin(16, 2);
  lcd.print( "LCD Design" );
  lcd.setCursor(0, 1);
  lcd.print( "By Aliyu" );
//  
}

///*
// * Poll for a measurement, keeping the state machine alive.  Returns
// * true if a measurement is available.
// */
//static bool measure_environment( float *temperature, float *humidity )
//{
//  static unsigned long measurement_timestamp = millis( );
//
//  /* Measure once every four seconds. */
//  if( millis( ) - measurement_timestamp > 3000ul )
//  {
//    if( dht_sensor.measure( temperature, humidity ) == true )
//    {
//      measurement_timestamp = millis( );
//      return( true );
//    }
//  }
//
//  return( false );
//}
//
///*
// * Main program loop.
// */
//void loop( )
//{
//  float temperature;
//  float humidity;
//
//  /* Measure temperature and humidity.  If the functions returns
//     true, then a measurement is available. */
//  if( measure_environment( &temperature, &humidity ) == true )
//  {
//   /*
//    * Display  changing text.
//    */
//    lcd.setCursor(4, 0);
//    lcd.print( temperature );
//    lcd.setCursor(4, 1);
//    lcd.print( humidity );
//        
//  }
////  delay(1000);
//}
