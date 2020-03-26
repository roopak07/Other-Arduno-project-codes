int val; 
#define m1 5     //Motor PIN=1
#define m2 6     //Motor PIN=2
#define m3 9    //Motor PIN=3
#define m4 10    //Motor Pin=4
int rpin=13; // RELAY PIN
void setup() {

  pinMode(m1, OUTPUT); 
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT); 
  pinMode(m4, OUTPUT);
  pinMode(rpin,OUTPUT);
  Serial.begin(9600);       
}

void loop() {


  if( Serial.available() )  
  {
    val = Serial.read();   
  }
  Serial.println("val:"+String(val));
  if( val == '1' )          // Move Forward      
  {
    analogWrite(m1, 50);
    analogWrite(m2, 0);
    analogWrite(m3, 50);
    analogWrite(m4, 0);
  } 
else if ( val == '2' )    // Move BACKWARD  
  {
    analogWrite(m1, 0);
    analogWrite(m2, 50);
    analogWrite(m3, 0);
    analogWrite(m4, 50);
  }
else if  ( val == '3' )      // Move RIGHT  
  {
    analogWrite(m1, 0);
    analogWrite(m2, 50);
    analogWrite(m3, 50);
    analogWrite(m4, 0);
  } 
  else if ( val == '4' )    // Move LEFT
  {
    analogWrite(m1, 50);
    analogWrite(m2, 0);
    analogWrite(m3, 0);
    analogWrite(m4, 50);
  } 

  else if(val == '5') // Relay on
  {
    digitalWrite(rpin,HIGH);
  }                          
  else if(val == '6') // Relay oFF
  {
    digitalWrite(rpin,LOW);
  }
  
  else if(val == '0') //Stop The All Motor
  {
    analogWrite(m1, 0);
    analogWrite(m2, 0);
    analogWrite(m3, 0);
    analogWrite(m4, 0);
  }                          //Stop The All Motor
  delay(50);                 
}
