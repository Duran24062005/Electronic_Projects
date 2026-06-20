const int blueLed = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(blueLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(blueLed, HIGH);
  delay(1000);
  digitalWrite(blueLed, LOW);
  delay(1000);
}
