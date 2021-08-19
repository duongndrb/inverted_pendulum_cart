#define IN1A 6
#define IN1B 7
#define PWM1 5
#define IN2A 8
#define IN2B 9
#define PWM2 10
#define POT 0

int errorcw = 0;
int errorccw = 0;
int correction = 0;
double kp = 100;
double ki = 28;
double kd = 12;
int PID = 0;
int error = 0;
int last_error = 0;
int angle = 0;
int sp = 360/5;

void setup()
{
Serial.begin(9600);
pinMode(IN1A, OUTPUT);
pinMode(IN1B, OUTPUT);
pinMode(PWM1, OUTPUT);
pinMode(IN2A, OUTPUT);
pinMode(IN2B, OUTPUT);
pinMode(PWM2, OUTPUT);
pinMode(POT, INPUT);

}

int calcPid(int error)
{
  PID = (kp*(error))+(ki*(error+last_error))+(kd*(error-last_error));
  last_error = error;
  
  return constrain(PID, 0, 255);
  //constrain() rang buoc, PID = PID neu PID thuoc [0,255], PID < 0 thi PID = 0, PID > 255 thi PID = 255
}

void loop()
{
  char buffer[5];
  angle = analogRead(POT)/5;
  Serial.println(itoa((angle), buffer, 10));
  
  if(angle>= 120 || angle<= 10){
    digitalWrite(IN2A, LOW);
    digitalWrite(IN2B, LOW);
    digitalWrite(IN1A, LOW);
    digitalWrite(IN1B, LOW);
  }
  else {
    if(angle>70 && angle<74)
    {
      digitalWrite(IN1A, LOW);
      digitalWrite(IN1B, LOW);
      digitalWrite(IN2A, LOW);
      digitalWrite(IN2B, LOW);
    }
    if(angle<70)
    {
      errorcw = (sp-angle);
      correction = calcPid(errorcw);
      analogWrite(PWM1, correction);
      //Serial.println(correction);
      digitalWrite(IN1A, LOW);
      digitalWrite(IN1B, HIGH);
      analogWrite(PWM2, correction);
      digitalWrite(IN2A, HIGH);
      digitalWrite(IN2B, LOW);
    }
    if(angle>74)
    {
      errorccw = (angle-sp);
      correction = calcPid(errorccw);
      
      analogWrite(PWM1, correction);
      //Serial.println(correction);
      digitalWrite(IN1A, HIGH);
      digitalWrite(IN1B, LOW);
      analogWrite(PWM2, correction);
      digitalWrite(IN2A, LOW);
      digitalWrite(IN2B, HIGH);
    }
  }
  return;
}
