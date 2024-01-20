//distance sensors
const int UltraDistTrig = 4;
const int UltraDistEcho = 5;

//motor
const int leftMotorForward = 6;
const int leftMotorBackward = 9;
const int rightMotorForward = 10;
const int rightMotorBackward = 11;

const int lightDetectorLeft = ;
const int lightDetectorRight = ;

const int ledRight = 8; //BOTTOM RIGHT
const int ledLeft = 12; //TOP RIGHT
const int ledFront = 13; //TOP LEFT
const int ledBack = 7; //BOTTOM LEFT

long duration;
int distanceCm;

const int colour = 140;
void setup()
{
  pinMode(leftMotorForward , OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);

  pinMode(UltraDistTrig, OUTPUT);
  pinMode(UltraDistEcho, INPUT);

  pinMode(lightDetectorRight, INPUT);
  pinMode(lightDetectorLeft, INPUT);

  pinMode(ledRight, OUTPUT);
  pinMode(ledLeft, OUTPUT);
  pinMode(ledFront, OUTPUT);
  pinMode(ledBack, OUTPUT);

  Serial.begin(9600);
}
void loop()
{
  detectColour();
  if (sendForwardUltrasonic() < 10)
    attackForward();
  else if (sendForwardUltrasonic() < 50)
    moveForward();
  else
    locate();
}

void detectColour() {
  //if front light detector reads white colour move backward, to return onto board
  if (analogRead (frontLight) > (colour - 100)) {
    moveBackward();
    digitalWrite(ledFront, HIGH);
    digitalWrite(ledBack, LOW);
    digitalWrite(ledLeft, LOW);
    digitalWrite(ledRight, LOW);
  }
  //if back light detector reads white light, move forward, to return to board
  else if (analogRead (backLight) > colour) {
    moveForward();
    digitalWrite(ledFront, LOW);
    digitalWrite(ledBack, HIGH);
    digitalWrite(ledLeft, LOW);
    digitalWrite(ledRight, LOW);
  }
  //if left light detector reads white light, move left to return to board
  else if (analogRead (leftLight) > colour) {
    moveRight();
    digitalWrite(ledFront, LOW);
    digitalWrite(ledBack, LOW);
    digitalWrite(ledLeft, HIGH);
    digitalWrite(ledRight, LOW);
  }
  //if right light detector reads white light, move left to return to board
  else if (analogRead (rightLight) > (colour-10)) {
    moveLeft();
    digitalWrite(ledFront, LOW);
    digitalWrite(ledBack, LOW);
    digitalWrite(ledLeft, LOW);
    digitalWrite(ledRight, HIGH);
  }

}
//sends an ultrasound burst out of the front sensor
int sendForwardUltrasonic() {
  digitalWrite(frontDistTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(frontDistTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(frontDistTrig, LOW);
  duration = pulseIn(frontDistEcho, HIGH);
  distanceCm = duration * 0.034 / 2;
  return distanceCm;
}

//sends an ultrasound burst out of the back sensor
int sendBackwardUltrasonic() {
  digitalWrite(backDistTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(backDistTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(backDistTrig, LOW);
  duration = pulseIn(backDistEcho, HIGH);
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
  analogWrite(leftMotorBackward, 255);//160
  analogWrite(rightMotorBackward, 255);//150
}

//turns right
void moveRight() {
  analogWrite(leftMotorForward, 255);//was 100
  analogWrite(rightMotorForward, 0);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, 255);//was 90
}
//turns left
void moveLeft() {
  analogWrite(leftMotorForward, 0);
  analogWrite(rightMotorForward, 255);//was 77
  analogWrite(leftMotorBackward, 255);//was 100
  analogWrite(rightMotorBackward, 0);
}

//stops all motors
void stopAll() {
  analogWrite(leftMotorForward, 0);
  analogWrite(rightMotorForward, 0);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, 0);
}
