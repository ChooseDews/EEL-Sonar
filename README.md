
# Ultrasonic Sonar
### EEL3003 UF
### John Dews-Flick
This project uses two ultrasonic sonars [`HC-SR04`](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf) mounted back to back to sweep out a 360° proximity radius. 

Full Module             |  HC-SR04 Mount
:-------------------------:|:-------------------------:
![Full Sensor](/docs/fullSensor.jpg)  |  ![Full Sensor](/docs/sensorTop.jpg)


The ultrasonic sensors and servo are controlled by an Arduino Uno, which transmits the distance value from each sensor for the 1-180 degree sweep over a serial connection. An [`Electron`](https://electronjs.org/) (Node.js) application uses the library [`serialport`](https://www.npmjs.com/package/serialport) to pick up each update compiling them into an array and graphic. The radar GUI is produced using the HTML canvas. Interpolating the cylindrical coordinates to the required cartesian system is required. 

## Radar Output

![Full Sensor](/docs/gui.png)
