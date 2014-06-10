const int RedPin = 3;
const int GreenPin = 4;
const int FT = 200;

void setup()
{
  Serial.begin(9600);
  //analogReference(DEFAULT);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
}

void loop()
{
   int i, t;
   
   for (i=1; i<6; i++)
      redFlash(i, FT);
   for (i=1; i<6; i++)
      greenFlash(i, FT);
   sos();
   ledBlack(2000);

  
   //int diodeIn;
   
   //lo = analogRead(diodeIn);
   
  
   //Serial.print(diodeIn);
   //delay(1000);
   //Serial.println();
}

void redFlash(int n, int t)
{
   int i;
   
   for (i=0; i < n; i++) {
      ledRed(t);
      ledBlack(t);
   }  
   ledBlack(t);
}

void greenFlash(int n, int t)
{
   int i;
   
   for (i=0; i < n; i++) {
      ledGreen(t);
      ledBlack(t);
   }  
   ledBlack(t);
}



void ledBlack(int t)
{
   digitalWrite(RedPin, LOW);
   digitalWrite(GreenPin, LOW);
   delay(t);
}

void ledRed(int t)
{
   digitalWrite(RedPin, HIGH);
   digitalWrite(GreenPin, LOW);
   delay(t);
}

void ledGreen(int t)
{
   digitalWrite(RedPin, LOW);
   digitalWrite(GreenPin, HIGH);
   delay(t);
}

void sos()
{
   int i;
   while (true) {
      for (i=0; i<3; i++){
         ledRed(FT);
         ledBlack(FT);
      }
      ledBlack(FT);
      for (i=0; i<3; i++){
         ledRed(3*FT);
         ledBlack(FT);
      }
      ledBlack(FT);
      for (i=0; i<3; i++){
         ledRed(FT);
         ledBlack(FT);
      }
      ledBlack(2*FT);
      delay(1000);
   }
 }


