


#include <SoftwareSerial.h>
char* val = "0";
SoftwareSerial serial (3,4); 


const byte COL_COUNT = 8;
//array to hold the data
//
unsigned char sequence[9][4] = {
 //north-south
  {
    B00110100,
    B10010100,
    B00110100,
    B10010100

  },
  {
    B01010100,
    B01010100,
    B01010100,
    B01010100

  },
  //east-west
  {
    B10010100,
    B00110100,
    B10010100,
    B00110100

  },
  {
    B10010100,
    B01010100,
    B10010100,
    B01010100
  },
  
  {
    B10010100,
    B10010100,
    B10010100,
    B10010100

  },
  //right turnings
  //E-W
  {
    B10010100,
    B10010110,
    B10010100,
    B10010110

  },
  //N-S
  {
    B10010110,
    B10010100,
    B10010110,
    B10010110

  },
  //pedesterians
  {
    B10001000,
    B10001000,
    B10001000,
    B10001000
 

  },
  //zebra over
  {
    B01010100,
    B10010100,
    B01010100,
    B10010100

  }
};

int delaytime[COL_COUNT] = {
  5000,
  7000,
  8000,
  9000,
  2000,
  3000,
  2500,
  4500
};
//unsigned char sequence[COL_COUNT] = {1, 2, 4, 8, 16, 32, 64, 128};
//unsigned char sequence[COL_COUNT] = {0x01, 0x02, 0x04, 0x8, 0x10, 0x20, 0x40, 0x80};
//Define which pins will be used for the shift register control
//can be any digital pin on the Arduino

int east = A5; //Pin connected to DS(pin 14) of 74HC595
int latchPinE = A4; //Pin connected to ST_CP(pin 12) of 74HC595
int clockPinE = A3; //Pin connected to SH_CP(pin 11) of 74HC595

int west = 7; //Pin connected to DS(pin 14) of 74HC595
int latchPinW = 6; //Pin connected to ST_CP(pin 12) of 74HC595
int clockPinW = 5; //Pin connected to SH_CP(pin 11) of 74HC595

int north = 10; //Pin connected to DS(pin 14) of 74HC595
int latchPinN = 9; //Pin connected to ST_CP(pin 12) of 74HC595
int clockPinN = 8; //Pin connected to SH_CP(pin 11) of 74HC595

int south = A2; //Pin connected to DS(pin 14) of 74HC595
int latchPinS = A1; //Pin connected to ST_CP(pin 12) of 74HC595
int clockPinS = A0; //Pin connected to SH_CP(pin 11) of 74HC595

void setup() {
  pinMode(latchPinE, OUTPUT);
  pinMode(clockPinE, OUTPUT);
  pinMode(latchPinW, OUTPUT);
  pinMode(clockPinW, OUTPUT);
  pinMode(latchPinN, OUTPUT);
  pinMode(clockPinN, OUTPUT);
  pinMode(latchPinS, OUTPUT);
  pinMode(clockPinS, OUTPUT);
  
    pinMode(north, OUTPUT);
  pinMode(east, OUTPUT);
  pinMode(south, OUTPUT);
  pinMode(west, OUTPUT);

  serial.begin(115200);
 Serial.begin(115200);

  

}
void loop() {
  for (int col = 0; col < 10; col++) {
     //
    digitalWrite(latchPinN, LOW); //Pull latch LOW to send data
    shiftOut(north, clockPinN, LSBFIRST, sequence[col][0]); //Send the data
    digitalWrite(latchPinN, HIGH); // Pull latch HIGH to stop sending data
    //
    
    
    digitalWrite(latchPinE, LOW); //Pull latch LOW to send data
    shiftOut(east, clockPinE, LSBFIRST, sequence[col][1]); //Send the data
    digitalWrite(latchPinE, HIGH); // Pull latch HIGH to stop sending data
    
    
    digitalWrite(latchPinS, LOW); //Pull latch LOW to send data
    shiftOut(south, clockPinS, LSBFIRST, sequence[col][2]); //Send the data
    digitalWrite(latchPinS, HIGH); // Pull latch HIGH to stop sending data 

    //
    digitalWrite(latchPinW, LOW); //Pull latch LOW to send data
    shiftOut(west, clockPinW, LSBFIRST, sequence[col][3]); //Send the data
    digitalWrite(latchPinW, HIGH); // Pull latch HIGH to stop sending data
   

for(int i=0; i<20;i++)
{
if (serial.available() > 0) Serial.print("\n");
 
while (serial.available() > 0) {
Serial.print(serial.read()-48);
}
delay(10);
}

    delay(delaytime[col]);
    

  }

}
