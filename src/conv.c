#include "include/macros.h"
#include "include/tpye_t.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int charstobin(bit_t *bins,char *str,int offset,int limit)
{
    int bcp = offset;
    int slen = strlen(str);
    for (size_t i = 0; i < slen; i++)
    {
        dtob(bins,(int)str[i],bcp,limit);
        bcp += limit;
    }
    return offset + limit;
}

int bintochars(char *buf,int buf_sz,bit_t *bins,int offset,int limit)
{
    int bcp = 0;
    buf = malloc(buf_sz * sizeof(char));

    for (int i = 0; i < buf_sz; i++)
    {
        btod(&buf[i],bins,bcp,limit); 
        bcp += limit;
    }

    return offset + bcp;
}

int dtob(bit_t *bins,long digit,int offset,int limit)
{
    int size = offset + limit;
    int i = offset;
    long next = digit;

    for(; i < size ;i++)
    {
        if(next == 0)
        {
            bins[size - i - 1] = (bit_t)next;
            break;
        }
        else
        {
            bins[size - i - 1] = 0;
            next = ( next % 2 ) / 2;
        }
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
    return size;   
}


int btod(long *data,bit_t *bins,int offset,int limit)
{
    *data=0;
    for (int i = 0; i < limit; i++)
    {
        if(bins[offset + i] == 1){
            *data += (long)pow(2,i);
        }
    }
    
    return offset + limit;
}

bit_t *bchtob(char *str,int sz)
{
    bit_t *bins = malloc(sz * sizeof(bit_t));
    
    for (int i = 0; i < sz; i++)
    {
        bins[sz - i - 1] = atoi((char[]){str[i]});
    }

    return bins;
}

int btob(bit_t *b1,bit_t *b2,int offset,int limit)
{
    for (int i = offset; i < limit; i++)
    {
        b1[i] = b2[i];
    }

    return offset + limit;
}

void print_bins(bit_t *bins,int offset,int limit)
{
    for (int i = limit-1 ; i >= offset; i--)
    {
        printf("%d",bins[i]);
    }
}