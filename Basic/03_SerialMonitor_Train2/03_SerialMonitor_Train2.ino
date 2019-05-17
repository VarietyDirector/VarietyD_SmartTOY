
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int a = 1;
for(int i = 0; i < 5; i++)
{
  a = a + 1;
  Serial.println(a);
  delay(500);
  }
}
