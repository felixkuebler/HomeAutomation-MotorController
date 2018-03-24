#define EN_PIN    14 
#define DIR_PIN   13
#define STEP_PIN  12
#define SensorPin A0

void setup() 
{

  pinMode(EN_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);

  digitalWrite(EN_PIN, LOW);
  
}

void loop() 
{ 

  delay(10);
  
}
