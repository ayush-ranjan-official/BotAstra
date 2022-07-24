// include the Ultrasonic Distance Sensor Library
#include<UltraDistSensor.h>
// include the LCD library
//#include <LiquidCrystal.h>

//LiquidCrystal lcd(2,3,4,5,6,7);

// Defining Pins
#define trigPin1 13
#define echoPin1 12
#define trigPin2 10
#define echoPin2 11

// Defining Variables and Constants
int n = 0;
const int N = 50;
int p ;
long duration, distance, FIRSTSensor,SECONDSensor,THIRDSensor;

// put your setup code here, to run once:

void setup(){
//tells the Arduino to exchange messages with the Serial Monitor at a data rate of 9600 bits per second.
Serial.begin (9600);
//The trigger (trig) pin is the pin needed to trigger or start the sensor into ranging mode.A 10-microsend pulse needs to be sent to the trigger pulse.
//The echo pin is the pin that sends the result of the sent out pulses.
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
}
//Finds how far the object is.
void SonarSensor(int trigPin,int echoPin){

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}
//// main code is written here, to run repeatedly.
void loop() {
 

SonarSensor(trigPin1, echoPin1);
FIRSTSensor = distance;
SonarSensor(trigPin2, echoPin2);
SECONDSensor = distance;


//Serial.print("S1:");Serial.println(FIRSTSensor); delayMicroseconds(10);
//Serial.print("S2:");Serial.println(SECONDSensor);delayMicroseconds(10);


if (( n <= N ) and (n >= 0)){
  if(FIRSTSensor <= 3){
  n = n + 1 ;
    if (n<=N){

    p = N - n ;
    //lcd.begin(16,2);
    Serial.print("\nAllowed");
    Serial.print(p);
    //lcd.setCursor(0,0);lcd.print("Allowed");lcd.setCursor(8,0);lcd.print(p);
    delay(500);
    //lcd.clear();}
  } 
  if (SECONDSensor <= 3){
  n = n - 1 ;
      if (n>0){

      p = N - n ;
      //lcd.begin(16,2);
      Serial.print("\nAllowed ");
      Serial.print(p);
      //lcd.setCursor(0,0);lcd.print("Allowed");lcd.setCursor(8,0);lcd.print(p);
      delay(300);
      //lcd.clear();}
  
  }
  }else {
  p = N - n;
      if (p <= N){

      //lcd.begin(16,2);
      Serial.print("\nAllowed ");
      Serial.print(p);
      
      //lcd.setCursor(0,0);lcd.print("Allowed");lcd.setCursor(8,0);lcd.print(p);
      delay(300);
      //lcd.clear();}
  }



}
}else if ( n > N){
  //lcd.begin(16,2);
    Serial.print("\nAlert");
    
  //lcd.setCursor(0,0);lcd.print("Alert");
  delay(300);
  //lcd.clear();
}
}else if (n < 0){
  //lcd.begin(16,2);
    Serial.print("\nAllowed ");
    Serial.print(N);
  //lcd.setCursor(0,0);lcd.print("Allowed");lcd.setCursor(8,0);lcd.print(N);
  delay(300);
  //lcd.clear();
}
}
