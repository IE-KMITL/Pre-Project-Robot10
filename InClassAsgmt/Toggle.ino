 //2 (ขาปล่อยสัญญาณ)
//4  (ขารับสัญญาณ) จากวงจรไฟวิ่งผ่านสวิตอยู่แล้ว
int led=2;
int button=4;
int val=0;
int old_val=0;
int state=0;

void setup ()
{
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
 
}


void loop()
{ val=digitalRead(button);
if( (val==HIGH) && (old_val==LOW)) {
  state=!state;}
  old_val=val;
  if (state==1) { digitalWrite(led, HIGH);}
  else {digitalWrite (led,LOW);}
  
  


}
