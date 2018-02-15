/*
  Trinamic TMC2130 Example
  
  Other examples/libraries can be found here:
  https://github.com/teemuatlut/TMC2130Stepper
  https://github.com/makertum/Trinamic_TMC2130
*/

#include "SPI.h"

// Note: You also have to connect GND, 5V/VIO and VM.
//       A connection diagram can be found in the schematics.
#define EN_PIN    9 //enable (CFG6)
#define DIR_PIN   7 //direction
#define STEP_PIN  8 //step

#define CS_PIN   10 //chip select

//TMC2130 registers
#define WRITE_FLAG      (1<<7) //write flag
#define READ_FLAG       (0<<7) //read flag
#define REG_GCONF       0x00
#define REG_GSTAT       0x01
#define REG_IOIN        0x04 
#define REG_IHOLD_IRUN  0x10
#define REG_TPOWER_DOWN 0x11
#define REG_TSTEP       0x12
#define REG_TPWMTHRS    0x13
#define REG_TCOOLTHRS   0x14
#define REG_THIGH       0x15
#define REG_XDIRECT     0x2D
#define REG_VDCMIN      0x33
#define REG_MSLUT_0     0x60
//#define REG_MSLUT_1_7   0x61

#define REG_CHOPCONF    0x6C
#define REG_COOLCONF    0x6D
#define REG_DCCTRL      0x6E
#define REG_DRVSTATUS   0x6F

uint8_t tmc_write(uint8_t cmd, uint32_t data)
{
  uint8_t s;

  digitalWrite(CS_PIN, LOW);

  s = SPI.transfer(cmd);
  SPI.transfer((data>>24UL)&0xFF)&0xFF;
  SPI.transfer((data>>16UL)&0xFF)&0xFF;
  SPI.transfer((data>> 8UL)&0xFF)&0xFF;
  SPI.transfer((data>> 0UL)&0xFF)&0xFF;

  digitalWrite(CS_PIN, HIGH);

  return s;
}

uint8_t tmc_read(uint8_t reg, uint32_t *data)
{
  uint8_t s;

  tmc_write(reg, 0UL);

  digitalWrite(CS_PIN, LOW);

  s = SPI.transfer(reg);
  *data  = SPI.transfer(0x00)&0xFF;
  *data <<=8;
  *data |= SPI.transfer(0x00)&0xFF;
  *data <<=8;
  *data |= SPI.transfer(0x00)&0xFF;
  *data <<=8;
  *data |= SPI.transfer(0x00)&0xFF;

  digitalWrite(CS_PIN, HIGH);

  return s;
}

uint32_t addHex(uint32_t hex1, uint32_t hex2)
{
  return  hex1+hex2;
}

unsigned createMask(unsigned N, unsigned a, unsigned b)
{
  if (a>b) return 0;
  
   unsigned r = 0;
   for (unsigned i=a; i<=b; i++)
       r |= 1 << i;
  
   return r & N;
}



