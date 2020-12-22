#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#include "tommath.h"
#include "wiki.h"
#include "xor.h"

void test1(){
    mp_int val;
    int res, a, b, c;
    res = mp_init(&val);

    a = 7, b = 1, c = 9;
    printf("\nParametrs: a = %d, b = %d, c = %d", a, b, c);
    printf("\nArticle code: %" PRIu32, Xorshift_32(a, b, c));
    res = mp_xorshift_32(&a, &b, &c, &val);
    printf("\nMy code:      %" PRIu32 "\n", mp_get_i32(&val));

    mp_clear(&val);
};
