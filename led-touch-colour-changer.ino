//colour-changing LED by touch
//JW
//10-27-17

int r = 2;
int g = 3;
int b = 4;
int touch = 0;
int counter = 0;
bool busy = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  touch = analogRead(A1);
  
  Serial.println(touch);
  if (touch){
    counter = counter + 1;
    Serial.println(counter);
  }

  while (analogRead(A1)>100){
    Serial.println(analogRead(A1));
  }
  
  if (counter == 0){ //red
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
  } else if (counter == 1){ //blue
    digitalWrite(b, HIGH);
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
  } else if (counter == 2){ //green
    digitalWrite(g, HIGH);
    digitalWrite(r, LOW);
    digitalWrite(b, LOW);
  } else if (counter == 3){ //white
    digitalWrite(r, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
  } else{
    seizure(50);
  }
  
 
delay(10);
  if (counter > 3){
    counter = 0;
  }
 // delay(1000);
  
//  digitalWrite(r, LOW);
//  digitalWrite(g, LOW);
//  digitalWrite(b, LOW);
}


bool seizure(int timer){
  int len = timer;
  while (len){
    red();
    delay(30);
    green();
    delay(30);
    blue();
    delay(30);
    len = len - 1;
  }
  return 1;
}

void red(){
  //red
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
}

void blue(){
    digitalWrite(b, HIGH);
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
}

void green(){
    digitalWrite(g, HIGH);
    digitalWrite(r, LOW);
    digitalWrite(b, LOW);
}

