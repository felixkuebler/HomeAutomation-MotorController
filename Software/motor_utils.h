#ifndef MOTOR_UTILS
#define MOTOR_UTILS

struct motor_obj
{
  String topic;
  
  short int pin_enable;
  short int pin_dir;
  short int pin_step;

  short int pin_current;

  String range_intern;
  String range_extern;
  
  long state;

  motor_obj(): topic(""), pin_enable(0), pin_dir(0), pin_step(0), pin_current(0), range_intern("100"), range_extern("100"), state(0) {}

  motor_obj(String topic, short int pin_enable, short int pin_dir, short int pin_step, short int pin_current)
  : topic(topic), pin_enable(pin_enable), pin_dir(pin_dir), pin_step(pin_step), pin_current(pin_current), range_extern("100"), state(0) 
  {
    pinMode(pin_enable, OUTPUT);
    pinMode(pin_dir, OUTPUT);
    pinMode(pin_step, OUTPUT);

    pinMode(pin_current, INPUT);

    digitalWrite(pin_enable, HIGH);
  }

};

bool isStallDetected(short int pin_current, double &current)
{
  double factor = 0.6;
  double analog_noise_thresh = 0.2;
  double thresh = 486;
  
  double analog_current = analogRead(pin_current);
  if (analog_current > current + analog_noise_thresh)
  {
    current = (current + analog_noise_thresh) + factor * (current - (current + analog_noise_thresh));
  }
  else if (analog_current < current - analog_noise_thresh)
  {
    current = (current - analog_noise_thresh) + factor * (current - (current - analog_noise_thresh));
  }
  else
  {
    current = analog_current + factor * (current - analog_current);
  }

  return current > thresh;
}

void calibrateMotor(motor_obj &motor_info)
{
  digitalWrite(motor_info.pin_enable, LOW);
  digitalWrite(motor_info.pin_dir, LOW);

  double current = analogRead(motor_info.pin_current);
  while (true)
  {
    digitalWrite(motor_info.pin_step, !digitalRead(motor_info.pin_step));
    delay(0);
  
    if( isStallDetected(motor_info.pin_current, current))
    {    
      break;
    }
  }
  digitalWrite(motor_info.pin_enable, HIGH);

  delay(500);

  digitalWrite(motor_info.pin_enable, LOW);
  digitalWrite(motor_info.pin_dir, HIGH);

  current = analogRead(motor_info.pin_current);
  long step_counter = 0;
  while (true)
  {
    digitalWrite(motor_info.pin_step, !digitalRead(motor_info.pin_step));
    delay(0);
  
    if(isStallDetected(motor_info.pin_current, current))
    {    
      break;
    }

    step_counter++;
  }

  digitalWrite(motor_info.pin_enable, HIGH);

  motor_info.range_intern = String(step_counter);
}

String motorToString(motor_obj motor_info)
{
  String str;
  str += "motor topic : " + motor_info.topic + "\n";
  str += "motor range_intern : " + motor_info.range_intern + "\n";
  str += "motor range_extern : " + motor_info.range_extern + "\n";
  return str;
}

  
#endif //MOTOR_UTILS



