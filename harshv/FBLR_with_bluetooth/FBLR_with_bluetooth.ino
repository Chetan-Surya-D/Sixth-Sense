
#include <SoftwareSerial.h>
#define en1 2
#define en2 7
SoftwareSerial Blue(10, 11); //Rx, Tx respectively
String readdata;

void setup() 
{
  Blue.begin(9600);
  Serial.begin(9600);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() 
{
  digitalWrite(en1, HIGH);
  digitalWrite(en2, HIGH);
  while (Blue.available())      //Check if there is an available byte to read
  {  
  delay(10);                  //Delay added to make thing stable
  char c = Blue.read();         //Conduct a serial read
  readdata += c;              //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readdata.length() > 0) 
  {
    Serial.println(readdata);
    if(readdata == "F")
  {
      digitalWrite(3,HIGH);   //logic for right motor 
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);    //logic for left motor
      digitalWrite(6,HIGH);
  }

  else if(readdata == "B")
  {
      digitalWrite(3, LOW);    //logic for right motor 
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);   //logic for left motor
      digitalWrite(6, LOW);
    
  }

  else if (readdata == "L")
  {
     digitalWrite(3,HIGH);   //logic for right motor 
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);    //logic for stopping left motor
      digitalWrite(6,LOW);
  }

 else if ( readdata == "R")
 {
       digitalWrite(3,LOW);   //logic for stopping right motor 
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);    //logic for left motor
      digitalWrite(6,HIGH);  
      
      
 }

 else if (readdata == "S")
 {
       digitalWrite(3,LOW);   //logic for stopping right motor 
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);    //logic for stopping left motor
      digitalWrite(6,LOW);
     
      
 }
readdata="";        //Reset the variable
}
} 
