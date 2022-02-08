#ifndef BOB_MEM_H
#define BOB_MEM_H
#include <stdio.h>
#include <stdbool.h>
#include "tpye_t.h"

typedef FILE MEM;

bit_t *read_range(MEM *mem,long offset,long limit);

bool write_range(MEM *mem,bit_t *d,long off_b,long lim_b,long off_m,long lim_m);

void flush_range(MEM *mem,long offset,long limit);

#endif