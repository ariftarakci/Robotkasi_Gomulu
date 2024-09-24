#include "Arduino.h"
#include <Wire.h>
#include <AS5600.h>
#ifndef aci_sensoru_h
#define aci_sensoru_h


#define AS5600_ADDRESS 0x36          // AS5600 I2C adresi
#define RAW_ANGLE_REGISTER 0x0C 
AS5600 as5600;

int okunanAci;
int angle;
int derece;


int aci_alma1() {
  Wire.beginTransmission(AS5600_ADDRESS);
  Wire.write(RAW_ANGLE_REGISTER);  // Açı verisinin bulunduğu registerı seç
  Wire.endTransmission();
  
  Wire.requestFrom(AS5600_ADDRESS, 2);  // 2 byte veri iste

  angle = 0;
  if (Wire.available() >= 2) {
    angle = Wire.read() << 8;      // İlk byte'ı oku ve yüksek byte olarak ayarla
    angle |= Wire.read();          // İkinci byte'ı oku ve düşük byte olarak ekle
  }
  
  return angle;
}

void aci_alma2()
{
 angle = aci_alma1();           // Açı değerini al
 derece = ((angle * 360.0) / 4096.0)-20;
 if (derece <= 0.0) {
    derece = 0.0 - derece;  // 180 dereceden küçük açılar için
  } else {
    derece = 360.0 - derece;  // 180 dereceden büyük açılar için (360 + 180 - derece)
  }
    if (derece > 0) {
      derece = map(derece, 180, 360, 0, 90);
    } else if (derece < 0) {
      derece = map(derece, 0, 180, 0, -90);
    }
    derece=derece/2;
}
#endif