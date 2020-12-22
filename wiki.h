#include "tommath.h"

#ifndef WIKI_H
#define WIKI_H

/*
 * MP_WUR - warn unused result
 */

struct mp_xorwow_set {
    mp_int x, y, z, w, v, d;
};

mp_err mp_xorshift_32 (int *a, int *b, int *c, mp_int *num) MP_WUR;

mp_err mp_xorshift_64 (int *a, int *b, int *c, mp_int *num) MP_WUR;

mp_err mp_xorwow (struct mp_xorwow_set *params, mp_int *num) MP_WUR;

//mp_err mp_xorshiro_256ss () MP_WUR;

//mp_err mp_xorshiro_256p () MP_WUR;

#endif
