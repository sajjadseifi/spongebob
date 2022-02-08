#include "include/macros.h"
#include "include/tpye_t.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

bit_t ctob(char c){
    if(c == '0') return 0;

    return 1;
}

void flushb(bit_t *bins,int offset,int limit,bit_t entry)
{
    int sz = offset + limit;
    for (int i = offset; i < sz; i++)
    {
        bins[i] = entry;
    }
}

void flush(bit_t *bins,int offset,int limit)
{
    flushb(bins,offset,limit,0);   
}

void shift_to_lsb(bit_t *bins,int offset,int limit,
                        int shiftc,bit_t entry)
{
    print_bins(bins,offset,32);
    printf("\nshiftc:%d\n",shiftc);
    if(shiftc == 0)
    {
        return;
    }

    int sz  = offset + limit;
    int end = offset + shiftc;

    for (int i = sz-1; i >= end ; i--)
    {
        bins[i] = bins[i - shiftc];   
    }

    //flush prev item
    flushb(bins,offset,shiftc,entry);
}

void shift_circular(bit_t *bins,int offset,int limit,int rtl)
{

}
void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void reverse(bit_t *bins,int offset,int limit)
{
    int a,b,t;
    for (int i = 0 ; i < limit / 2; i++)
    {
        a = offset + i;
        b = offset + limit - i - 1;
        t = bins[a];
        bins[a] = bins[b];
        bins[b] = t;
    }
}

int charstobin(bit_t *bins,char *str,int offset,int limit)
{
    int bcp = offset;
    int slen = strlen(str);

    flush(bins,offset,limit);
    for (size_t i = 0; i < slen; i++)
    {
        int ascc =(int)str[i]; 
        dtob(bins,ascc,bcp,limit);
        printf("[%d-%d](%d):",bcp,bcp+limit,ascc);
        print_bins(bins,bcp,limit);
        printf("\n");
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
    int index = offset;
    long next = digit;
    for(; index < size ;index++)
    {
        if(next <= 1)
        {
            bins[index] = (bit_t)next;
            break;
        }

        bins[index] = next % 2;
        next = (next - bins[index]) / 2;
    }

    reverse(bins,offset,index+1);

    shift_to_lsb(bins,offset,limit,size - index,0);

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
        bins[sz - i - 1] = ctob(str[i]);
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
    for (int i = offset; i < limit-1 ; i++)
    {
        printf("%d",bins[i]);
    }
}