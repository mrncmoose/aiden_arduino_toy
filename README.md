# Basic Electronics and Micro Controller

The purpose of this code is to help teach basic electronics to young people.  This project is a stepped build with each step building on the previous ones.

## Concepts

- What is electricity:  electrical charge flowing through a conductor
- Voltage:  The pressure or force pushing the current
- Current:  The amount of electrical charge moving through the conductor
- Resistance:  What is slowing or limiting the flow of electrical charge

## Tinkercad simulator

The completed circut may be found and simulated on tinkercad here:  [tinkercad simulator](https://www.tinkercad.com/things/dfnrsZUuHO6-distance-controlled-servo)

## Materials needed

1. Small bread board with assorted jumper wires
2. USB power supply with USB C cable
3. Bread board USB C power supply
4. (1) Red LED
5. (1) Blue LED
6. (1) Green LED
7. (1) Arduino Nano Micro Controller
8. (1) Neo pixel strip with at least 4 neo pixels.  A ring may be subistuted
9. (1) Sonic distance sensor.  Either a 3 or 4 pin unit will work.
10. (3) 300 Ohm 1/4 watt resitors
11. (1) 100 uF, 50V capacitor
12. (1) Positional servo motor of 180 degree sweep
13. Personal Computer/laptop with at least one free USB port
14. The programs use the Visual Studio Code IDE with the Platform IO plug-in.  You can use the Arduino IDE also.

## Steps

### Lesson 1  Basic electrical flow using an LED

1. An LED is a Light Emitting Diode.  It converts electricity into light and only allow current to flow in one direction.  Because an LED will allow a very large amount of current to flow, it must have a small resistor to limit the current or the LED will overheat and fail.
2. The ammount of current in a given electrical circuit is governed by Ohms Law:  E = I * R.  Where E is voltage measured in Volts, I is current measured in Amps and R is the resistance measured on Ohms.  Rewritten for the find the current:  I = E/R.
3. Connect the power supply to the bread board.  Make sure the + goes into the plus side of the bread board.
4. Remove the USB power cord from the bread board.
5. Bread boards have conductors that run up and down on the edges and across the middle part of the board.
6. Select a 300 Ohm resistor and connect one end to the positive strip one the edge of the bread board.  Connect the other side to one of the middle strips.
7. Connect one end of the red LED to the negative strip.  Connect the other end to the same middle strip as the 300 ohm resistor is plugged into on the middle strip of the bread board.
8. Plug the USB power cord into the bread board power supply.
9. Does the LED light up?
   1. Yes  
      1. Remove the LED and reverse the leads to see the LED only lights up if the current is flowing in the correct direction.
      2. Remove the LED and revers the leads so it lights up again.
   2. No
      1. Remove the LED and revers the leads so it lights up.
10. Repeat for the blue and green LEDs.
11. Question:  Assume the LED's are consumming no power, how much current is being consumed?  
12. Answer:  (5V/300 Ohms) = 0.0167 Amps.  The total current is 3 * 0.0167 Amps = 0.05 Amps.
13. This is very important to know in the next lesson.

### Lesson 2:  Introduction to programable micro controllers

1. A micro controller can do many things based on inputs.  It is programmed to read the voltage on the input pins and then turn output pins on or off.  In this lesson, we will simply make the LED's blink in sequence.
2. The micro controller used in this lesson is an Arduino Nano.  The pinout diagram may be found here:  [Arduino Nano Pinout](https://content.arduino.cc/assets/Pinout-NANO_latest.pdf)
3. The Arduino Nano can only provide 0.02 Amps of current per output pin and not to exceed 0.2 Amps total  Will we overload the Arduino Nano?
4. Remove the resistor leads from the positive rail and plug them into pins in the following table
|LED Color | Arduino Pin |
|----------|-------------|
| Red      | 10          |
| Blue     | 5           |
| Green    | 6           |

5. Connect the bread board - strip to the GND pin on the Arduino Nano.
6. Clone the code from the repository [git hub repository](https://github.com/mrncmoose/basic_electronics_blink_LEDs)
7. Connect a USB cable from the computer to the Arduino Nano and up load the code.
8. Watch the LED's blink in sucession.

### Lesson 3:  Sonic Distance Sensor


