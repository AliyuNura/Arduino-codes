void setup() 
{
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    int state = Serial.parseInt();
    if (state == 1)
    {
     digitalWrite(8, HIGH);
     Serial.println("Command completed LED turned ON");
    }
    if (state == 2)
    {
     digitalWrite(8, LOW);
     Serial.println("Command completed LED turned OFF");
    }  
  }
}z
