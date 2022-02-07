#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc,char *argv[])
{
    printf("%ld,%ld,%ld",
        sizeof(int),
        sizeof(long),
        sizeof(time_t)
    );
    return 0;
}