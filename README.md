
# Ultrasonic Sonar
This project uses two ultrasonic sonars (HC-SR04) mounted back to back to sweep out a 360° proximity radius. 

![Full Sensor](/docs/fullSensor.jpg)
![Full Sensor](/docs/sensorTop.jpg)


The ultrasonic sensors and servo are controlled by an Arduino Uno, which transmits the distance value from each sensor for the 1-180 degree sweep over a serial connection. An electron (Node.js Desktop) application uses the library 'serial port' to pick up each update compiling them into an array and graphic. The radar GUI is produced using the HTML canvas interpolating the cylindrical coordinates to the required cartesian system. 

![Full Sensor](/docs/gui.png)
