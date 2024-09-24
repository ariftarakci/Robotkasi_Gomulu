#include "Arduino.h"
#ifndef otonom_modu_h
#define otonom_modu_h
#import "fren.h"

void otonomModu() {
    dataAl();
    aci_alma2();
    sol_Sinyal_yak();
    sag_Sinyal_yak();

   /////Durmayı Gerektiren Bir Durum Var mı Kontrol Et/////////
    if (pc_aci == 100)                                        //
    {                                                        //   
      digitalWrite(mek_fren1, HIGH);                        //
      digitalWrite(mek_fren2, HIGH);                       //
      analogWrite(tahrik_pwm,0);                          //
      analogWrite(dumen_pwm, 0);                         //
      digitalWrite(dumen_yon1, LOW);                    //
      digitalWrite(dumen_yon2, LOW);                   //
      digitalWrite(stop_lambasi,LOW);
      pwm=95;  //Durduktan sonra pwm 85 ile başlar  //
    }                                              //
    ///////////////   DURMA  BİTTİ    //////////////
    
    ///////Durmak Gerekmiyorsa Bu Fonksiyon içine Gir///////
    else if(pc_aci!=100 && pc_aci!=-200 && pc_aci!=200)
    {
    digitalWrite(stop_lambasi,HIGH);
    freni_birak();

    ///////////////  AÇI SINIRLAMA   ////////////////
    if(pc_aci>25)
    {
      pc_aci=25;
    }
    else if(pc_aci<-25)
    {
      pc_aci=-25;
    }
    ///////////////AÇI SINIRLAMA BİTTİ //////////////

    ///////////// DÜMENLEME FONKSİYONU /////////////
    hedef = pc_aci - derece;
    if (hedef <  2 && hedef > -2) {     
        analogWrite(tahrik_pwm, 0);
        analogWrite(dumen_pwm, 0);
        digitalWrite(dumen_yon1, LOW);
        digitalWrite(dumen_yon2, LOW);
    } else if (hedef >= 2) {
        digitalWrite(dumen_yon1, LOW);
        digitalWrite(dumen_yon2, HIGH);
        analogWrite(dumen_pwm, 130);
    } else if (hedef <= -2) {
        digitalWrite(dumen_yon1, HIGH);
        digitalWrite(dumen_yon2, LOW);
        analogWrite(dumen_pwm, 130);
    }
    ////////////// DÜMENLEME BİTTİ ////////////////

    /////////////  TAHRİK KISMI   ////////////////
     if(hiz < 800000)
    {
      pwm++;
      analogWrite(tahrik_pwm, pwm);
    }
    else if(hiz > 1000000)
    {
      pwm--;
      analogWrite(tahrik_pwm, pwm);
    }
    else
    {
      analogWrite(tahrik_pwm,pwm);
    }
    if(pwm<90)
    {
      pwm=90;
    }
    else if(pwm>108)
    {
      pwm =108;
    }
    //Serial.println(pwm);
    ///////////// TAHRİK BİTTİ  ///////////////////
} 
}

#endif 
