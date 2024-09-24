#include "Arduino.h"
#ifndef serial_almak_h
#define serial_almak_h
#import "fren.h"
#import "serial_almak.h"  

int pc_aci = 0;                                     // Alınan veriyi tutacak değişken

void sol_Sinyal_yak() 
{
  unsigned long currentMillis = millis(); 
    if (pc_aci == -200 && !led1Yaniyor) {
      digitalWrite(sol_sinyal, LOW);    // LED'i yak
      yanmaBaslangic = currentMillis;   // Yanma başlangıç zamanını kaydet
      led1Yaniyor = true;               // LED'in yandığını işaretle
    }
  
  if (led1Yaniyor && currentMillis - yanmaBaslangic >= 5000) {
    digitalWrite(sol_sinyal, HIGH);     // LED'i söndür
    led1Yaniyor = false;                // LED'in söndüğünü işaretle
  }
}

void sag_Sinyal_yak() 
{
  unsigned long currentMillis = millis();
    if (pc_aci == 200 && !led2Yaniyor) {
      digitalWrite(sag_sinyal, LOW);       // LED'i yak
      yanmaBaslangic = currentMillis;      // Yanma başlangıç zamanını kaydet
      led2Yaniyor = true;                  // LED'in yandığını işaretle
    }
  
  if (led2Yaniyor && currentMillis - yanmaBaslangic >= 5000) {
    digitalWrite(sag_sinyal, HIGH);   // LED'i söndür
    led2Yaniyor = false;              // LED'in söndüğünü işaretle
  }
}

void dataAl()//PYTHON VERİ ALMA FONKSİYONU
{                    
  if (Serial.available() > 0)
  {
      pc_aci = Serial.readString().toInt();
  }
}

#endif