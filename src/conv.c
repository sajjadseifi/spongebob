#include "include/conv.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LEN(a) (sizeof(a) / sizeof(a[0]))

short *charstobin(char *str,int base)
{
    int slen = strlen(str);
    short *bins = malloc(slen * base * sizeof(int));
    int bcp = 0;
    
    for (size_t i = 0; i < slen; i++)
    {
        dtob(bins,(int)str[i],bcp,base);
        bcp += base;
    }
}

char *bintochars(short *bins,int base)
{
    int size = ceil((float)LEN(bins) / (float)base) ;
    char *str = malloc(size * sizeof(char));

    int bcp = 0;

    for (int i = 0; i < size; i++)
    {
        str[i] = btod(bins,bcp,base); 
        bcp += base;
    }

    return str;
}

void dtob(short *bins,int digit,int offset,int limit)
{
    int next = digit;
    int size = offset + limit;
    int i = offset;

    for(; i < size ;i++)
    {
        if(next < 2)
        {
            bins[size - i - 1] = next;
            break;
        }
        
        bins[size - i - 1] = 0;

        next = ( next % 2 ) / 2;
    }

    int shift_c = size - i;
  
    if(shift_c > 0)
    {
        //shift end to start
        for (int i = 0; i < size; i++)
        {
            bins[i] = bins[i + shift_c]; 
        }
        //flush end shift count 
        for (int i = 0; i < shift_c; i++)
        {
            bins[size - i - 1] = 0;
        }
    }
    
}

long btod(short *bins,int offset,int limit)
{
    long data = 0;
    int len = LEN(bins);
    if(offset + limit > len) 
    {
        printf("out of bounds...\n");
        return NULL;
    }

    for (int i = 0; i < limit; i++)
    {
        if(bins[offset + i] == 1)
            data += (int)pow(2,i);
    }
    
    return data;
}

