#include "tommath.h"
#include "wiki.h"
#include "const.h"

mp_err mp_xorshift_32(int *a, int *b, int *c, mp_int *num)
{
    mp_err err;
    mp_int d;
    err = mp_init_u32(num, MY_SEED_32);
    err = mp_init_u32(&d, 0);

    err = mp_mul_2d(num, *a, num);
    err = mp_div_2d(num, *b, num, &d);
    err = mp_mul_2d(num, *c, num);

    return err;
}

mp_err mp_xorshift_64(int *a, int *b, int *c, mp_int *num)
{
    mp_err err;
    mp_int d;
    err = mp_init_u64(num, MY_SEED_64);
    err = mp_init_u64(&d, 0);

    err = mp_mul_2d(num, *a, num);
    err = mp_div_2d(num, *b, num, &d);
    err = mp_mul_2d(num, *c, num);

    return err;
}
