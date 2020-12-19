#include "tommath.h"

#ifndef WIKI_H
#define WIKI_H

/*
 * MP_WUR - warn unused result
 */

mp_err mp_xorshift_32 (int *a, int *b, int *c, mp_int *num) MP_WUR;

mp_err mp_xorshift_64 (int *a, int *b, int *c, mp_int *num) MP_WUR;

#endif
