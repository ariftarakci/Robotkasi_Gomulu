#import "pin_tanimlama.h"                                     // Pinlerin tanımlanması
#import "kumanda_tanimlama.h"                                 // Kumanda kanallarının tanımlanması
#import "serial_almak.h"                                      // Seri iletişim fonksiyonlarının tanımlanması
#import "kumanda_kontrol.h"                                   // Kumanda kontrol fonksiyonlarının tanımlanması
#import "otonom_modu.h"                                       // LIDAR fonksiyonlarının tanımlanması
#import "aci_sensoru.h"                                       // Açı Sensörü fonksiyonlarının tanımlanması


void setup() {
  Serial.begin(9600); 
  Serial.setTimeout(1);    
  Wire.begin();

  pinMode(CH1, INPUT);                                        // Pinlerin modlarını ayarla
  pinMode(CH3, INPUT);                                        // Pinlerin modlarını ayarla
  pinMode(CH7, INPUT);                                        // Pinlerin modlarını ayarla
  pinMode(CH8, INPUT);                                        // Pinlerin modlarını ayarla
  pinMode(CH10, INPUT);                                       // Pinlerin modlarını ayarla

  pinMode(tahrik_pwm, OUTPUT);
  pinMode(dumen_pwm, OUTPUT);
  
  pinMode(dumen_yon1, OUTPUT);
  pinMode(dumen_yon2, OUTPUT);

  pinMode(mek_fren1, OUTPUT);
  pinMode(mek_fren2, OUTPUT);

  pinMode(yon1, OUTPUT);
  pinMode(yon2, OUTPUT); 

  digitalWrite(dumen_yon1, LOW);                             // Tetik 1'i devre dışı bırak
  digitalWrite(dumen_yon2, LOW);

  digitalWrite(mek_fren1, HIGH);                             // Tetik 1'i devre dışı bırak
  digitalWrite(mek_fren2, HIGH);

  pinMode(sag_sinyal, OUTPUT);
  pinMode(sol_sinyal, OUTPUT);
  pinMode(far, OUTPUT);
  pinMode(stop_lambasi, OUTPUT);
  digitalWrite(sol_sinyal, HIGH);
  digitalWrite(sag_sinyal, HIGH);
  digitalWrite(far, HIGH); 
  digitalWrite(stop_lambasi, HIGH);
}

void loop() {
  kanal();
  if(ch10Value == 0)        //Manuel mod anahtarı
  {
    kanal();
    aci_alma2();
    tahrik_motoru();
    dumenleme_motoru();
    yazdir();
    pwm=90;
  }

  else if(ch10Value == 1)   //Otonom modu anahtarı
  {
    otonomModu();
  }
}

