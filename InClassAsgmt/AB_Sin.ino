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
  // put your main code here, to run repeatedly:
  //aStop();
  //bStop();
  //delay(5000);   
   
  //aForward(30);
  //delay(5000);
  //aReward(30);
  //delay(5000);  

  int aspeed = sin(pi*angle/180) * maxSpd;
  int bspeed = cos(pi*angle/180) * maxSpd;

  // try this
  //int aspeed = sin(angle/180 * pi) * maxSpd;
  //int bspeed = cos(angle/180 * pi) * maxSpd;

  Serial.print(aspeed);
  Serial.print("\t");
  Serial.println(bspeed);

  if (aspeed > 0)
    aForward(aspeed);
  else
    aReward(-aspeed);

  if (bspeed > 0)
    bForward(bspeed);
  else
    bReward(-bspeed);

  delay(20);
          
  angle++;
  if (angle == 360)
    angle = 0; 
}
void aForward(int speed)
{
  digitalWrite(ia1, LOW);   
  analogWrite(ia2, speed);   
}

void aReward(int speed)
{
  digitalWrite(ia2, LOW);   
  analogWrite(ia1, speed);   
}

void bForward(int speed)
{
  digitalWrite(ib1, LOW);   
  analogWrite(ib2, speed);   
}

void bReward(int speed)
{
  digitalWrite(ib2, LOW);   
  analogWrite(ib1, speed);   
}
