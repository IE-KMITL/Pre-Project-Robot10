#include <HCSR04.h>

HCSR04 hc(A0,A1);//initialisation class HCSR04 (trig pin , echo pin)
 int ma1 = D2; // motor A
 int ma2 = D3; // motor A
 int mb1 = D4;// motor B
 int mb2 = D5;// motor B
 int sensor_A = A2; // sensor ตรวจจับสิ่งกีดขวางทาง ขวา
 int sensor_B = A4; // sensor ตรวจจับสิ่งกีดขวางทาง ซ้
 int   sensor_value_A = 0;
 int   sensor_value_B = 0;

 void setup() {
  pinMode(ma1, OUTPUT);
  pinMode(ma2, OUTPUT);
  pinMode(mb1, OUTPUT);
  pinMode(mb2, OUTPUT);
  pinMode(sensor_A,INPUT);
  pinMode(sensor_B,INPUT);
  
}

void loop() {
  testsensor(); // function ตรวจสอบการทำงานของ sensor ซ้าย และ ขวา
   if(hc.dist()>=20&&sensor_value_A ==0&&sensor_value_B==0 ){ testforward(); }// function เดินหน้า
      else if(hc.dist()<20&&sensor_value_A ==1&&sensor_value_B==0){ testMoveleft(); } // function เคลื่อนที่ไปทางซ้าย
        else if(hc.dist()<20&&sensor_value_A ==0&&sensor_value_B==1){ testMoveright(); } // function เคลื่อนที่ไปทาขวา
          else if (hc.dist()<20&&sensor_value_A ==1&sensor_value_B==1){ testBreak(); } // function หยุดรถ
            else testStop(); // function หยุดรถ

           //** function ที่ต้องเพิ่มเติม คือ การไปถึงเส้นแล้วกลับ รถ  แล้วเคลื่อนรถกลับไปยังจุด start (ใช้ Sensor ตรวจสอบ สี หรือ Sensor วัดระยะ)  
           // ** function ตรวจสอบขอบ สนาม 
   
}
   

 void testsensor(){
  sensor_value_A = digitalRead(sensor_A);
  sensor_value_B =digitalRead(sensor_B);
 }
 void testforward(){
  digitalWrite(ma1, LOW);   
  analogWrite(ma2, HIGH);   
  digitalWrite(mb1, LOW);   
  analogWrite(mb2, HIGH);  
  }
  void  testMoveleft(){
  digitalWrite(ma1, LOW);   
  analogWrite(ma2, HIGH);   
  digitalWrite(mb1, HIGH); // ต้องมีการ test ค่าความเร็ว 
  analogWrite(mb2, LOW);  //ต้องมีการ test ค่าความเร็ว 
  }

   void  testMoveright(){
  digitalWrite(ma1, LOW);   
  analogWrite(ma2, HIGH);   
  digitalWrite(mb1, HIGH); // ต้องมีการ test ค่าความเร็ว 
  analogWrite(mb2, LOW);  //ต้องมีการ test ค่าความเร็ว 
  }

  void  testBreak(){
  digitalWrite(ma1, HIGH);   
  analogWrite(ma2, HIGH);   
  digitalWrite(mb1, HIGH);  
  analogWrite(mb2, HIGH);  
  }

   void  testStop(){
  digitalWrite(ma1,LOW);   
  analogWrite(ma2, LOW);   
  digitalWrite(mb1, LOW);  
  analogWrite(mb2, LOW);  
   }
  
