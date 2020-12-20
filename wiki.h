#include "tommath.h"

#ifndef WIKI_H
#define WIKI_H

/*
 * MP_WUR - warn unused result
 */

mp_err mp_xorshift_32 (int *a, int *b, int *c, mp_int *num) MP_WUR;

mp_err mp_xorshift_64 (int *a, int *b, int *c, mp_int *num) MP_WUR;
/*
mp_err mp_xorw128 () MP_WUR;

mp_err mp_xorwow () MP_WUR;

mp_err mp_xorshiro_256ss () MP_WUR;

mp_err mp_xorshiro_256p () MP_WUR;
*/
#endif
