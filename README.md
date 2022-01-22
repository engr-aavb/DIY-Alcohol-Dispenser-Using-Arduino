# Alcohol Auto Dispenser DIY Starter Kit Using Arduino
Keep your hands clean by filling it with liquid soap, hand sanitizer or with rubbing alcohol. By reducing physical contact, an automated dispenser keeps virus from spreading around in communal areas. Here's a guide for you, electronics enthusiasts, in creating your own DIY Alcohol Dispenser using GizDuino.

## Hardware Requirements

### Microcontroller
On this guide, you will use the [GizDuino SE](https://www.e-gizmo.net/oc/index.php?route=product/product&product_id=1405&search=Gizduino+se&description=true). But there are other microcontroller options to be used for portability, such as [Arduino Uno](https://store-usa.arduino.cc/products/arduino-uno-rev3/?selectedStore=us).



### Alcohol Auto Dispenser DIY Starter Kit
You may get the Alcohol Dispenser Kit on this [link](https://www.e-gizmo.net/oc/index.php?route=product/product&product_id=1505&search=alcohol&description=true).

This kit contains the following components:


![Alt text](https://www.e-gizmo.net/oc/image/cache/catalog/General/Alcohol%20Kit/211400005-5-450x350h.jpg?raw=true "DIY Alcohol Auto Dispensing Kit")

- 1x DC Water Pump
- 1x PVC Tube
- 1x Adjustable Spray Nozzle
- 1x TIP32C or 2SA1640 Transistor
- 1x IR Proximity sensor module
- 1x MicroUSB breakout board
- 1x 1N4002-4007 Rectifier Diode
- 1x 1k 1/4W Resistor
- 1x Mini Breadboard
- 1x Prototyping board


On this guide, you will use [HC-SR04 Ultrasonic Distance Sensor](https://www.e-gizmo.net/oc/index.php?route=product/product&search=hc-s&product_id=1385&search=hc-s) as the sensing device to trigger the DC Water Pump. 

![Alt text](https://hackster.imgix.net/uploads/attachments/991537/uploads2ftmp2f95250d93-b617-40b9-956c-3294973543a02fultrasonic428229_UYEDpDPTPU.png?auto=compress%2Cformat&w=1280&h=960&fit=max?raw=true "HC-SR04 Specifications")

### Schematic Diagram
This section discusses the schematic diagram and how to assemble the circuit of the DIY Alcohol Auto Dispenser.

1. Connect the HC-SR04 Ultrasonic Distance Sensor. the following pin configuration should be connected to each other.

|**HC-SR04**|**Arduino**|
| -----   | ------------ |
| Vcc     | 5V           |
| GND     | GND          |
| Trigger | A3           |
| Echo    | A4           |

![Alt text](images/hc-sr04.png?raw=true "HC-SR04 Connection")

2. Connect the Driver Circuit to the Arduino. The connection of electronic components to **TIP32C** and **Arduino** are seen on the table provided below. Then, connect the `GND` of all devices. 

|**TIP32C** |    **Connected To**      |
| -----     | ------------------------ |
| Base      | 1k Ohms Resistor -> A0   |
| Collector | +5V of DC Water Pump     |
| Emitter   | +5V of 9V-to-5V converter|

> :warning: **WARNING:**
> - Make sure you connect `1k Ohms Resistor` to the **Base** of **TIP32C** before connecting it to `pin A0` of **Arduino**

![Alt text](images/Driver.PNG?raw=true "Driver Circuit")


3. Connect the 9 Volts Battery to the Circuit.

> :warning: **WARNING:**
> - To see it functioning, make sure you upload the program through the Arduino IDE, which will be discussed on the next part of this guide.

Here's the Complete Schematic Diagram.
![Alt text](images/Alcohol.Sanitizer.drawio.final.png?raw=true "DIY Alcohol Auto Dispenser Schematic Diagram")

## Software Requirement
On this guide, you will use Arduino IDE. Download the IDE on this [link](https://www.arduino.cc/en/software), depending on your Computer's Operating System.


![Alt text](images/Arduino.png?raw=true "Arduino IDE Download")


> :warning: **WARNING:**
> - _**If you are using Windows 10**_.    
>   - Do _**NOT**_ install the Arduino IDE from the Microsoft App Store. Install the original Arduino IDE from the Arduino official website. The Arduino app from the Microsoft App Store has problems using third-party Board Support Packages.


1. Open the Arduino IDE. You will see a bare minimum program file opened. It is written using [C++ Language](https://www.w3schools.com/cpp/cpp_intro.asp#:~:text=C%2B%2B%20is%20a%20cross%2Dplatform,over%20system%20resources%20and%20memory.), since most of microcontrollers' programming languages are related to C++. 

- `void setup()` is a function in Arduino IDE where it will run the program once.
- `void loop()` is a function in Arduino IDE where it will run the program on a loop.
- Before the `void setup()`, you may initialize data types such as `int`, `float`, `double`, etc.


> **NOTE**: 
> - Curly Brackets `{}` and semicolons `;` are important in coding the program. 
> - Curly Brackets are used to know the boundary of a `function`, `if else statement`, `for loop`, and `while loop`. 
> - Semicolons are used in ending every line of the program. Failure to put a semicolon will be prompt by the Arduino IDE as an error.

![Alt text](images/ArduinoIDE1.PNG?raw=true "Arduino IDE Bare Minimum")

2. To start the programming, let's initialize the variables you need to declare. Put it **above** the `void setup()`. All variable declared in this section can be accessed both in `void setup()` and `void loop()`.

```c
//----ULTRASONIC SENSOR CONFIGURATION----//
const int trigPin1 = A3; //Set trigger pin to A3
const int echoPin1 = A4; //Set echo pin to A4
float distanceCm1; //Handling the distance in Centimeters
float duration1; //Handling the time duration of Ultrasonic Frequency
long prevMillis; //handling time interval for alcohol dispensing
//------------end of init----------------//
```
> **Variables:**
> - `const int trigPin1` sets `pin A3` as the trigger pin connected to HC-SR04.
> - `const int echoPin1` sets `pin A4` as the echo pin connected to HC-SR04.
> - `float distanceCm1` handles data for distance measured in centimeters.
> - `float duration1` handles the time duration of Ultrasonic Frequency to reflect on the sensor.
> - `long prevMillis` handles the time interval for alcohol dispensing


3. Inside the `void setup()`, let's initialize the `Serial` for Arduino to show data measured and you may also command the Arduino what to do. Then, you will declare an I/O pin either be `INPUT` or `OUTPUT` using `pinMode`. The `digitalWrite` sets the `pin A0` as logic `HIGH` for the Driver Circuit to turn off the DC Water Pump.

```c
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT
  pinMode(A0, OUTPUT); // Sets the A0 as an OUTPUT
  digitalWrite(A0,HIGH); //needed to be set HIGH due to PNP Transistor was used for Driver Circuit
}
```

4. Inside the `void loop()`, let's code the distance measurement function, displaying the measured distance in centimeters, reading Serial data, and triggering the DC Water Pump Function, when conditions are satisfied.

> **DC Water Pump Functions Condition**:
> - When a Serial data is available to be received by Arduino and if it is `char 'p'`, it will perform the DC Water Pump Function.
> - When the distance measured by HC-SR04 is _**less than or equal to**_ `5 centimeters`, it will perform the DC Water Pump Function.

```c
void loop() {
  // put your main code here, to run repeatedly:

 
  getDist1();                     //function for getting the distance measured by the ultrasonic sensor
  Serial.println(distanceCm1,2);  //Display the measured distance in cm

  
  while(Serial.available())
  {
    
    char srx=Serial.read();      //Serial Communication (Receive data from the Serial)
    if (srx=='p'){
      pumps();                   // this will be performed when a char 'p' was read from the serial
    }
  }
  
  if((millis()-prevMillis)>=1500){ //having 1500ms time interval in alcohol dispensing
    if(distanceCm1<=8){
      pumps();                     // this will be performed when distance from the Ultrasonic Sensor <= 8cm
    }
    prevMillis=millis();
  }
}
```

4. Let's add the `void pumps()` to declare the DC Water Pump Function in the program. This performs the activation of DC Water Pump for `1 Second` and deactivated after.

```c
void pumps(){
  
  Serial.println("PUMP ON");
  digitalWrite(A0,LOW);          //Activating Pump
  delay(1000);                   //Activating for 1 Second, 1000 ms = 1 Second
  digitalWrite(A0,HIGH);         //Deactivating Pump
  Serial.println("PUMP OFF");    
}
```

5. Let's add the `void getDist1`. It will measure the distance of an object from the sensor. It will send an ultrasonic frequency through the trigger transducer, and the echo transducer will receive the signal and measure the time duration of the reflected ultrasonic signal to the sensor.

```c
void getDist1(){
  //Getting the distance from the Ultrasonic Sensor


  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);   //Measuring the time duration of the signal using pulseIn
  distanceCm1= duration1*0.034/2;        //Conversion of pulseIn to actual measurement in centimeters
}
```

![Alt text](https://osoyoo.com/wp-content/uploads/2018/09/hc-sr04.png?raw=true "HC-SR04 Function")


Here's the complete Arduino Program. You may copy it and save it as `Alcohol_Dispenser.ino` in Arduino IDE. The next part of this guide shows the configuration and installation needed to upload Arduino Programs to the boards.

```c
//----ULTRASONIC SENSOR CONFIGURATION----//
const int trigPin1 = A3; //Set trigger pin to A3
const int echoPin1 = A4; //Set echo pin to A4
float distanceCm1; //Handling the distance in Centimeters
float duration1; //Handling the time duration of Ultrasonic Frequency
long prevMillis; //handling time interval for alcohol dispensing
//------------end of init----------------//

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT
  pinMode(A0, OUTPUT); // Sets the A0 as an OUTPUT
  digitalWrite(A0,HIGH); //needed to be set HIGH due to PNP Transistor was used for Driver Circuit
}

void loop() {
  // put your main code here, to run repeatedly:

 
  getDist1();                     //function for getting the distance measured by the ultrasonic sensor
  Serial.println(distanceCm1,2);  //Display the measured distance in cm

  
  while(Serial.available())
  {
    
    char srx=Serial.read();      //Serial Communication (Receive data from the Serial)
    if (srx=='p'){
      pumps();                   // this will be performed when a char 'p' was read from the serial
    }
  }
  
  if((millis()-prevMillis)>=1500){ //having 1500ms time interval in alcohol dispensing
    if(distanceCm1<=8){
      pumps();                     // this will be performed when distance from the Ultrasonic Sensor <= 8cm
    }
    prevMillis=millis();
  }
}

void pumps(){
  
  Serial.println("PUMP ON");
  digitalWrite(A0,LOW);          //Activating Pump
  delay(1000);                   //Activating for 1 Second, 1000 ms = 1 Second
  digitalWrite(A0,HIGH);         //Deactivating Pump
  Serial.println("PUMP OFF");    
}

void getDist1(){
  //Getting the distance from the Ultrasonic Sensor


  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);   //Measuring the time duration of the signal using pulseIn
  distanceCm1= duration1*0.034/2;        //Conversion of pulseIn to actual measurement in centimeters
}

```

6. Now the program is complete, let's upload the program. Make sure the `Serial Port` is set to the location of the Arduino Port. 

> **Note**: 
> - GizDuino SE may not be recognized in some Windows OS. You may download the [CH340 USB driver](https://drive.google.com/drive/folders/1OdKkHaLvMXNtWAbDbR_Zf8WIaAFE65Ai?usp=sharing) and click the `SETUP.EXE` to install.

![Alt text](images/setup.PNG?raw=true "Arduino IDE Bare Minimum")

In Windows OS, it is in `COMx`, where x is the port number. The serial number of an Arduino board differs depending to the mode the board is functioning on. For example, on bootloader mode the serial number presented to Windows' `Device Manager` is different to the serial number of the board when it is on application mode.

![Alt text](https://support.arduino.cc/hc/article_attachments/360016531980/COM_port_changes_3.png?raw=true "Device Manager")

![Alt Text](https://www.makerspaces.com/wp-content/uploads/2017/02/select-arduino-port.png?raw=true "Setting the Port to Arduino Uno on Windows OS")

In Mac or Linux OS, it is in `/dev/ttyACM0` for **Arduino Uno**, and `/dev/ttyUSB0` for **GizDuino SE**. 

![Alt Text](https://support.arduino.cc/hc/article_attachments/360016532060/COM_port_changes_4.png?raw=true "Setting the Port to Arduino Uno Mac/Linux OS")

Then, let's set the board into Arduino Uno. 
![Alt Text](https://www.makerspaces.com/wp-content/uploads/2017/02/select-arduino-board.png?raw=true "Setting the Board")


7. Now, you may press `ctrl + u` or click the `Upload` button, as seen on the image below, to upload the program to Arduino Uno. Then it will be prompted as `Done Uploading`, if it is successfully uploaded.

![Alt text](images/upload.PNG?raw=true "Successfull uploading")

8. You may use the Serial Monitor, by pressing `ctrl + shift + m`, or going to **Tools > Serial Monitor ** to see the actual data reading of HC-SR04. You may now use the `DIY-Alcohol-Auto-Dispenser` by assembling it with an Alcohol Container.

```
30.31
29.60
10.21
8.43
4.77
PUMP ON
PUMP OFF
10.55
11.23
```

![Alt Text](https://hackster.imgix.net/uploads/attachments/1100148/FVORFUDK8WIIJM3.jpg?raw=true "Alcohol Dispenser")
