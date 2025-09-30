#include <LowPower.h>

#define clock_in 2
#define data_in 3


unsigned long firstTime;  // משתנה לשמירת זמן תחילת הפעולה
unsigned long elapsedTime; 

void onInterapte();
volatile  char c;
String data="";
int count=0;
volatile  bool gotNewString=false;


void setup() {
  // put your setup code here, to run once:
pinMode(clock_in,INPUT);
pinMode(data_in,INPUT);
Serial.begin(2000000);

attachInterrupt(digitalPinToInterrupt(clock_in),onInterapte , RISING  );
}

void loop() {
  if( gotNewString &&millis()-firstTime>2500){
    Serial.print("the word is: ");
    Serial.print(data);  // הדפסת התו
    Serial.println();
    gotNewString=false;

  }
  
  // put your main code here, to run repeatedly:
  // if(gotNewString){
  //  Serial.print("the word is: ");
  // Serial.print(data);  // הדפסת התו
  // Serial.println();
  //   gotNewString=false;
  // }
  // delayMicroseconds(1);

}
void onInterapte(){
  firstTime=millis();
  //Serial.println("on interpat");
  delayMicroseconds(10);
  if(digitalRead(data_in)==1){
    c=(c<<1) | 1;
    //Serial.print("1");
  }
  else{
    c=(c<<1) | 0;
    //Serial.print("0");
  }

count++;
if(count%8==0){
  data=data+c;
  //Serial.println();
  //c='';
  //Serial.print(c); 
  gotNewString=true;
  //Serial.println("done");
  
}





}