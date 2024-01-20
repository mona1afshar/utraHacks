//distance sensors
const int ultraDistTrig = 1;
const int ultraDistEcho = 2;

//Motor Pins
int EN_A = 11;  //Enable pin for first motor
int IN1 = 9;    //control pin for first motor
int IN2 = 8;    //control pin for first motor
int IN3 = 7;    //control pin for second motor
int IN4 = 6;    //control pin for second motor
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
const int x_pos=800 ;             //Reading the horizontal movement value
const int y_pos=800 ;

const int colour = 140;  //value of black line colour

void setup() {
  pinMode(EN_A, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
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
  motor_speed = map(20, 400, 0, 0, 255);  //Mapping the values to 0-255 to move the motor

  if (x_pos < 400) {                           //Rotating the left motor in clockwise direction
    motor_speed = map(x_pos, 400, 0, 0, 255);  //Mapping the values to 0-255 to move the motor
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(EN_A, motor_speed);
  }

  else if (x_pos > 400 && x_pos < 600) {  //Motors will not move when the joystick will be at center
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }

  else if (x_pos > 600) {  //Rotating the left motor in anticlockwise direction
    motor_speed = map(x_pos, 600, 1023, 0, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(EN_A, motor_speed);
  }

  if (y_pos < 400) {  //Rotating the right motor in clockwise direction
    motor_speed1 = map(y_pos, 400, 0, 0, 255);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN_B, motor_speed1);
  }

  else if (y_pos > 400 && y_pos < 600) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  else if (y_pos > 600) {  //Rotating the right motor in anticlockwise direction
    motor_speed1 = map(y_pos, 600, 1023, 0, 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(EN_B, motor_speed1);
  }
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
