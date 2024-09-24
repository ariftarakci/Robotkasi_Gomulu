//ch7 = 0 sayac =0 ileri gitme durumu
//ch7 = 1 sayac =1 geri gitme durumu

#include "Arduino.h"
#ifndef kumanda_kontrol_h
#define kumanda_kontrol_h
#import "aci_sensoru.h" 

void tetik(){                            
  digitalWrite(yon1, HIGH);
  digitalWrite(yon2, HIGH); 
  delay(600);                               // 750 milisaniye bekle
  digitalWrite(yon1, LOW);
  digitalWrite(yon2, LOW);
  delay(600);                               // 750 milisaniye bekle
}

void tahrik_motoru(){                       // Kumanda kontrol fonksiyonu: Kumanda verilerine göre motor kontrolü yap
  if(ch7Value == 0 && ch10Value==0 ){       // Vites kontrol anahtarı kapalıysa
      if(sayac == 1)
      {                         // İleri hareket etme durumu değilse
      tetik();                              // Tetikleme işlemini gerçekleştir
      sayac = 0;                            // İleri hareket etme durumunu güncelle
      }
      if(tahrik < 0)
      {                         // İleri hareket için pozitif bir hız değeri olmalı
      tahrik = 0;
      }
      else if (tahrik > 0) 
      {
      //digitalWrite(fren, HIGH);
        //digitalWrite(mek_fren1, LOW);
        //digitalWrite(mek_fren2, HIGH);
      }
    analogWrite(tahrik_pwm, tahrik);        // Hız değerini motor hızı olarak ayarla  
  }

  else if(ch7Value == 1 && ch10Value==0){                   // Vites kontrol anahtarı açıksa
    if(sayac == 0){                         // İleri hareket etme durumu ise
      analogWrite(tahrik_pwm, 0);           // Motor hızını sıfırla
      tetik();                              // Tetikleme işlemini gerçekleştir
      sayac = 1;                            // İleri hareket etme durumunu güncelle
    }

    if(tahrik > 0)
    {                         // Geri hareket için negatif bir hız değeri olmalı
      tahrik = 0;
    } 
     else if (tahrik < 0) 
    {
       // digitalWrite(mek_fren1, LOW);
       //digitalWrite(mek_fren2, HIGH);
    }
    analogWrite(tahrik_pwm, -tahrik);
  }

  else{                                     // Diğer durumlarda
    analogWrite(tahrik_pwm, 0);             // Motor hızını sıfırla
  }
}

void dumenleme_motoru()
{

  if(dumenleme>700){
      digitalWrite(dumen_yon1,HIGH);  //sağ
      digitalWrite(dumen_yon2,LOW);
      analogWrite(dumen_pwm,130);
  }
  
  else if(dumenleme<-700){  
      digitalWrite(dumen_yon1,LOW); //sol
      digitalWrite(dumen_yon2,HIGH);  
      analogWrite(dumen_pwm,130); 
  }

  else{
      analogWrite(dumen_pwm,0);
      digitalWrite(dumen_yon1,LOW);
      digitalWrite(dumen_yon2,LOW);
  }
}

void yazdir() {
    Serial.print("    Tahrik : ");      Serial.print(tahrik);
    Serial.print("    Dümenleme : ");   Serial.print(dumenleme);
    Serial.print("    ch7 : ");         Serial.print(ch7Value);
    Serial.print("    ch8 : ");         Serial.print(ch8Value);
    Serial.print("    ch10 : ");        Serial.print(ch10Value);
    Serial.print("    Sayaç : ");       Serial.print(sayac);
    Serial.print("    Açı : ");         Serial.println(derece);
}

#endif