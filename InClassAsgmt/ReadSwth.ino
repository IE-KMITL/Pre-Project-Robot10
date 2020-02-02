 //2 (ขาปล่อยสัญญาณ)
//4  (ขารับสัญญาณ) จากวงจรไฟวิ่งผ่านสวิตอยู่แล้ว
const int sw = 4;
const int led = 2;
int stateSW=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(sw,INPUT);
}

void loop() {
  stateSW = digitalRead(sw);
  if (stateSW==HIGH) {digitalWrite(led,LOW);}
  else digitalWrite(led,HIGH);
  


}
