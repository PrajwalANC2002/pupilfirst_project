#include <Wire.h>




//Engage coil = LOW
//Disengage coil = HIGH

int bmsData = 1;

int Delay = 500;

void setup() {
  // initialize digital pins 2,3,4 as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  // Set up i2c communication ------------
  Wire.begin(4);                // set the address of your arduino as "4"
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output

  
}

// the loop function runs over and over again forever
void loop() {


if(bmsData == 1)
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(Delay); 
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  delay(Delay); 
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(Delay); 
}else{

delay(500);
// Print low voltage as fault in serial monitor
Serial.println("\t"); Serial.print((String)"BMS Data: "+bmsData);  Serial.print("\t");  Serial.print((String)"Fault : " + "Low voltage");  

}
}
 
// I2c incoming data below ----------------

int receiveEvent()
{
 int bmsData = Wire.read();    // receive byte as an integer

}
