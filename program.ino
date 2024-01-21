//distance sensors
const int ultraDistTrig = 12;
const int ultraDistEcho = 6;

//Motor Pins
int EN_A = 11;       //Enable pin for first motor
int motor1pin1 = 2;  //control pin for first motor
int motor1pin2 = 3;  //control pin for first motor

// Right wheel
int motor2pin1 = 4;  //control pin for second motor
int motor2pin2 = 5;  //control pin for second motor
int EN_B = 10;       //Enable pin for second motor

//Initializing variables to store data
int motor_speed; // blue
int motor_speed1;


const int lightDetectorLeft = 7;
const int lightAnalogLeft = A0;
const int lightDetectorRight = 8;
const int lightAnalogRight = A1;

const int ledRed = 9;
const int ledGreen = 13;  //BOTTOM RIGHT

long duration;
int distanceCm;

const int buttonPin = 13;
volatile byte buttonReleased = false;

//const int colour = 140;  //value of black line colour

void setup() {
  pinMode(EN_A, OUTPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(EN_B, OUTPUT);

  pinMode(ultraDistTrig, OUTPUT);
  pinMode(ultraDistEcho, INPUT);

  pinMode(lightAnalogLeft, INPUT);
  pinMode(lightAnalogLeft, INPUT);
  pinMode(lightDetectorRight, INPUT);
  pinMode(lightDetectorRight, INPUT);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonReleasedInterrupt, FALLING);

  Serial.begin(9600);
}

bool isRed = false;    // 9, Right Side
bool isGreen = false;  // 13, Left Side
int value_A0;
int value_D0;

void loop() {

  value_A0 = analogRead(lightDetectorLeft);   // reads the analog input from the IR distance sensor
  value_D0 = analogRead(lightDetectorRight);  // reads the digital input from the IR distance sensor

  // put your main code here, to run repeatedly:
  // Blue
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  analogWrite(EN_A, motor_speed);
  // Black (70% of Blue)
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  analogWrite(EN_B, motor_speed1);

  detectColour();

  delay(10);

  // Serial.println(analogRead(lightAnalogLeft));
  // Serial.println(analogRead(lightAnalogRight));
  Serial.println(digitalRead(buttonPin));

  /*int distance = sendForwardUltrasonic();
  if (distance <= 10) // AND LOCATION IS TO THE LEFT
  {
    moveRight();
    delay(500);
  }*/

  /* else if (distance <= 10) // AND LOCATION IS TO THE RIGHT
  {
    turnRight();
  }

  /* (digitalRead(buttonPin)==0){
    buttonReleased= false;
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    delay(100000);
  }*/
}

/* int sendForwardUltrasonic() {
  digitalWrite(ultraDistTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultraDistTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraDistTrig, LOW);
  duration = pulseIn(ultraDistEcho, HIGH);
  distanceCm = duration * 0.034 / 2;
  return distanceCm;
}*/

void buttonReleasedInterrupt(){
  buttonReleased=true;
  // Serial.println("released");

}

void detectColour() {
  // if light detector left reads white, move forward
  if (analogRead(lightDetectorLeft) > 850) {
    moveLeft();
  }
  //if light detector right reads white, move forward, to return to board
  else if (analogRead(lightDetectorRight) > 750) {
    moveRight();
  }
  // WORRY ABOUT CIRCLE LATER
  //otherwise move forward
  else {
    moveForward();
  }
}

//moves foward
void moveForward() {
  motor_speed = 100;   // Blue wheel
  motor_speed1 = 100;  // Black wheel
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
}

//moves backward
/* void moveBackward() {
  analogWrite(leftMotorForward, 0);
  analogWrite(rightMotorForward, 0);
  analogWrite(leftMotorBackward, 255);   //160
  analogWrite(rightMotorBackward, 255);  //150
} */

//turns right
void moveRight() {
  motor_speed = 80;
  motor_speed1 = 50;
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, LOW);
}
//turns left
void moveLeft() {

  motor_speed = 50;
  motor_speed1 = 80;
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
}

//stops all motors
/* void stopAll() {
  analogWrite(leftMotorForward, 0);
  analogWrite(rightMotorForward, 0);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, 0);
*/