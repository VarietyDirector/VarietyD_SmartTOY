#include <SoftwareSerial.h>
SoftwareSerial BTSerial(4, 5);

int IN1 = 6;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int Ri=0;
int Le=0;
int enA = 3;
int enB = 2;

int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  BTSerial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);  
  
  pinMode(enA, OUTPUT);
  pinMode(IN1, OUTPUT);    
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);    
  pinMode(IN4, OUTPUT);

  // Set initial rotation direction

  // Initial speed
  motorSpeedA = 250;// 0~255//오른쪽 70
  motorSpeedB = 215;// 0~255   // 왼쪽 118부터
  //118
}
 
void loop()
{

  analogWrite(enA, motorSpeedA+Ri); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB+Le); // Send PWM signal to motor B  
  while (BTSerial.available()) 
  {

    char inChar = (char)BTSerial.read();
    
    if(inChar == '0')//정지
    {
      Le = 0;
      Ri = 0;
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      
    }
    else if(inChar == 'f')//직진
    {
      Le = 0;
      Ri = 0;
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);      
    }
    else if(inChar == 'b')//후진
    {
      Le = 0;
      Ri = 0;
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);      
    }
    else if(inChar == 'l')//좌회전
    {
      Le = -100;
      Ri = 100;
    }
    else if(inChar == 'r')//우회전
    {
      Le = 100;
      Ri = -100;
    }    
    else if(inChar == 'w')
    {
      Le = 0;
      Ri = 0;
      motorSpeedA = motorSpeedA + 10;
      motorSpeedB = motorSpeedB + 10;
   
      if (motorSpeedA > 255) 
      {
        motorSpeedA = 255;
      }
      if (motorSpeedB > 255) 
      {
        motorSpeedB = 255;
      }
      
      //Serial.println(motorSpeed);
      
    }
    else if(inChar == 's')
    {
      Le = 0;
      Ri = 0;
      motorSpeedA = motorSpeedA-10;
      motorSpeedB = motorSpeedB-10;   
      if (motorSpeedA < 0) 
      {
        motorSpeedA= 0;
      }
      if (motorSpeedB < 0) 
      {
        motorSpeedB= 0;
      }
      //Serial.println(motorSpeed);
    }
  }
}
