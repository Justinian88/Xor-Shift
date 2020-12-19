#include <stdio.h>
#include <stdlib.h>

#include "tommath.h"
#include "wiki.h"
#include "xor.h"
#include "const.h"

int main()
{
    mp_int val;
    int res;
    char stroka[150];
    res = mp_init(&val);

    /* TEST 32-bit integer */
    int a = 1, b=3, c =10;
    printf("\n1) %lu \n", Xorshift_32(a, b, c));
    res = mp_xorshift_32(&a, &b, &c, &val);
    res = mp_to_radix(&val, stroka, 150, NULL, 10);
    printf("1) %s \n" , stroka);

    /* TEST 64-bit integer */
    a = 4, b=1, c =25;
    printf("\n2) %lu \n", Xorshift_64(a, b, c));
    res = mp_xorshift_64(&a, &b, &c, &val);
    res = mp_to_radix(&val, stroka, 150, NULL, 10);
    printf("2) %s \n" , stroka);

    return 1;
}


/*
int main()
{
    mp_int A, B, C;
    int res;
    res = mp_init(&A);
    res = mp_init(&B);
    res = mp_init(&C);

    res = mp_read_radix(&A, "14", 10);
    res = mp_read_radix(&B, "127", 10);

    res = mp_xor(&A, &B, &C);
    char stroka[150];
    res = mp_to_radix(&A, stroka, 150, NULL, 10);
    printf("\n%s \n" , stroka);
    res = mp_to_radix(&B, stroka, 150, NULL, 10);
    printf("\n%s \n" , stroka);
    res = mp_to_radix(&C, stroka, 150, NULL, 10);
    printf("\n%s \n" , stroka);

    return 1;
}


int main()
{
    printf("Hello, world!\n");
    int i;
    struct xoshiro256ss_state number = {0xfff, 0x11f, 0x22f, 0xabcd};
    for (i=0; i<4; ++i)
    {
        printf("%llx\n", number.s[i]);
    }
    uint64_t result = xoshiro256ss(&number);
    printf("%llx\n", result);
    return 0;
}
*/
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
