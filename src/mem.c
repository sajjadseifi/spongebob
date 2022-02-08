#include <stdbool.h>
#include <stdlib.h>
#include "include/mem.h"
#include "include/macros.h"

bit_t *read_range(MEM *mem,long offset,long limit)
{
    bit_t *d = malloc((limit) * sizeof(bit_t));    
    //new open file
    fseek(mem,offset,SEEK_SET);

    for(long i=0;!feof(mem) && i < limit;i++)
    {
        d[i] = atoi(fgetc(mem));
    }

    return d;
}

bool write_range(MEM *mem,bit_t *d,long off_b,long lim_b,long off_m,long lim_m)
{
    //new open file
    fseek(mem,off_m,SEEK_SET);

    int sz = MIN(lim_b - off_b, lim_m);

    for(long i = off_b;i < sz;i++)
    {
        printf("%d",d[i]);
        fputc(d[i]+'0',mem);
    }

    return true;
}

void flush_range(MEM *mem,long offset,long limit)
{
    //new open file
    fseek(mem,offset,SEEK_SET);
    for (size_t i = 0; i < limit; i++)
    {
        fputc(NOTC,mem);
    }
}