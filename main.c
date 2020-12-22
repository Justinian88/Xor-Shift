#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#include "tommath.h"
#include "wiki.h"
#include "xor.h"
#include "const.h"

int main()
{
    mp_int val;
    int res, a, b, c;
    res = mp_init(&val);

    /* TEST 32-bit integer */
    printf("\n\t1 TEST 32-bit integer");
    a = 7, b = 1, c = 9;
    printf("\nParametrs: a = %d, b = %d, c = %d", a, b, c);
    printf("\nArticle code: %" PRIu32, Xorshift_32(a, b, c));
    res = mp_xorshift_32(&a, &b, &c, &val);
    printf("\nMy code:      %" PRIu32 "\n", mp_get_u32(&val));

    a = 7, b= 17, c = 21;
    printf("\nParametrs: a = %d, b = %d, c = %d", a, b, c);
    printf("\nArticle code: %" PRIu32, Xorshift_32(a, b, c));
    res = mp_xorshift_32(&a, &b, &c, &val);
    printf("\nMy code:      %" PRIu32 "\n", mp_get_u32(&val));


    /* TEST 64-bit integer */
    printf("\n\t2 TEST 64-bit integer");
    a = 16, b = 5, c = 17;
    printf("\nParametrs: a = %d, b = %d, c = %d", a, b, c);
    printf("\nArticle code: %" PRIu64, Xorshift_64(a, b, c));
    res = mp_xorshift_64(&a, &b, &c, &val);
    printf("\nMy code:      %" PRIu64 "\n", mp_get_u64(&val));


    /* TEST xorwow 192-bit integer */
    printf("\n\t3 TEST xorwow 32-bit integer");
    // Set parametrs values
    struct xorwow_set wow_prms = {WOW_X, WOW_Y, WOW_Z, WOW_W, WOW_V, WOW_D};
    struct mp_xorwow_set mp_wow_prms;
    res = mp_init_u32(&mp_wow_prms.x, WOW_X);
    res = mp_init_u32(&mp_wow_prms.y, WOW_Y);
    res = mp_init_u32(&mp_wow_prms.z, WOW_Z);
    res = mp_init_u32(&mp_wow_prms.w, WOW_W);
    res = mp_init_u32(&mp_wow_prms.v, WOW_V);
    res = mp_init_u32(&mp_wow_prms.d, WOW_D);

    printf("\n SEED:\t see const.h");
    printf("\nArticle code: %" PRIu32, XorWow_32(&wow_prms));
    res = mp_xorwow(&mp_wow_prms, &val);
    printf("\nMy code:      %" PRIu32 "\n", mp_get_u32(&val));
    mp_clear_multi(&mp_wow_prms.d, &mp_wow_prms.x, &mp_wow_prms.y, &mp_wow_prms.z, &mp_wow_prms.w, &mp_wow_prms.v, NULL);


    /* TEST xoshiftro256++ 256-bit integer */
    printf("\n\t4 TEST xoshiftro256++ 256-bit integer");
    // Set parametrs values
    printf("\n SEED:\t see const.h");
    struct xoshiro_set xoshiro_state1 = {XOSHIRO_1, XOSHIRO_2, XOSHIRO_3, XOSHIRO_4};
    struct mp_xoshiro_set mp_xoshiro_state1;
    res = mp_init_u64(&mp_xoshiro_state1.a, XOSHIRO_1);
    res = mp_init_u64(&mp_xoshiro_state1.b, XOSHIRO_2);
    res = mp_init_u64(&mp_xoshiro_state1.c, XOSHIRO_3);
    res = mp_init_u64(&mp_xoshiro_state1.d, XOSHIRO_4);
    printf("\nArticle code: %" PRIu64, xoshiro_256p(&xoshiro_state1));
    res = mp_xoshiro_256p(&mp_xoshiro_state1, &val);
    printf("\nMy code:      %" PRIu64 "\n", mp_get_u64(&val));


    /* TEST xoshiftro256** 256-bit integer*/
    printf("\n\t5 TEST xoshiftro256** 256-bit integer");
    printf("\n SEED:\t see const.h");
    printf("\nArticle code: %" PRIu64, xoshiro_256ss(&xoshiro_state1));
    res = mp_xoshiro_256ss(&mp_xoshiro_state1, &val);
    printf("\nMy code:      %" PRIu64 "\n", mp_get_u64(&val));

    return 1;
}
