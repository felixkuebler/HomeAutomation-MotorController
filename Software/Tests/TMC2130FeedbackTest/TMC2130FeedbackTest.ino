/*
Initializes the library and turns the motor in alternating directions.
*/
#define EN_PIN    9  
#define DIR_PIN   7 
#define STEP_PIN  8 

bool dir = true;


void setup() {
  Serial.begin(9600);

  pinMode(EN_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);

  digitalWrite(EN_PIN, LOW);
}

double sample_average = 0;
int sample_counter = 0;
int sample_max_count = 50;

double thresh = 2.4;

void loop() 
{
  
  digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
  //delayMicroseconds(80);



  sample_average += (double)pow((512 - analogRead(A3)),2);
  sample_counter++;
  
  if (sample_counter > sample_max_count) 
  {
    sample_average = sqrt(sample_average);
    sample_average/=(double)sample_counter;

    Serial.println(sample_average);

    if(sample_average > thresh)
    {
      Serial.println(sample_average);
      digitalWrite(DIR_PIN, !digitalRead(DIR_PIN));
    }
    sample_average = 0;
    sample_counter = 0;

    
    /*
    int mVperAmp = 185; // use 100 for 20A Module and 66 for 30A Module
    int RawValue= 0;
    int ACSoffset = 2500; 
    double Voltage = 0;
    double Amps = 0;

    RawValue = analogRead(A3);
    Voltage = (RawValue / 1024.0) * 5000; // Gets you mV
    Amps = ((Voltage - ACSoffset) / mVperAmp);
    
    
    Serial.print("Raw Value = " ); // shows pre-scaled value 
    Serial.print(RawValue); 
    Serial.print("\t mV = "); // shows the voltage measured 
    Serial.print(Voltage,3); // the '3' after voltage allows you to display 3 digits after decimal point
    Serial.print("\t Amps = "); // shows the voltage measured 
    Serial.println(Amps,3); // the '3' after voltage allows you to display 3 digits after decimal point
    */
    
    //digitalWrite(DIR_PIN, !digitalRead(DIR_PIN));
    //Serial.println(512 - analogRead(A3));
  }
}
