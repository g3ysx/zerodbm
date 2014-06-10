const int DiodeIn = 1;

void setup()
{
  Serial.begin(9600);
  analogReference(DEFAULT);
}

void loop()
{
  
   int diodeIn;
   
   lo = analogRead(diodeIn);
   
  
   Serial.print(diodeIn);
   delay(1000);
   Serial.println();
}



