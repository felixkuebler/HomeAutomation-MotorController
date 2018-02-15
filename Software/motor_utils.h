#ifndef MOTOR_UTILS
#define MOTOR_UTILS

struct motor_obj
{
  String topic;
  
  short int pin_enable;
  short int pin_dir;
  short int pin_step;

  short int pin_endstop_1;
  short int pin_endstop_2;
  short int pin_pos;

  String pin_endstop_LOW;
  String pin_endstop_HIGH;
  String range_intern;
  String range_extern;
  
  short int state;

  motor_obj(): topic(""), pin_enable(0), pin_dir(0), pin_step(0), pin_endstop_1(0), pin_endstop_2(0), pin_endstop_LOW("0"), pin_endstop_HIGH("0"), pin_pos(0), range_intern("100"), range_extern("100"), state(0) {}

  motor_obj(String topic, short int pin_enable, short int pin_dir, short int pin_step, short int pin_endstop_1, short int pin_endstop_2, short int pin_pos)
  : topic(topic), pin_enable(pin_enable), pin_dir(pin_dir), pin_step(pin_step), pin_endstop_1(pin_endstop_1), pin_endstop_2(pin_endstop_2), pin_endstop_LOW("0"), pin_endstop_HIGH("0"), pin_pos(pin_pos), range_extern("100"), state(0) 
  {
    pinMode(pin_enable, OUTPUT);
    pinMode(pin_dir, OUTPUT);
    pinMode(pin_step, OUTPUT);
  
    pinMode(pin_endstop_1, INPUT);
    pinMode(pin_endstop_2, INPUT);
    //pinMode(pin_pos, INPUT);

    digitalWrite(pin_enable, HIGH);
  }

};

void calibrateMotor(motor_obj &motor_info)
{
    digitalWrite(motor_info.pin_enable, LOW);
    digitalWrite(motor_info.pin_dir, LOW);
    while (true)
    {
      if(digitalRead(motor_info.pin_endstop_1)==HIGH)
      {
        motor_info.pin_endstop_LOW = String(motor_info.pin_endstop_1);
        motor_info.pin_endstop_HIGH = String(motor_info.pin_endstop_2);
        break;
      }
      else if(digitalRead(motor_info.pin_endstop_2)==HIGH)
      {
        motor_info.pin_endstop_LOW = String(motor_info.pin_endstop_2);
        motor_info.pin_endstop_HIGH = String(motor_info.pin_endstop_1);
        break;
      }
      
      digitalWrite(motor_info.pin_step, HIGH);
      delay(0);
      delayMicroseconds(80);
      digitalWrite(motor_info.pin_step, LOW);
      delay(0);
      delayMicroseconds(80);
    }
    digitalWrite(motor_info.pin_enable, HIGH);    

    digitalWrite(motor_info.pin_enable, LOW);
    digitalWrite(motor_info.pin_dir, HIGH);  
    short int step_counter = 0;
    for ( ; digitalRead(motor_info.pin_endstop_HIGH.toInt())!=HIGH; step_counter++)
    {
      digitalWrite(motor_info.pin_step, HIGH);
      delay(0);
      delayMicroseconds(80);
      digitalWrite(motor_info.pin_step, LOW);
      delay(0);
      delayMicroseconds(80);
    }
    digitalWrite(motor_info.pin_enable, HIGH);

    motor_info.range_intern = String(step_counter);
}

String motorToString(motor_obj motor_info)
{
  String str;
  str += "motor topic : " + motor_info.topic + "\n";
  str += "motor endstop_LOW : " + motor_info.pin_endstop_LOW + "\n";
  str += "motor endstop_HIGH : " + motor_info.pin_endstop_HIGH + "\n";
  str += "motor range_intern : " + motor_info.range_intern + "\n";
  str += "motor range_extern : " + motor_info.range_extern + "\n";
  return str;
}
  
#endif //MOTOR_UTILS



