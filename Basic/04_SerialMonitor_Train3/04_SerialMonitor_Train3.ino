void setup() {
  // put your setup code here, to run once:
pinMode(2, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int a;
a = digitalRead(2);
Serial.println(a);
delay(200);
}
