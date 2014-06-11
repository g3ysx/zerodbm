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
   ADCtoLed(100)
   sos();
   ledBlack(2000);

  
   //int diodeIn;
   
   //lo = analogRead(diodeIn);
   
  
   //Serial.print(diodeIn);
   //delay(1000);
   //Serial.println();
}

void ADCtoLed(int adc)
{
   //dBm	ADC	Action
   //10	536	rsolid
   if (adc>=536){
      ledRed(0);
      return;
   }
   //9	467	r9
   if (adc>=467){
      redFlash(9, FT); 
      return;
   }
   //8	407	r8
   if (adc>=407){
      redFlash(8, FT);
      return;
   }
   //7	353	r7
   if (adc>=353){
      redFlash(7, FT);
      return;
   }
   //6	306	r6
   if (adc>=306){
      redFlash(6, FT);
      return;
   }
   //5	267	r5
   if (adc>=267){
      redFlash(5, FT);
      return;
   }
   //4	231	r4
   if (adc>=251){
      redFlash(4, FT);
      return;
   }
   //3	199	r3
   if (adc>=199){
      redFlash(3, FT);
      return;
   }
   //2	170	r2
   if (adc>=170){
      redFlash(2, FT);
      return;
   }
   //1	146	r1
   if (adc>=146){
      redFlash(1, FT);
      return;
   }
   //0	125	gsolid
   if (adc>=125){
      ledGreen(0);
      return;
   }
  //-1	107	g1
     if (adc>=107){
      greenFlash(1, FT);
      return;
   }
   //-2	91	g2
   if (adc>=91){
      greenFlash(2, FT);
      return;
   }
   //-3	77	g3
   if (adc>=77){
      greenFlash(3, FT);
      return;
   }
   //-4	65	g4
   if (adc>=65){
      greenFlash(4, FT);
      return;
   }
   //-5	55	g5
   if (adc>=55){
      greenFlash(5, FT);
      return;
   }
   //-6	46	g6
   if (adc>=46){
      greenFlash(6, FT);
      return;
   }
   //-7	38	g7
   if (adc>=38){
      greenFlash(7, FT);
      return;
   }
   //-8	32	g8
   if (adc>=32){
      greenFlash(8, FT);
      return;
   }
   //-9	26	g9
   if (adc>=26){
      greenFlash(9, FT);
      return;
   }
   // -10	22	g10
   if (adc>=22){
      greenFlash(10, FT);
      return;
   }
   //-11	18	g1/1
   if (adc>=18){
      greenFlash(1, FT);
      delay(FT)
      greenFlash(1, FT);
      return;
   }
   //-12	15	g1/2
   if (adc>=15){
      greenFlash(1, FT);
      delay(FT)
      greenFlash(2, FT);
      return;
   }
   //-13	12	g1/3
   if (adc>=12){
      greenFlash(1, FT);
      delay(FT)
      greenFlash(3, FT);
      return;
   }
   //-14	10	g1/4
   if (adc>=10){
      greenFlash(1, FT);
      delay(FT)
      greenFlash(4, FT);
      return;
   }
   //-15	8	g1/5
   if (adc>=8){
      greenFlash(1, FT);
      delay(FT)
      greenFlash(5, FT);
      return;
   }
   //-16	6	black
   else{
      ledGreen(0);
      return;
   }
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


