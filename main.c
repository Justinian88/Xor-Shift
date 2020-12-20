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

    /* TEST 32-bit integer*/
    a = 1, b=1, c =1;
    printf("\n1) %" PRIu32, Xorshift_32(a, b, c));
    res = mp_xorshift_32(&a, &b, &c, &val);
    printf("\n1) %" PRIu32 "\n", mp_get_i32(&val));

    /*TEST 64-bit integer*/
    a = 4, b=1, c =25;
    printf("\n2) %" PRIu64, Xorshift_64(a, b, c));
    res = mp_xorshift_64(&a, &b, &c, &val);
    printf("\n2) %" PRIu64 "\n", mp_get_i64(&val));

    mp_clear(&val);
    return 1;
}

/*
static inline uint64_t rotl(const uint64_t x, int k) {
    return (x << k) | (x >> (64 - k));
}

static uint64_t s[4] = {0xfff, 0x11f, 0x22f, 0xabcd};

uint64_t next(void) {
    const uint64_t result = rotl(s[0] + s[3], 23) + s[0];

    const uint64_t t = s[1] << 17;

    s[2] ^= s[0];
    s[3] ^= s[1];
    s[1] ^= s[2];
    s[0] ^= s[3];

    s[2] ^= t;

    s[3] = rotl(s[3], 45);

    return result;
}

void jump(void) {
    static const uint64_t JUMP[] = { 0x180ec6d33cfd0aba, 0xd5a61266f0c9392c, 0xa9582618e03fc9aa, 0x39abdc4529b1661c };

    uint64_t s0 = 0;
    uint64_t s1 = 0;
    uint64_t s2 = 0;
    uint64_t s3 = 0;
    unsigned long i;
    for(i = 0; i < sizeof JUMP / sizeof *JUMP; i++)
        for(int b = 0; b < 64; b++) {
            if (JUMP[i] & UINT64_C(1) << b) {
                s0 ^= s[0];
                s1 ^= s[1];
                s2 ^= s[2];
                s3 ^= s[3];
            }
            next();
        }

    s[0] = s0;
    s[1] = s1;
    s[2] = s2;
    s[3] = s3;
}

int main()
{
    uint64_t number;
    for (int i=0; i<4; ++i)
    {
        number = next();
        printf("%llx\n", number);
        jump();
    }
    return 0;
}
*/
