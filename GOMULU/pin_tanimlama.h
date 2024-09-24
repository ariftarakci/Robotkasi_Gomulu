#include "Arduino.h"
#include <Stepper.h>
#ifndef pin_tanimlama_h
#define pin_tanimlama_h

#define CH1 33                                      // Dümenleme kontrol kanalı
#define CH3 35                                      // Tahrik kontrol kanalı
#define CH7 37                                      // Vites kontrol kanalı
#define CH8 39                                      // Vites kontrol kanalı
#define CH10 4                                      // Vites kontrol kanalı

#define dumen_pwm 27                             
#define dumen_yon1 10
#define dumen_yon2 11

int hedef;
uint8_t sayac = 0;                                  // ileri geri durumunu kontrol için
int dumenleme;                                      // Dümenleme kontrol değeri
int tahrik;                                         // Tahrik kontrol değeri
bool ch7Value;                                      // Vites kontrol değeri
bool ch8Value;                                      // Vites kontrol değeri
bool ch10Value;                                     // Vites kontrol değeri                   
int tetiklendi;
int i=0;

#define tahrik_pwm 13                            // Tahrik motoru PWM Pini
#define yon1 29
#define yon2 49
#define mek_fren1 22                                // Fren 1
#define mek_fren2 24                                 // Fren 2
bool mekanik_fren=0;

#define sag_sinyal 30
#define sol_sinyal 32 
#define far 42 
#define stop_lambasi 52
unsigned long yanmaBaslangic = 0;   // LED'in yanmaya başladığı zamanı tutan değişken
bool led1Yaniyor = false;
bool led2Yaniyor = false;

int pwm=85;
int hiz;

#endif