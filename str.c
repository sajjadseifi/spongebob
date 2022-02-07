#include "include/str.h"
#include "string.h"

char *clone(char *str)
{
    char str2 =(char *) malloc(strlen(str) * sizeof(char) + 1);
    strcpy(str2,str);

    return str2;
}
