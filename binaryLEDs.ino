
const int counter = 3;
const int reset = 2;
const int led1 =  13;
const int led2 =  12;
const int led3 =  11;
const int led4 =  10;
const int led5 =  9;

int lastCounterState = 0;
int counterState = 0;
int resetState = 0;
int c = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(counter, INPUT);
  pinMode(reset, INPUT);
  Serial.begin(9600);
}

void loop() {
  int counterBuffer = 0;
  counterState = digitalRead(counter);
  resetState = digitalRead(reset);

  if (counterState != lastCounterState) {
    if(counterState == HIGH){
      c = c + 1;
      Serial.println(c);
    }
  }

  lastCounterState = counterState;

  if(resetState == HIGH){
    c = 0;
  }

  counterBuffer = c;


  if(counterBuffer > 0 && counterBuffer / 16 == 1){
    digitalWrite(led5, HIGH);
    counterBuffer = counterBuffer % 16;
  }else{
    digitalWrite(led5, LOW);
  }

  if(counterBuffer > 0 && counterBuffer / 8 == 1){
    digitalWrite(led4, HIGH);
    counterBuffer = counterBuffer % 8;
  }else{
    digitalWrite(led4, LOW);
  }

  if(counterBuffer > 0 && counterBuffer / 4 == 1){
    digitalWrite(led3, HIGH);
    counterBuffer = counterBuffer % 4;
  }else{
    digitalWrite(led3, LOW);
  }

  if(counterBuffer > 0 && counterBuffer / 2 == 1){
    digitalWrite(led2, HIGH);
    counterBuffer = counterBuffer % 2;
  }else{
    digitalWrite(led2, LOW);
  }

  if(counterBuffer == 1){
    digitalWrite(led1, HIGH);
  }else{
    digitalWrite(led1, LOW);
  }

  delay(100);
}
