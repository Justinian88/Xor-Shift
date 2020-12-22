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

mp_err mp_xorwow (struct mp_xorwow_set *params, mp_int *num)
{
    mp_err err;
    mp_int buff, buff2, tt, no_name;

    err = mp_init_multi(&no_name, &buff, &tt, &buff2, NULL);

    err = mp_div_2d(&params->x, 2, &buff, &no_name);
    err = mp_xor(&params->x, &buff, &tt);
    err = mp_copy(&params->y, &params->x);
    err = mp_copy(&params->z, &params->y);
    err = mp_copy(&params->w, &params->z);
    err = mp_copy(&params->v, &params->w);

    // (t^(t<<1))
    err = mp_mul_2d(&tt, 1, &buff);
    err = mp_xor(&tt, &buff, &buff);

    // (params->v^(params->v<<4))
    err = mp_mul_2d(&params->v, 4, &buff2);
    err = mp_xor(&buff2, &params->v, &buff2);

    err = mp_xor(&buff, &buff2, &params->v);

    mp_set(&no_name, 362437);
    err = mp_add(&no_name, &params->d, &params->d);
    err = mp_add(&params->v, &params->d, num);

    mp_clear_multi(&buff, &buff2, &tt, &no_name, NULL);
    return err;
}

/*
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
