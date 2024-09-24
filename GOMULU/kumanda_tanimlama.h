#include "Arduino.h"
#ifndef kumanda_tanimlama_h
#define kumanda_tanimlama_h

int kanalokuma(int kanal, int min, int max, int varsayilan){                     // Kanalların okunması
  int ch = pulseIn(kanal, HIGH, 30000);                                          // Kanalın değerini oku
  if (ch < 100) return varsayilan;                                               // Eğer değer çok düşükse, varsayılan değeri dön
  return map(ch, 1000, 2000, min, max);                                          // Değeri istenen aralığa dönüştür
}

bool switchokuma(byte kanal, bool varsayilan){                                   // Anahtarın okunması
  int intvarsayilan = (varsayilan)? 100: 0;                                      // Bool değeri integer'a dönüştür
  int ch = kanalokuma(kanal, 0, 100, intvarsayilan);                             // Kanalı oku
  return (ch > 50);                                                              // Eğer kanal değeri 50'den büyükse, anahtar açık demektir
}

void kanal(){                                                                    // Kanalların okunması ve değerlerin atanması
  dumenleme = kanalokuma(CH1, 10000, -10000, 1);                                 // Dümenleme kanalından değeri al
  tahrik = kanalokuma(CH3, -145, 145, 0);                                        // Tahrik kanalından değeri al
  ch7Value = switchokuma(CH7, true);                                             // Vites kontrol kanalından değeri al
  ch8Value = switchokuma(CH8, true);                                             // Vites kontrol kanalından değeri al
  ch10Value = switchokuma(CH10, true);                                           // Vites kontrol kanalından değeri al
}

#endif