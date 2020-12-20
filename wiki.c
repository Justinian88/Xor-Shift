#include <stdint.h>
#include <inttypes.h>

#include "tommath.h"
#include "wiki.h"
#include "const.h"

mp_err mp_xorshift_32(int *a, int *b, int *c, mp_int *num)
{
    mp_err err;
    mp_int d, buff;
    err = mp_init_u32(num, MY_SEED_32);
    err = mp_init_u32(&d, 0);
    err = mp_init_u32(&buff, 0);

    err = mp_mul_2d(num, *a, &buff);
    err = mp_xor(num, &buff, num);

    err = mp_div_2d(num, *b, &buff, &d);
    err = mp_xor(num, &buff, num);

    err = mp_mul_2d(num, *c, &buff);
    err = mp_xor(num, &buff, num);

    mp_clear_multi(&buff, &d, NULL);

    return err;
}

mp_err mp_xorshift_64(int *a, int *b, int *c, mp_int *num)
{
    mp_err err;
    mp_int d, buff;
    err = mp_init_u64(num, MY_SEED_64);
    err = mp_init_u64(&d, 0);
    err = mp_init_u64(&buff, 0);

    err = mp_mul_2d(num, *a, &buff);
    err = mp_xor(num, &buff, num);

    err = mp_div_2d(num, *b, &buff, &d);
    err = mp_xor(num, &buff, num);

    err = mp_mul_2d(num, *c, &buff);
    err = mp_xor(num, &buff, num);

    mp_clear_multi(&buff, &d, NULL);

    return err;
}

/*
mp_err mp_xorw128 ()
{
    mp_err err;

    return err;
}

mp_err mp_xorwow ()
{
    mp_err err;

    return err;
}

mp_err mp_xorshiro_256ss ()
{
    mp_err err;

    return err;
}

mp_err mp_xorshiro_256p ()
{
    mp_err err;

    return err;
}
*/
