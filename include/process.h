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

/**
 * @brief 
 * this function init strickt becuse time & state & opfs & opdev
 * inited this entry of function  
 * @param uid  user id created this proccess
 * @param ppid proccess parent id create  this proccess
 * @param cmd  command runer tihs proccess proc
 * @return * Proc_T* 
 */
Proc_T* proc_init_stk(size_t uid,size_t pid,size_t ppid,char *cmd,int nice);

/**
 * @brief 
 * 
 * @param uid user id created this proccess
 * @param pid proccess id
 * @param ppid proccess parent id create  this proccess
 * @param time time of start proccess
 * @param cmd command runer tihs proccess proc
 * @param nice nice ness peoccess 
 * @param state type of state proccess 
 * @return * Proc_T* 
 */
Proc_T* proc_init_dyn(size_t uid,size_t pid,size_t ppid,time_t time,char *cmd,int nice,int state);

#endif