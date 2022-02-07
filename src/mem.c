#include <stdbool.h>
#include "include/mem.h"
#include <stdlib.h>

int *read_range(MEM *mem,long start,long end)
{
    int size = end - start + 1;
    int *d = malloc((size) * sizeof(int));
    
    //new open file
    fseek(mem,start,SEEK_SET);

    for(long i=0;!feof(mem) && i < size;i++)
    {
        d[i] = fgetc(mem);
    }

    return d;
}

bool write_range(MEM *mem,int *d,long start,long end)
{
    int size = end - start + 1;
    //new open file
    fseek(mem,start,SEEK_SET);

    for(long i = 0;!feof(mem) && i < size;i++)
    {
        fputc(d[i],mem);
    }

    return true;
}