void setup()
{
  //set pins
  pinMode(2, INPUT);
  
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, HIGH); //deactivate driver (LOW active)
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(DIR_PIN, LOW); //LOW or HIGH
  pinMode(STEP_PIN, OUTPUT);
  digitalWrite(STEP_PIN, LOW);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);


  //init serial port
  Serial.begin(9600); //init serial port and set baudrate
  while(!Serial); //wait for serial port to connect (needed for Leonardo only)
  Serial.println("\nStart...");

  //init SPI
  SPI.begin();
  //SPI.setDataMode(SPI_MODE3); //SPI Mode 3
  //SPI.setBitOrder(MSBFIRST); //MSB first
  //SPI.setClockDivider(SPI_CLOCK_DIV128); //clk=Fcpu/128
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
/*
  cli();//stop interrupts
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  OCR1A = 256;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS11 bits for 8 prescaler
  TCCR1B |= (1 << CS11);// | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei();//allow interrupts
    */

  uint32_t hex =  0x00000001;
  uint32_t addedHex = addHex(hex, 0x00000004);
  Serial.println(addedHex, HEX);
 
  //set TMC2130 config
  //tmc_write(WRITE_FLAG|REG_GCONF,      0x00001081UL); //voltage on AIN is current reference
  //tmc_write(WRITE_FLAG|REG_GCONF,      0x00000001UL); //voltage on AIN is current reference
  tmc_write(WRITE_FLAG|REG_GCONF,      addedHex); //voltage on AIN is current reference, stealthchop
  //tmc_write(WRITE_FLAG|REG_TCOOLTHRS, 0xfffffUL); // 
  //tmc_write(WRITE_FLAG|REG_TCOOLTHRS, 0x00000UL); // 
  //tmc_write(WRITE_FLAG|REG_THIGH, 0x00000UL); // 
  //tmc_write(WRITE_FLAG|REG_TPWMTHRS, 0x00000UL); // 

  //tmc_write(WRITE_FLAG|REG_COOLCONF, 0x00270000UL); //stallguard value -50
  //tmc_write(WRITE_FLAG|REG_COOLCONF, 0x006c0000UL); // stallguard value -20
  //tmc_write(WRITE_FLAG|REG_COOLCONF, 0x00760000UL); // stallguard value -10
  //tmc_write(WRITE_FLAG|REG_COOLCONF, 0x00000000UL); // stallguard value 0
  //tmc_write(WRITE_FLAG|REG_COOLCONF, 0x000a0000UL); // stallguard value 10
  //tmc_write(WRITE_FLAG|REG_COOLCONF, 0x00140000UL); // stallguard value 20
  //tmc_write(WRITE_FLAG|REG_COOLCONF, 0x00320000UL); // stallguard value 50
  tmc_write(WRITE_FLAG|REG_IHOLD_IRUN, 0x00001010UL); //IHOLD=0x10, IRUN=0x10

  //tmc_write(WRITE_FLAG|REG_CHOPCONF,   0x00008008UL); //native 256 microsteps, MRES=0, TBL=1=24, TOFF=8
  tmc_write(WRITE_FLAG|REG_CHOPCONF,   0x01008008UL); //128 microsteps, MRES=0, TBL=1=24, TOFF=8
  //tmc_write(WRITE_FLAG|REG_CHOPCONF,   0x02008008UL); // 64 microsteps, MRES=0, TBL=1=24, TOFF=8
  //tmc_write(WRITE_FLAG|REG_CHOPCONF,   0x03008008UL); // 32 microsteps, MRES=0, TBL=1=24, TOFF=8
  //tmc_write(WRITE_FLAG|REG_CHOPCONF,   0x04008008UL); // 16 microsteps, MRES=0, TBL=1=24, TOFF=8
  //tmc_write(WRITE_FLAG|REG_CHOPCONF,   0x05008008UL); //  8 microsteps, MRES=0, TBL=1=24, TOFF=8
  //tmc_write(WRITE_FLAG|REG_CHOPCONF,   0x06008008UL); //  4 microsteps, MRES=0, TBL=1=24, TOFF=8
  //tmc_write(WRITE_FLAG|REG_CHOPCONF,   0x07008008UL); //  2 microsteps, MRES=0, TBL=1=24, TOFF=8
  //tmc_write(WRITE_FLAG|REG_CHOPCONF,   0x08008008UL); //  1 microsteps, MRES=0, TBL=1=24, TOFF=8

  attachInterrupt(digitalPinToInterrupt(2), interrupt_test, RISING);

  //TMC2130 outputs on (LOW active)
  digitalWrite(EN_PIN, LOW);
}

void interrupt_test()
{
  Serial.println("interrupt detected");
  digitalWrite(DIR_PIN, !digitalRead(DIR_PIN));
}

void loop()
{

  
  static uint32_t last_time=0;
  uint32_t ms = millis();
  uint32_t data;
  uint8_t s;
    /*
  if((ms-last_time) > 1000) //run every 1s
  {
    last_time = ms;

    //show REG_DRVSTATUS
    s = tmc_read(REG_DRVSTATUS, &data);
    Serial.print("DRVSTATUS: 0x");
    Serial.print(data, HEX);
    Serial.print("\t - ");
    Serial.print("Status: 0x");
    Serial.print(s, HEX);
    if(s & 0x01) Serial.print(" reset");
    if(s & 0x02) Serial.print(" error");
    if(s & 0x04) Serial.print(" sg2");
    if(s & 0x08) Serial.print(" standstill");
    Serial.println(" ");

     Serial.println(digitalRead(2));
  }
  
  */
  

  //make steps
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(10);
}
