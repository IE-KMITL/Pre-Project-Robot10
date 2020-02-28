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
digitalWrite(ia1, LOW);   // motor stop
digitalWrite(ia2, LOW);    
  digitalWrite(ib1, HIGH);   // motor break
  digitalWrite(ib2, HIGH);    
}
