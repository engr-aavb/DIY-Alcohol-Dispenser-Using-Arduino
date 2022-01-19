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

|**HC-SR04**|**MCU**|
| -----   | ------------ |
| Vcc     | 5V           |
| GND     | GND          |
| Trigger | A3           |
| Echo    | A4           |

![Alt text](images/hc-sr04.PNG?raw=true "HC-SR04 Connection")


## Software Requirement
On this guide, you will use Arduino IDE. Download the IDE on this [link](https://www.arduino.cc/en/software), depending on your Computer's Operating System.


![Alt text](images/Arduino.png?raw=true "Arduino IDE Download")



