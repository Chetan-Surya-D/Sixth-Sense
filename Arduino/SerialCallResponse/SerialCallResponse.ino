
#define R1 10
#define R0 11
#define L1 12
#define L0 13


int inbyte = 0;         // incoming serial byte

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(7, HIGH);   
  
  establishContact();  // send a byte to establish contact until receiver responds 
}

void loop()
{
  // if we get a valid byte, read analog ins:
  establishContact();
  if (Serial.available() > 0) {
    // get incoming byte:
    inbyte = Serial.read();
    Serial.println("Recieved");
if (inbyte=='R')
{
  Serial.println("Right");
  digitalWrite(R0,HIGH);
  digitalWrite(R1,LOW);
  digitalWrite(L0,LOW);
  digitalWrite(L1,HIGH);
}
else if (inbyte == 'L')
{
  Serial.println("Left");
  digitalWrite(R0,LOW);
  digitalWrite(R1,HIGH);
  digitalWrite(L0,HIGH);
  digitalWrite(L1,LOW);
 }
 else if (inbyte=='F')
 {
  Serial.println("Forward");
  digitalWrite(R1,HIGH);
  digitalWrite(R0,LOW);
  digitalWrite(L1,HIGH);
  digitalWrite(L0,LOW);
 }
 else if (inbyte=='B')
 {
  Serial.println("Back");
  digitalWrite(R1,LOW);
  digitalWrite(R0,HIGH);
  digitalWrite(L1,LOW);
  digitalWrite(L0,HIGH);
 }
 else
{
 digitalWrite(13,HIGH);
 digitalWrite(12,HIGH);
 digitalWrite(11,HIGH);
 digitalWrite(10,HIGH);
 Serial.println("STOP");
}
delay(1000);
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
}


