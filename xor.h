#ifndef XOR_H
#define XOR_H

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include "const.h"

uint32_t Xorshift_32 (int a, int b, int c)
{
     uint32_t y= MY_SEED_32;
     printf("\n SEED:\t %" PRIu32, y);
     y^=(y<<a);
     y^=(y>>b);
     y^=(y<<c);
     return y;
};

uint64_t Xorshift_64 (int a, int b, int c)
{
     uint64_t y= MY_SEED_64;
     printf("\n SEED:\t %" PRIu64, y);
     y^=(y<<a);
     y^=(y>>b);
     y^=(y<<c);
     return y;
};

struct xorwow_set{
    uint32_t x, y, z, w, v, d;
};

uint32_t XorWow_32(struct xorwow_set *params)
{

    uint32_t t=(params->x^(params->x>>2));

    params->x = params->y;
    params->y = params->z;
    params->z = params->w;
    params->w = params->v;
    params->v = (params->v^(params->v<<4))^(t^(t<<1));

    return (params->d+=362437)+params->v;
};

// Дополнительно определена функция rotate
static inline uint64_t rotl(const uint64_t x, int k) {
    return (x << k) | (x >> (64 - k));
};

struct xoshiro_set{
    uint64_t s1, s2, s3, s0;
};

uint64_t xoshiro_256p(struct xoshiro_set *params) {
    const uint64_t result = rotl(params->s0 + params->s3, 23) + params->s0;

    const uint64_t t = params->s1 << 17;

    params->s2 ^= params->s0;
    params->s3 ^= params->s1;
    params->s1 ^= params->s2;
    params->s0 ^= params->s3;
    params->s2 ^= t;

    params->s3 = rotl(params->s3, 45);

    return result;
}

uint64_t xoshiro_256ss(struct xoshiro_set *params) {
    const uint64_t result = rotl(params->s1 * 5, 7) * 9;

    const uint64_t t = params->s1 << 17;

    params->s2 ^= params->s0;
    params->s3 ^= params->s1;
    params->s1 ^= params->s2;
    params->s0 ^= params->s3;
    params->s2 ^= t;

    params->s3 = rotl(params->s3, 45);

    return result;
}
#endif // XOR_H
