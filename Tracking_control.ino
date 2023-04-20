#include <SoftwareSerial.h>
//-----------------------------------
SoftwareSerial BLE(2,3); //接收,發射
char command_BLE; //定義字符變數
//-----------------------------------
const byte left_01 = 9;
const byte left_02 = 8;
const byte left_pwm = 10;
byte motor_Lspeed = 148; //150 4.7//120//125//120  (120,4.06V)  backleft

const byte right_01 = 7;
const byte right_02 = 6;
const byte right_pwm = 5;
byte motor_Rspeed = 200; //200 4.5//170 //170 //158   (160,3.87V)  (172,4.13V) (170,4.1)  200 backleft


//-----------------------------------
void motor_forward(){
  digitalWrite(left_01,HIGH);
  digitalWrite(left_02,LOW);
  digitalWrite(right_01,LOW);
  digitalWrite(right_02,HIGH);
  analogWrite(left_pwm,motor_Lspeed);
  analogWrite(right_pwm,motor_Rspeed); 
}

void motor_back(){
  digitalWrite(left_01,LOW);
  digitalWrite(left_02,HIGH);
  digitalWrite(right_01,HIGH);
  digitalWrite(right_02,LOW);
  analogWrite(left_pwm,motor_Lspeed);
  analogWrite(right_pwm,motor_Rspeed);
}
  void motor_turnRight(){
  digitalWrite(left_01,HIGH);
  digitalWrite(left_02,LOW);
  digitalWrite(right_01,LOW);
  digitalWrite(right_02,LOW);
  analogWrite(left_pwm,motor_Lspeed);
  analogWrite(right_pwm,0);
  
}
  void motor_big_turnRight(){
  digitalWrite(left_01,HIGH);
  digitalWrite(left_02,LOW);
  digitalWrite(right_01,HIGH);
  digitalWrite(right_02,LOW);
  analogWrite(left_pwm,motor_Lspeed);
  analogWrite(right_pwm,0);
  
}

  void motor_turnLeft(){               
  digitalWrite(left_01,LOW);
  digitalWrite(left_02,LOW);
  digitalWrite(right_01,LOW);
  digitalWrite(right_02,HIGH);
  analogWrite(left_pwm,0);
  analogWrite(right_pwm,motor_Rspeed);
}

  void motor_big_turnLeft(){               //轉幅度大
  digitalWrite(left_01,LOW);
  digitalWrite(left_02,HIGH);
  digitalWrite(right_01,LOW);
  digitalWrite(right_02,HIGH);
  analogWrite(left_pwm,0);
  analogWrite(right_pwm,motor_Rspeed);
}
  void motor_stop(){
  digitalWrite(left_01,LOW);
  digitalWrite(left_02,LOW);
  digitalWrite(right_01,LOW);
  digitalWrite(right_02,LOW);
  analogWrite(left_pwm,0);
  analogWrite(right_pwm,0);
}
  void sencor_status(){
  Serial.print("\t");
  Serial.print(digitalRead(4));
  Serial.print("\t");
  Serial.print(digitalRead(11));
  Serial.print("\t");
  Serial.print(digitalRead(12));
  Serial.print("\n");
  delay(500);  
}
//-----------------------------------
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BLE.begin(9600); //ZS-040為HC05型號
  pinMode(left_01,OUTPUT);
  pinMode(left_02,OUTPUT);
  pinMode(left_pwm,OUTPUT);
  pinMode(right_01,OUTPUT);
  pinMode(right_02,OUTPUT);
  pinMode(right_pwm,OUTPUT);
  pinMode(4,INPUT); //右感測器
  pinMode(11,INPUT); //中間感測器
  pinMode(12,INPUT); //左感測器
}

void loop() {
  // put your main code here, to run repeatedly:
  //該方向的偵測器偵測到訊號轉向該方向(EX:左感測器 > 左轉)

  //(0,1,0)=無偵測到線路
  if(digitalRead(4)==0 and digitalRead(11)==0 and digitalRead(12)==0){
    motor_back();
    delay(20);
    motor_stop();
    delay(10);
//    Serial.print("無循跡");
//    sencor_status();
  }
   if(digitalRead(4)==1 and digitalRead(11)==1 and digitalRead(12)==1){
     
    motor_forward();
    delay(20);
    motor_stop();
    delay(10);

//    Serial.print("停止");
//    sencor_status();
  }
  //(0,1,0)=直走
  else if(digitalRead(4)==0 and digitalRead(11)==1 and digitalRead(12)==0){
    motor_forward();
    delay(20);
    motor_stop();
    delay(10);
//    Serial.print("直走");
//    sencor_status();
  }
  //(0,1,1)=左轉
  else if(digitalRead(4)==0 and digitalRead(11)==1 and digitalRead(12)==1){
    motor_turnLeft();
    delay(20);
    motor_stop();
    delay(10);
//    Serial.print("小左轉");
//    sencor_status();
  }
  //(0,0,1)=較偏的左轉
   else if(digitalRead(4)==0 and digitalRead(11)==0 and digitalRead(12)==1){
    motor_turnLeft();
    delay(20);
    motor_stop();
    delay(10);
//    Serial.print("大左轉");
//    sencor_status();
  }
  //(1,1,0)=右轉
  else if(digitalRead(4)==1 and digitalRead(11)==1 and digitalRead(12)==0){
    motor_turnRight();
    delay(20);
    motor_stop();
    delay(10); 
//    Serial.print("小右轉");
//    sencor_status();
  }
  //(0,1,1)=較偏的右轉
  else if(digitalRead(4)==1 and digitalRead(11)==0 and digitalRead(12)==0){
    motor_turnRight();
    delay(20);
    motor_stop();
    delay(10); 
//    Serial.print("大右轉");
//    sencor_status();
  }

/*藍牙功能
  if(BLE.available()){  //讀取藍芽傳輸從APP控制的資料
    command_BLE = BLE.read();  //把藍芽的command丟到變數內做判定
    switch(command_BLE){
     case 'T': 
        motor_forward();        
        break;
      case 'S':
        motor_stop();
        break;    
     }
   }
*/
}
