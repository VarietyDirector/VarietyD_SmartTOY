
int ib = 0;    // for incoming serial data

// piezo buzzer를 9번핀에 연결합니다.
int buzzer = 9; 

void setup() {
  Serial.begin(9600);    // opens serial port, sets data rate to 9600 bps
  pinMode(buzzer,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    
    // read the incoming byte:
    ib = Serial.read();
    //incomingByte = incomingByte+1;
    if(ib == '1')
    {
      tone(buzzer, 261, 1000); 
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      Serial.print("Do");
    }
    else if(ib == '2')
    {
      tone(buzzer, 277, 1000); 
    }
    else if(ib == '3')
    {
      tone(buzzer, 293, 1000); 
    }
    else if(ib == '4')
    {
      tone(buzzer, 311, 1000); 
    }
     else if(ib == '5')
    {
      tone(buzzer, 329, 1000); 
    }
    
    else if(ib == '6')
    {
      tone(buzzer, 349, 1000); 
    }
    
    else if(ib == '7')
    {
      tone(buzzer, 369, 1000); 
    }
    else if(ib == '8')
    {
      tone(buzzer, 391, 1000); 
    }
    else if(ib == '9')
    {
      tone(buzzer, 415, 1000); 
    }    
    else if(ib == 'q')
    {
      tone(buzzer, 440, 1000); 
    }
    else if(ib == 'w')
    {
      tone(buzzer, 466, 1000); 
    }
    else if(ib == 'e')
    {
      tone(buzzer, 493, 1000); 
    }     
    else if(ib == '0')
    {
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      Serial.print("Off");

      noTone(buzzer);
    }
    // say what you got:
    //Serial.print((char)incomingByte);
  }
  
}
