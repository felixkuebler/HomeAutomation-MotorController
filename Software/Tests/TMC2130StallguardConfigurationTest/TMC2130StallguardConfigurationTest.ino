
#include <algorithm>
#include <functional>
#include <vector>


/*
Initializes the library and turns the motor in alternating directions.
*/
#define EN_PIN    14 
#define DIR_PIN   13
#define STEP_PIN  12


int sample_max_count = 25;
std::vector<int> samples;

double thresh = 487.65;



void setup() 
{
  Serial.begin(9600);

  pinMode(EN_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);

  digitalWrite(EN_PIN, LOW);

  for(int i=0; i<sample_max_count; i++)
  {
    samples.push_back(0);
  }

  
}





void loop() 
{
  
  digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
  delayMicroseconds(20);
  
  samples.push_back(analogRead(A0));
  samples.erase(samples.begin());
  
  std::vector<int> sorted_samples = samples;
  std::sort(sorted_samples.begin(),sorted_samples.end());


  int sub_sample_counter = 0;
  double sorted_average = 0;
  for (int i = sample_max_count/4; i< 3*sample_max_count/4; i++)
  {
    sorted_average += sorted_samples[i];
    sub_sample_counter++;
  }

  sorted_average /= sub_sample_counter;

  
  if(sorted_average > thresh)
    {
      Serial.println(sorted_average);

      digitalWrite(DIR_PIN, !digitalRead(DIR_PIN));

      for (int i=0; i<500; i++)
      {
          digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
          delayMicroseconds(80);
      }
      delay(500);

      samples.clear();
      for(int i=0; i<sample_max_count; i++)
      {
        samples.push_back(0);
      }   
       
    }
  
}
