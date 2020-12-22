#include "tommath.h"

#ifndef WIKI_H
#define WIKI_H

/*
 * MP_WUR - warn unused result
 */

struct mp_xorwow_set {
    mp_int x, y, z, w, v, d;
};

struct mp_xoshiro_set {
    mp_int a, b, c, d;
};

mp_err mp_xorshift_32 (int *a, int *b, int *c, mp_int *num) MP_WUR;

mp_err mp_xorshift_64 (int *a, int *b, int *c, mp_int *num) MP_WUR;

mp_err mp_xorwow (struct mp_xorwow_set *params, mp_int *num) MP_WUR;

mp_err mp_xoshiro_rotl (mp_int *x, int k, mp_int *num) MP_WUR;

mp_err mp_xoshiro_256ss (struct mp_xoshiro_set *params, mp_int *num) MP_WUR;

mp_err mp_xoshiro_256p (struct mp_xoshiro_set *params, mp_int *num) MP_WUR;

#endif
