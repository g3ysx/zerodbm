#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/io.h>

const int RedPin = 3;
const int GreenPin = 4;
const int FT = 200;
const int diodeIn =  A7;
unsigned long sleepTime;

void setup()
{
  Serial.begin(9600);
  analogReference(INTERNAL);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  
  sleepTime = millis() + (unsigned long)(1000)*60*10;
  Serial.print("sleep time "); Serial.print(sleepTime); Serial.println();
  
}

void loop()
{
   static int adc = 0;
   
   if (millis() > sleepTime) {
      Serial.println("going to sleep");
      ledBlack(FT);
      delay(1000);
      redDot(10);
      Serial.println("goodnight");
      delay(1000);
      sleepNow(); 
   }
   
   adc = analogRead(diodeIn);
   
   Serial.print(adc);
   Serial.println();

   ADCtoLed(adc);
   delay(1000);
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
      redDotandPause(9); 
      return;
   }
   //8	407	r8
   if (adc>=407){
      redDotandPause(8);
      return;
   }
   //7	353	r7
   if (adc>=353){
      redDotandPause(7);
      return;
   }
   //6	306	r6
   if (adc>=306){
      redDotandPause(6);      
      return;
   }
   //5	267	r5
   if (adc>=267){
      redDotandPause(5);
      return;
   }
   //4	231	r4
   if (adc>=251){
      redDotandPause(4);
      return;
   }
   //3	199	r3
   if (adc>=199){
      redDotandPause(3);
      return;
   }
   //2	170	r2
   if (adc>=170){
      redDotandPause(2);
      return;
   }
   //1	146	r1
   if (adc>=146){
      redDotandPause(1);
      return;
   }
   //0	125	gsolid
   if (adc>=125){
      ledGreen(0);
      return;
   }
  //-1	107	g1
     if (adc>=107){
      greenDotandPause(9);
      return;
   }
   //-2	91	g2
   if (adc>=91){
      greenDotandPause(8);
      return;
   }
   //-3	77	g3
   if (adc>=77){
      greenDotandPause(7);
      return;
   }
   //-4	65	g4
   if (adc>=65){
      greenDotandPause(6);
      return;
   }
   //-5	55	g5
   if (adc>=55){
      greenDotandPause(5);
      return;
   }
   //-6	46	g6
   if (adc>=46){
      greenDotandPause(4);
      return;
   }
   //-7	38	g7
   if (adc>=38){
      greenDotandPause(3);
      return;
   }
   //-8	32	g8
   if (adc>=32){
      greenDotandPause(2);
      return;
   }
   //-9	26	g9
   if (adc>=26){
      greenDotandPause(1);
      return;
   }

   //-10	22	black
   else{
      ledBlack(0);
      return;
   }
}


void redDotandPause(int n)
{
   redDot(n);
   ledBlack(2*FT); 
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

void greenDotandPause(int n)
{
   greenDot(n);
   ledBlack(2*FT); 
}

void greenDash(int n)
{
   int i;
   
   for (i=0; i < n; i++) {
      ledGreen(3*FT);
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

void sos()
{
   redDot(3);
   ledBlack(2*FT);
   redDash(3);
   ledBlack(2*FT);
   redDot(3);
   ledBlack(2*FT);
   delay(1000);
}

void sleepNow(void)
{
    //
    // Choose our preferred sleep mode:
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    //
    // Set sleep enable (SE) bit:
    sleep_enable();
    //
    // Put the device to sleep:
    sleep_mode();
}

