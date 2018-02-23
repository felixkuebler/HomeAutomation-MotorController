
#include <algorithm>
#include <functional>
#include <vector>


/*
Initializes the library and turns the motor in alternating directions.
*/
#define EN_PIN    14 
#define DIR_PIN   13
#define STEP_PIN  12


double current = 0;
double factor = 0.6;

double analog_noise_thresh = 0.2;
double thresh = 484.1;



void setup() 
{
  Serial.begin(115200);

  pinMode(EN_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);

  digitalWrite(EN_PIN, LOW);

  current = analogRead(A0);

  
}


int test_count = 0;



void loop() 
{ 

  digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
  delayMicroseconds(20);

  double analog_current = analogRead(A0);
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

  if(test_count > 50)
  {
    //Serial.print(analog_current);
    //Serial.print("\t");
    Serial.print(thresh);
    Serial.print("\t");
    Serial.println(current);

    test_count = 0;
  }
  test_count++;

  
  if(current > thresh)
  {
    //Serial.println(current);

    digitalWrite(DIR_PIN, !digitalRead(DIR_PIN));

    /*
    for (int i=0; i<1000; i++)
    {
        digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
        delayMicroseconds(80);
    }
    */
    
    digitalWrite(EN_PIN, HIGH);
    delay(500);    
    digitalWrite(EN_PIN, LOW);

    current = 0;

     
  }
  
}
