#ifndef BOB_MEM_H
#define BOB_MEM_H
#include <stdio.h>
#include <stdbool.h>

typedef FILE MEM;

int *read_range(MEM *mem,long start,long end);

bool write_range(MEM *mem,int *d,long start,long end);

#endif