#include <analogWrite.h>
#define ia1 4
#define ia2 5
#define ib1 6
#define ib2 7

#define maxSpd 255    // motor max speed

const float pi = 3.1415926;

int angle = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ia1, OUTPUT);
  pinMode(ia2, OUTPUT);
  pinMode(ib1, OUTPUT);
  pinMode(ib2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
 //if(digitalRead(ia1))
 //aStop();
  //if(digitalRead(ib1))
 //bBreak();
 aForward(maxSpd);
 bReward(maxSpd);
}

void aStop()
{
  digitalWrite(ia1, LOW);   // motor stop
  digitalWrite(ia2, LOW);    
}

void aBreak()
{
  digitalWrite(ia1, HIGH);   // motor break
  digitalWrite(ia2, HIGH);    
}

void bStop()
{
  digitalWrite(ib1, LOW);   // motor stop
  digitalWrite(ib2, LOW);    
}

void bBreak()
{
  digitalWrite(ib1, HIGH);   // motor break
  digitalWrite(ib2, HIGH);    
}

void aForward(int speed)
{
  digitalWrite(ia1, LOW);   
  analogWrite(ia2, 0.3*speed);   
}

void aReward(int speed)
{
  digitalWrite(ia2, LOW);   
  analogWrite(ia1, 0.3*speed);   
}

void bForward(int speed)
{
  digitalWrite(ib1, LOW);   
  analogWrite(ib2, 0.7*speed);   
}

void bReward(int speed)
{
  digitalWrite(ib2, LOW);   
  analogWrite(ib1, 0.7*speed);   
}
