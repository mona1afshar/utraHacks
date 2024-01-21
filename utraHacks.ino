//distance sensors
const int ultraDistTrig = 1;
const int ultraDistEcho = 2;

//Motor Pins
int EN_A = 11;  //Enable pin for first motor
int motor1pin1 = 9;    //control pin for first motor
int motor1pin2 = 8;    //control pin for first motor
int motor2pin1 = 7;    //control pin for second motor
int motor2pin2 = 6;    //control pin for second motor
int EN_B = 10;  //Enable pin for second motor

//Initializing variables to store data
int motor_speed;
int motor_speed1;


const int lightDetectorLeft = 4;
const int lightAnalogLeft = A0;
const int lightDetectorRight = 3;
const int lightAnalogRight = A1;

const int led = 13;  //BOTTOM RIGHT

long duration;
int distanceCm;

const int colour = 140;  //value of black line colour

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
  pinMode(lightAnalogRight, INPUT);
  pinMode(lightDetectorLeft, INPUT);
  pinMode(lightDetectorRight, INPUT);

  pinMode(led, OUTPUT);

  Serial.begin(9600);
}
void loop() {
  digitalWrite(led, HIGH);
  // put your main code here, to run repeatedly:   
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(1000);

}

int sendForwardUltrasonic() {
  digitalWrite(ultraDistTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultraDistTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraDistTrig, LOW);
  duration = pulseIn(ultraDistEcho, HIGH);
  distanceCm = duration * 0.034 / 2;
  return distanceCm;
}

/*void detectColour() {
  //if front light detector reads white colour move backward, to return onto board
  if (analogRead(lightDetectorLeft) > 100) {
    moveLeft();
  }
  //if back light detector reads white light, move forward, to return to board
  else if (analogRead(lightDetectorRight) > colour) {
    moveForward();
    digitalWrite(ledFront, LOW);
    digitalWrite(ledBack, HIGH);
    digitalWrite(ledLeft, LOW);
    digitalWrite(ledRight, LOW);
  }
  //if left light detector reads white light, move left to return to board
  else if (analogRead(leftLight) > colour) {
    moveRight();
    digitalWrite(ledFront, LOW);
    digitalWrite(ledBack, LOW);
    digitalWrite(ledLeft, HIGH);
    digitalWrite(ledRight, LOW);
  }
  //if right light detector reads white light, move left to return to board
  else if (analogRead(rightLight) > (colour - 10)) {
    moveLeft();
    digitalWrite(ledFront, LOW);
    digitalWrite(ledBack, LOW);
    digitalWrite(ledLeft, LOW);
    digitalWrite(ledRight, HIGH);
  }
}
//sends an ultrasound burst out of the front sensor
int sendForwardUltrasonic() {
  digitalWrite(ultraDistTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultraDistTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(frontDistTrig, LOW);
  duration = pulseIn(frontDistEcho, HIGH);
  distanceCm = duration * 0.034 / 2;
  return distanceCm;
}

//moves foward
void moveForward() {
  analogWrite(rightMotorForward, 100);
  analogWrite(leftMotorForward, 140);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, 0);
}

//moves backward
void moveBackward() {
  analogWrite(leftMotorForward, 0);
  analogWrite(rightMotorForward, 0);
  analogWrite(leftMotorBackward, 255);   //160
  analogWrite(rightMotorBackward, 255);  //150
}

//turns right
void moveRight() {
  analogWrite(leftMotorForward, 255);  //was 100
  analogWrite(rightMotorForward, 0);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, 255);  //was 90
}
//turns left
void moveLeft() {
  analogWrite(leftMotorForward, 0);
  analogWrite(rightMotorForward, 255);  //was 77
  analogWrite(leftMotorBackward, 255);  //was 100
  analogWrite(rightMotorBackward, 0);
}

//stops all motors
void stopAll() {
  analogWrite(leftMotorForward, 0);
  analogWrite(rightMotorForward, 0);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, 0);
}*/
