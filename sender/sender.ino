#define clock_out 2
#define data_out 3





String input = "";
void sendOther(char c);

void setup() {
  // put your setup code here, to run once:
pinMode(clock_out,OUTPUT);
pinMode(data_out,OUTPUT);
 digitalWrite(clock_out,LOW);
Serial.begin(2000000);
}Demonstrates synchronous bit-level communication between two Arduinos using interrupts and precise timing.

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("please enter your word:");
while(Serial.available()==0){

}
if(Serial.available()>0){
   input=Serial.readStringUntil('\n');
   

}
  Serial.println(input);

for(int i=0;i<input.length();i++){
  sendOther(input.charAt(i));
  delayMicroseconds(50);
}

}


void sendOther(char c){
for(int i=7;i>=0;i--){
  digitalWrite(clock_out,HIGH);
  delayMicroseconds(1);

  if( (c>>i)&1==1){
    digitalWrite(data_out,HIGH);
    Serial.print("1");

  } 
  else{
    digitalWrite(data_out,LOW);
    Serial.print("0");
  } 
  delayMicroseconds(50);
  digitalWrite(clock_out,LOW);
  delayMicroseconds(1000);
}
    Serial.println();


}
