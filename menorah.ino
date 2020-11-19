// v1.0
#include "Sodaq_DS3231.h"
//#include "hebrewdate.h"
#include <Wire.h>

#define DAY_MSECS 86400000 //there are this many miliseconds in a day

//un comment the folowing line and line 23 to set time
// DateTime dt (2019, 12, 22, 16, 34, 00, 0); // year, month, date, hour, min, sec, week day (Sunday 0, Shabbat 6) - in Julian calendar only!

int cnkDay = 22; //SET THE FIRST DAY OF CHANUKAH
int cnkMnt = 12; //SET THE MONTH IN WHICH CHANUKAH BEGINS

//time of day new candle turns on
int turnOnH = 16; // set hour with 24 hour clock

void setup(){
  
//UNCOMMENT the folowing and line 5 to set time
//  rtc.setDateTime(dt);
  
  Serial.begin(9600); //initiat sirial connection
  Wire.begin();
  rtc.begin();
  for (int i = 2; i< 10; ++i){
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);                  
  }
  
}

void loop(){
  DateTime now = rtc.now();
  int sec = now.second();
  int mnt = now.minute();
  int hur = now.hour();
  int dat = now.date();

//for testing
  Serial.print(dat);
  Serial.print('-');
  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.println(now.second());
 // Serial.println(HebrewDate;)
//end for testing
  
  if (hur >= turnOnH){
    if (dat == cnkDay){
      digitalWrite(2, LOW);
    }
    if (dat == cnkDay + 1){
      for (int i = 2; i <= 3; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 2){
      for (int i = 2; i <= 4; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 3){
      for (int i = 2; i <= 5; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 4){
      for (int i = 2; i <= 6; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 5){
      for (int i = 2; i <= 7; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 6){
      for (int i = 2; i <= 8; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 7){
      for (int i = 2; i <= 9; ++i){
        digitalWrite(i, LOW);
      }
    }
    else{};
  }
  if (hur <= turnOnH){
    if (dat == cnkDay + 1){
      digitalWrite(2, LOW);
    }
    if (dat == cnkDay + 2){
      for (int i = 2; i <= 3; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 3){
      for (int i = 2; i <= 4; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 4){
      for (int i = 2; i <= 5; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 5){
      for (int i = 2; i <= 6; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 6){
      for (int i = 2; i <= 7; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 7){
      for (int i = 2; i <= 8; ++i){
        digitalWrite(i, LOW);
      }
    }
    if (dat == cnkDay + 8){
      for (int i = 2; i <= 9; ++i){
        digitalWrite(i, LOW);
      }
    }
    else{};
  }//hu < 16
  else{
//   if(dat == cnkDay + 9){
//     for (int i = 2; i< 10; ++i){
//        digitalWrite(i, LOW);
//      }
   }
  }// last day of chanukah
//  delay(10000);
}
