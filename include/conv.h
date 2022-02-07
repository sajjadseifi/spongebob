#ifndef BOB_CONVERTOR_H
#define BOB_CONVERTOR_H
#include <stdio.h>
#include <stdbool.h>

short *charstobin(char *str,int base);

char *bintochars(short *bins,int base);

void dtob(short *bins,int digit,int offset,int limit);

long btod(short *bins,int offset,int limit);

#endif