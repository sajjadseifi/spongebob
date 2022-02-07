#ifndef PROCCESS_H
#define PROCCESS_H
#include <stdlib.h>
#include "list.h"

typedef struct PROCCESS_STRUCT
{
    size_t uid;
    size_t pid;
    size_t ppid;
    time_t time;
    char *cmd;
    int nice;
    enum
    {
        PROC_INIT,
        PROC_READY,
        PROC_RUNNIGN,
        PROC_WAITING,
        PROC_TERMINATED
    } state;
    list_T* opfs;
    list_T* opdev;
} Proc_T;


#endif