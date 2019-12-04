
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
  pinMode(2,OUTPUT)
  pinMode(12,OUTPUT)

}


void update(){

  int sonarOne = sonar.ping_cm();
  int sonarTwo = sonar.ping_cm();  
  Serial.print("");
  Serial.print(sonarOne); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.print(";");
  Serial.print(sonarTwo); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.print(";");
  Serial.println(pos);
  
  if(sonarOne == 0 || sonarOne > 30){
    digitalWrite(12, LOW);
  }else{
    digitalWrite(12, HIGH);
  }
  
  if(sonarTwo == 0 || sonarTwo > 30){
    digitalWrite(2, LOW);
  }else{
    digitalWrite(2, HIGH);
  }

}

void loop() {


  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    
    myservo.write(pos);   
  delay(40); // tell servo to go to position in variable 'pos'
  update();
    
    }

    
  for (pos = 180; pos >= 0; pos -= 1){
    
    
  myservo.write(pos);   
  delay(40);
  update();
  
  
  }





  
}
