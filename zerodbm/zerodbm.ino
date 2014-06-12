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
   static int adc = 0;
   
   Serial.print(adc);
   Serial.println();

   ADCtoLed(adc);
   adc++;
   
   //sos();
  
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
      redShort(9); 
      return;
   }
   //8	407	r8
   if (adc>=407){
      redShort(8);
      return;
   }
   //7	353	r7
   if (adc>=353){
      redShort(7);
      return;
   }
   //6	306	r6
   if (adc>=306){
      redShort(6);
      return;
   }
   //5	267	r5
   if (adc>=267){
      redShort(5);
      return;
   }
   //4	231	r4
   if (adc>=251){
      redShort(4);
      return;
   }
   //3	199	r3
   if (adc>=199){
      redShort(3);
      return;
   }
   //2	170	r2
   if (adc>=170){
      redShort(2);
      return;
   }
   //1	146	r1
   if (adc>=146){
      redShort(1);
      return;
   }
   //0	125	gsolid
   if (adc>=125){
      ledGreen(0);
      return;
   }
  //-1	107	g1
     if (adc>=107){
      greenShort(1);
      return;
   }
   //-2	91	g2
   if (adc>=91){
      greenShort(2);
      return;
   }
   //-3	77	g3
   if (adc>=77){
      greenShort(3);
      return;
   }
   //-4	65	g4
   if (adc>=65){
      greenShort(4);
      return;
   }
   //-5	55	g5
   if (adc>=55){
      greenShort(5);
      return;
   }
   //-6	46	g6
   if (adc>=46){
      greenShort(6);
      return;
   }
   //-7	38	g7
   if (adc>=38){
      greenShort(7);
      return;
   }
   //-8	32	g8
   if (adc>=32){
      greenShort(8);
      return;
   }
   //-9	26	g9
   if (adc>=26){
      greenShort(9);
      return;
   }
   // -10	22	g10
   if (adc>=22){
      greenShort(10);
      return;
   }
   //-11	18	g1/1
   if (adc>=18){
      greenShort(11);
      return;
   }
   //-12	15	g1/2
   if (adc>=15){
      greenShort(12);
      return;
   }
   //-13	12	g1/3
   if (adc>=12){
      greenShort(13);
      return;
   }
   //-14	10	g1/4
   if (adc>=10){
      greenShort(14);
      return;
   }
   //-15	8	g1/5
   if (adc>=8){
      greenShort(15);
      return;
   }
   //-16	6	black
   else{
      ledGreen(0);
      return;
   }
}



void redDot(int n)
{
   int i;
   
   for (i=0; i < n; i++) {
      ledRed(FT);
      ledBlack(FT);
   }  
}

void redDash(int n)
{
   int i;
   
   for (i=0; i < n; i++) {
      ledRed(3*FT);
      ledBlack(FT);
   }  
}

void greenDot(int n)
{
   int i;
   
   for (i=0; i < n; i++) {
      ledGreen(FT);
      ledBlack(FT);
   }  
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

void redShort(n)
//for n in range 1..9
{
   if ((n < 1) || (n>9))
      outOfRange("redShort", n);

   if (n > 5) {
     redDash(1);
     switch(n){
       case 9:
         n = 1; break;
       case 8:
         n = 2; break;
       case 7:
         n = 3; break;
       case 6:
         n = 4; break;
       default:
     }
   }
   switch(n){
     case 9:
     case 8:
     case 7:
   
}

void greenShort(n)
//for n in range 1..15
{
  
}

void outOfRange()
      //out of range
      Serial.print("redShort OOR");
      Serial.println(n);
      sos();

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


