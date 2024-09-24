#include "Arduino.h"
#ifndef fren_h
#define fren_h

void frenle()
{
  if(mekanik_fren==0)
  {
  digitalWrite(mek_fren1, HIGH);
  digitalWrite(mek_fren2, LOW);
  delay(1000);
  mekanik_fren=1;
    }
    else if(mekanik_fren==1)
    {
      digitalWrite(mek_fren1, HIGH);
      digitalWrite(mek_fren2, HIGH);
    }
}
void freni_birak()
{ 
  if(mekanik_fren==1)
  {
  digitalWrite(mek_fren1, LOW);
  digitalWrite(mek_fren2, HIGH);
  delay(1000);
  mekanik_fren=0;
  }
  else if(mekanik_fren==0)
    {
      digitalWrite(mek_fren1, HIGH);
      digitalWrite(mek_fren2, HIGH);
    }
}
#endif