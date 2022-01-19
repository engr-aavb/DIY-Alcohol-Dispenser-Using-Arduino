# Alcohol Auto Dispenser DIY Starter Kit Using Arduino
Keep your hands clean by filling it with liquid soap, hand sanitizer or with rubbing alcohol. By reducing physical contact, an automated dispenser keeps virus from spreading around in communal areas. Here's a guide for you, electronics enthusiasts, in creating your own DIY Alcohol Dispenser using GizDuino.

## Hardware Requirements

### Microcontroller
On this guide, you will use the GizDuino SE. But there are other microcontroller options to be used for portability.
- [Arduino Uno](https://store-usa.arduino.cc/products/arduino-uno-rev3/?selectedStore=us)
- [GizDuino SE](https://www.e-gizmo.net/oc/index.php?route=product/product&product_id=1405&search=Gizduino+se&description=true)
- [Arduino Nano](https://www.makerlab-electronics.com/product/arduino-nano-2/)



### Alcohol Auto Dispenser DIY Starter Kit
You may get the Alcohol Dispenser Kit on this [link](https://www.e-gizmo.net/oc/index.php?route=product/product&product_id=1505&search=alcohol&description=true)
This kit contains the following components:
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


On this guide, you will use [HC-SR04 Ultrasonic Distance Sensor](https://www.e-gizmo.net/oc/index.php?route=product/product&search=hc-s&product_id=1385&search=hc-s) as the sensing device to trigger the DC Water Pump


### Schematic Diagram
This section discusses the schematic diagram and how to assemble the circuit of the DIY Alcohol Auto Dispenser

![Alt text](images/Alcohol.Sanitizer.drawio.final.png?raw=true "DIY Alcohol Auto Dispenser Schematic Diagram")

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
> Make sure you connect `1k Ohms Resistor` to the **Base** of **TIP32C** before connecting it to `pin A0` of **Arduino**

![Alt text](images/Driver.PNG?raw=true "Driver Circuit")




3. Connect the 9 Volts Battery to the Circuit.

> :warning: **WARNING:**
> To see it functioning, make sure you upload the program through the Arduino IDE, which will be discussed on the next part of this guide.

![Alt text](images/battery.png?raw=true "9 Volts battery connection")



## Software Requirement
On this guide, you will use Arduino IDE. Download the IDE on this [link](https://www.arduino.cc/en/software), depending on your Computer's Operating System.


![Alt text](images/Arduino.png?raw=true "Arduino IDE Download")


> :warning: **WARNING:**
> _**If you are using Windows 10**_.    
> Do _**NOT**_ install the Arduino IDE from the Microsoft App Store. Install the original Arduino IDE from the Arduino official website. The Arduino app from the Microsoft App Store has problems using third-party Board Support Packages.


1. Open the Arduino IDE. You will see a bare minimum program file opened. It is written using [C++ Language](https://www.w3schools.com/cpp/cpp_intro.asp#:~:text=C%2B%2B%20is%20a%20cross%2Dplatform,over%20system%20resources%20and%20memory.), since most of microcontrollers' programming languages are related to C++. 

- `void setup()` is a function in Arduino IDE where it will run the program once.
- `void loop()` is a function in Arduino IDE where it will run the program on a loop.
- Before the `void setup()`, you may initialize data types such as `int`, `float`, `double`, etc.

![Alt text](images/ArduinoIDE1.PNG?raw=true "Arduino IDE Bare Minimum")
