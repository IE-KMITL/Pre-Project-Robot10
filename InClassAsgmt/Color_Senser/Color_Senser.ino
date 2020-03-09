int color = 0;
// the setup routine runs once when you press reset:
void setup() {
  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
    if(sensorValue>=140&&sensorValue<=150){color = 1 ; }// สีเหลือง
   else if(sensorValue>=151&&sensorValue<=170){color = 2;}  // สีเขียว
   else if(sensorValue>=171&&sensorValue<=250){color = 3; } // น้ำเงิน
   else {color=0;}
 
 
  if(color==1){Serial.println("สีเหลือง");}
  else if(color==2){Serial.println("สีเขียว");}
  else if (color==3){Serial.println("สีน้ำเงิน");}
  else if(color==0){Serial.println("ไม่ทราบค่า");}
 else {Serial.println("ไม่ทราบค่า");}
  delay(1);        // delay in between reads for stability
}
