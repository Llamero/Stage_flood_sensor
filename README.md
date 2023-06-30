# Stage Flood Sensor

![](Design%20files/Images/Arduino%20sensor%20setup.png)

## Summary:

This is an open-source liquid sensor for microscopes.  It works by measuring the resistance between pairs of conductors separated by 550 µm.
![](Design%20files/Images/PCB%20layout.png)

The four-layer layout with a grid of vias connecting to the layers allows for the the sensor board to be cut and shaped as needed without interfering with the electrical connections.  

##Installation (Arduino Uno):

1) Order the sensor PCB by uploading the provided Gerber files to a PCB manufacturer such as [OSH Park](https://oshpark.com/), [PCBWay](https://www.pcbway.com/orderonline.aspx), [Ailser](https://aisler.net/), etc.
2) If using an Arduino, order the following items:
- [Arduino Uno](https://www.digikey.com/en/products/detail/arduino/A000066/2784006)
- [Piezo transducer](https://www.digikey.com/en/products/detail/mallory-sonalert-products-inc/PT-2038WQ/1957869)
- [10 kOhm throughhole resistor](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF14JT10K0/1741265)
- [Header pins](https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/61300811121/4846839)
- Wires and solder
- Note: If using the [High-Speed Programmable LED Driver](https://github.com/Llamero/Four_Channel_MHz_LED_Driver), the sensor can connect directly to the external thermistor port, so only wire and solder is needed.
3) Cut/drill the sensor PCB as needed
4) Solder across both jumpers if an RC filter isn't used, otherwise solder on the desired resistor and capacitor combination.
![](Design%20files/Images/Sensor%20connections.png)
5) Solder a pair of wires to the two wire pads.
![](https://github.com/Llamero/Stage_flood_sensor/blob/main/Design%20files/Images/Soldered%20Jumper.png)
6) Cut a set of 5 pins from the header pins.
7) Solder the 10 kOhm resistor between the 5V pin and A0 pin on the arduino.
8) Solder the positive wire to pin A0.
9) Solder the negative wire to GND.
![](Design%20files/Images/Arduino%20sensor%20setup.png)
10) Cut a pair of pins from the header pins.
11) Solder the two piezo wires to the pins (polarity does not matter).
12) Insert the pins to digital pins 6 and 7.
13) Upload the provided code to the Arduino.

## Installation (LED Driver):

1) Follow steps 1-5 for the Arduino Uno installation
2) Connect the wires to the "External Therm" port on the LED driver.
3) Set the "External Fault" temperature to 0° and the "External Warn" temperature to 1°C.  For higher sensitivity, also increase the "Resistance at 25°C" value.  For example, a value of 90000 will allow the sensor to detect deionized water.
![](Design%20files/Images/LED%20Driver%20GUI.PNG)


## Troubleshooting 

Test the driver by applying a drop of water or PBS onto the sensor.  This should trip the alarm and wiping the liquid off should reset the alarm:
- [Arduino alarm example](https://www.youtube.com/watch?v=3DOJQmaSFc4&ab_channel=BenjaminESmith)
- [LED driver example](https://www.youtube.com/watch?v=jpRJdUz0464&ab_channel=BenjaminESmith)

If the alarm trips without liquid, this means there is a short on the board.  If the board was cut or drilled, then sand these regions and inspect the board under a microscope for any shorting traces.


