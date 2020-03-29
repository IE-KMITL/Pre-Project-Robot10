#include <HCSR04.h>

HCSR04 hc(A0,A1);//initialisation class HCSR04 (trig pin , echo pin)
 int ma1 = 2; // motor A
 int ma2 = 3; // motor A
 int mb1 = 4;// motor B
 int mb2 = 5;// motor B
 int sensor_A = 8; // sensor ตรวจจับสิ่งกีดขวางทาง ขวา  ปกติมี output =1  ไม่เจอวัดถุ อย่าลืมปรับระยะหละ
 int sensor_B = 9; // sensor ตรวจจับสิ่งกีดขวางทาง ซ้
 int   sensor_value_A ;
 int   sensor_value_B ;
  int led=A5;
  int button=11;
  int val=0;
  int old_val=0;
  int state=0;
 void setup() {
  Serial.begin(9600);
  pinMode(ma1, OUTPUT);
  pinMode(ma2, OUTPUT);
  pinMode(mb1, OUTPUT);
  pinMode(mb2, OUTPUT);
  pinMode(sensor_A,INPUT);
  pinMode(sensor_B,INPUT);
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
  
}

void loop() {
 //Serial.println( hc.dist() );
   Serial.println( state);
   
    testsw();
  
      
     //กลยุทธ์รุก
     if(state==0){
  testsensor(); // function ตรวจสอบการทำงานของ sensor ซ้าย และ ขวา
   if(hc.dist()>=21&&sensor_value_A ==1&&sensor_value_B==1 ){ testforward(); }// function เดินหน้า
      else if(hc.dist()<20&&sensor_value_A ==0&&sensor_value_B==1){ testMoveleft(); } // function เคลื่อนที่ไปทางซ้าย
        else if(hc.dist()<20&&sensor_value_A ==1&&sensor_value_B==0){ testMoveright(); } // function เคลื่อนที่ไปทาขวา
          else if (hc.dist()<20&&sensor_value_A ==0&sensor_value_B==0){  testBreak(); } // function หยุดรถ
            else testStop(); // function หยุดรถ
     }
              // ** ล้อแบบ mecanum
           //** function ที่ต้องเพิ่มเติม คือ การไปถึงเส้นแล้วกลับ รถ  แล้วเคลื่อนรถกลับไปยังจุด start (ใช้ Sensor ตรวจสอบ สี หรือ Sensor วัดระยะ)  
           // ** function ตรวจสอบขอบ สนาม อาจใช้ sensor 3 ตัว
        
      //กลยุทธ์รับ
    else if (state==1){
      testsensor();
   if(hc.dist()<=30&&sensor_value_A ==1&&sensor_value_B==1 ){ testStop();  }// function หยุดรถ
      else if(hc.dist()>20&&sensor_value_A ==0&&sensor_value_B==1){testMoveright(); } // function เคลื่อนที่ไปทาขวา
        else if(hc.dist()>20&&sensor_value_A ==1&&sensor_value_B==0){ testMoveleft();} // function เคลื่อนที่ไปทาซ้าย
           else if(hc.dist()>=40&&sensor_value_A ==1&&sensor_value_B==1){delay(3000);searchtest();} // function ค้นหา
              else testStop(); // function หยุดรถ  */
    }
      
   
}
   

 void testsensor(){
  sensor_value_A = digitalRead(sensor_A);
  sensor_value_B =digitalRead(sensor_B);
 }
 void testsw(){
    val=digitalRead(button);
if( (val==1) && (old_val==0)) {
  state=!state;}
  old_val=val;
  delay(500);
    if(state==0){ 
      digitalWrite(A5,LOW);
    }
      else {
      digitalWrite(A5,HIGH);
      }
 }
 void searchtest(){
  
  testMoveright();
/*  if(function ตรวจสอบขอบสนามขวา =1){testMoveleft(); left=1 }
   else if(function ตรวจสอบขอบสนามซ้าย = 1) {testMoveright();}
   else teststop();*/
   
  
  }
 
 void testforward(){
  digitalWrite(ma1, HIGH);   
  analogWrite(ma2, LOW);   
  digitalWrite(mb1, HIGH);   
  analogWrite(mb2, LOW);  
  }
  void  testMoveleft(){
  digitalWrite(ma1, LOW);   
  analogWrite(ma2, HIGH);   
  digitalWrite(mb1, HIGH); // ต้องมีการ test ค่าความเร็ว 
  analogWrite(mb2, LOW);  //ต้องมีการ test ค่าความเร็ว 
  }

   void  testMoveright(){
  digitalWrite(mb1, LOW);   
  analogWrite(mb2, HIGH);   
  digitalWrite(ma1, HIGH); // ต้องมีการ test ค่าความเร็ว 
  analogWrite(ma2, LOW);  //ต้องมีการ test ค่าความเร็ว 
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
  
