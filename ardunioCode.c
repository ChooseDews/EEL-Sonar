// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#include <Servo.h>

#define TRIGGER_PIN  9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     10  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define TRIGGER_PIN_2  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_2     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

Servo myservo;  // create servo object to control a servo
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonarTwo(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int pos = 0;    // variable to store the servo position


void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object

}

void loop() {


  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    
    myservo.write(pos);   
  delay(40); // tell servo to go to position in variable 'pos'
  Serial.print("");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.print(";");
  Serial.print(sonarTwo.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.print(";");
  Serial.println(pos);
    
    }

    
  for (pos = 180; pos >= 0; pos -= 1){
  
  myservo.write(pos);   
  delay(40); // tell servo to go to position in variable 'pos'
  Serial.print("");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.print(";");
  Serial.print(sonarTwo.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.print(";");
  Serial.println(pos);
  
  
  }





  
}