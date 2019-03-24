#include <msp430f249.h>
#define uchar unsigned char
#define uint unsigned int
uchar const LED_Lib[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

void delayus(uint t)
{
  uint i;
  while (t--)
  {
    for(i=1330;i>0;i--);
  }
}

void main(void)
{
  uchar i;
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = 0xFF;
  P1SEL = 0x00;
  P1OUT = 0x00;
  while (1)
  {
    for(i=0;i<16;i++)
    {
      P1OUT = LED_Lib[i];
      delayus(100);
    }
  }
}