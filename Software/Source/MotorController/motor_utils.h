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

  double factor = 0.6;
  double analog_noise_thresh = 0.2;
  double upper_thresh = 115;
  double lower_thresh = 90;
  double activation_thresh = 100;

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

bool isStallDetected(motor_obj &motor_info, double &current)
{
   
  double analog_current = analogRead(motor_info.pin_current);
  if (analog_current > current + motor_info.analog_noise_thresh)
  {
    current = (current + motor_info.analog_noise_thresh) + motor_info.factor * (current - (current + motor_info.analog_noise_thresh));
  }
  else if (analog_current < current - motor_info.analog_noise_thresh)
  {
    current = (current - motor_info.analog_noise_thresh) + motor_info.factor * (current - (current - motor_info.analog_noise_thresh));
  }
  else
  {
    current = analog_current + motor_info.factor * (current - analog_current);
  }


  return current > motor_info.upper_thresh || current < motor_info.lower_thresh;
}

void calibrateMotor(motor_obj &motor_info)
{
  digitalWrite(motor_info.pin_enable, LOW);
  digitalWrite(motor_info.pin_dir, LOW);

  double current = analogRead(motor_info.pin_current);
  bool enable_thresh = false;
  while (true)
  {
    if (!enable_thresh && current >= motor_info.activation_thresh && current < motor_info.upper_thresh)
    {
      enable_thresh = true;
    }
    
    digitalWrite(motor_info.pin_step, !digitalRead(motor_info.pin_step));
    delay(0);
  
    if( enable_thresh && isStallDetected(motor_info, current))
    {    
      break;
    }
  }
  digitalWrite(motor_info.pin_enable, HIGH);

  delay(500);

  digitalWrite(motor_info.pin_enable, LOW);
  digitalWrite(motor_info.pin_dir, HIGH);

  current = analogRead(motor_info.pin_current);
  enable_thresh = false;
  long step_counter = 0;
  while (true)
  {
    if (!enable_thresh && current >= motor_info.activation_thresh && current < motor_info.upper_thresh)
    {
      enable_thresh = true;
    }
    
    digitalWrite(motor_info.pin_step, !digitalRead(motor_info.pin_step));
    delay(0);
  
    if( enable_thresh && isStallDetected(motor_info, current))
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



