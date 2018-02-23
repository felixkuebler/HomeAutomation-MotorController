
#include <algorithm>
#include <functional>
#include <vector>


/*
Initializes the library and turns the motor in alternating directions.
*/
#define EN_PIN    14 
#define DIR_PIN   13
#define STEP_PIN  12

bool dir = true;


void setup() 
{
  Serial.begin(9600);

  pinMode(EN_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);

  digitalWrite(EN_PIN, LOW);
}

int sample_counter = 0;
int sample_max_count = 50;
double sample_average = 0;

std::vector<int> samples;

double old_sample = 0;



//double thresh = 482;
double thresh = 500;



void loop() 
{
  
  digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
  delayMicroseconds(100);
  //delay(0);

  //Serial.println(analogRead(A0));

  
  samples.push_back(analogRead(A0));
  sample_average += analogRead(A0);
  sample_counter++;

  if (sample_counter > sample_max_count) 
  {
    
    std::sort(samples.begin(),samples.end());
    int mid_val = samples[sample_max_count/2];

    sample_average /= sample_max_count;
    
    int sub_sample_counter = 0;
    double sorted_average = 0;
    for (int i = sample_max_count/4; i< 3*sample_max_count/4; i++)
    {
      sorted_average += samples[i];
      sub_sample_counter++;
    }

    sorted_average /= sub_sample_counter;

    double sorted_average_smooth = (sorted_average + old_sample) /2;
    old_sample = sorted_average_smooth;

    
    Serial.print(sample_average);
    Serial.print("\t");
    Serial.print(mid_val);
    Serial.print("\t");
    Serial.print(sorted_average);
    Serial.print("\t");
    Serial.print(sorted_average_smooth);
    Serial.print("\t");
    Serial.println(thresh);

    /*
    Serial.print("Average: ");
    Serial.println(sample_average);

    Serial.print("Median: ");
    Serial.print(mid_val);

    Serial.print("Sorted Average: ");
    Serial.println(sorted_average);
    
    Serial.print("Sorted Average (Smooth): ");
    Serial.println(sorted_average_smooth);

*/

    if(sorted_average_smooth > thresh)
    {
      //Serial.println(mid_val);
      //Serial.println(sample_average);
      
      Serial.println("Stall Detected");

      
      digitalWrite(DIR_PIN, !digitalRead(DIR_PIN));

      for (int i=0; i<100; i++)
      {
          digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
          delayMicroseconds(80);
      }
      delay(500);
      old_sample = 0;

      /*
      while(true)
      {
        delay(50);
      }
      */
      
    }
    samples.clear();
    sample_average = 0;
    sample_counter = 0;

  }
 
  
}
