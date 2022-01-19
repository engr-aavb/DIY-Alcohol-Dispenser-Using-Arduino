
//----ULTRASONIC SENSOR CONFIGURATION----//
const int trigPin1 = A3; //Set trigger pin to A3
const int echoPin1 = A4; //Set echo pin to A4
float distanceCm1;
float duration1;
//------------end of init----------------//

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT
  pinMode(A0, OUTPUT); // Sets the A0 as an OUTPUT
  digitalWrite(A0,HIGH); //needed to be HIGH due to PNP Transistor was used for Amplifier Circuit
}

void loop() {
  // put your main code here, to run repeatedly:

  //get distance from ultrasonic sensor
  getDist1();
  Serial.println(distanceCm1,2);

  
  while(Serial.available())
  {
    //Serial Communication (Receive data from the Serial)
    char srx=Serial.read(); 
    if (srx=='p'){
      // this will be performed when a char 'p' was read from the serial
      pumps(); 
    }
  }
  
  
  if(distanceCm1<=5){
    // this will be performed when distance from the Ultrasonic Sensor <= 5cm
    pumps(); 
  }
}

void pumps(){
  //Turning on and off of Pump
  Serial.println("PUMP ON");
  digitalWrite(A0,LOW);
  delay(1000);
  digitalWrite(A0,HIGH);
  Serial.println("PUMP OFF");
}

void getDist1(){
  //Getting the distance from the Ultrasonic Sensor
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distanceCm1= duration1*0.034/2;
}
