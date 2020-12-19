#include "const.h"

#ifndef XOR_H
#define XOR_H

unsigned long Xorshift_32 (int a, int b, int c)
{
     static unsigned long y= MY_SEED_32;
     y=(y<<a);
     y=(y>>b);
     y=(y<<c);
     return y;
};

unsigned long Xorshift_64 (int a, int b, int c)
{
     static unsigned long long y= MY_SEED_64;
     y=(y<<a);
     y=(y>>b);
     y=(y<<c);
     return y;
};

#endif // XOR_H
