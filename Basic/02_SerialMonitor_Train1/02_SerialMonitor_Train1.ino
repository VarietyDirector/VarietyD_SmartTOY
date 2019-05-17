int a = 1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
a = a +1;
Serial.print("a = ");
Serial.println(a);
delay(500);
}
