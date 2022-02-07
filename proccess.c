#include "include/process.h"
#include "include/str.h"
Proc_T* proc_init_stk(size_t uid,size_t pid,size_t ppid,char *cmd,int nice)
{
    time_t time;
    Proc_T* proc = malloc(sizeof(Proc_T));
    proc->uid = uid;
    proc->pid = pid;
    proc->time = time;
    proc->nice = nice;
    proc->state = PROC_INIT;
    proc->cmd = clone(cmd);
    proc->opfs =  init_list(0);
    proc->opdev =  init_list(0);
    
    return proc;    
}

Proc_T* proc_init_dyn(size_t uid,size_t pid,size_t ppid,time_t time,char *cmd,
            int nice,int state,list_T *opfs,list_T *opdev)
{
    Proc_T* proc = malloc(sizeof(Proc_T));
    proc->uid = uid;
    proc->pid = pid;
    proc->time = time;
    proc->nice = nice;
    proc->state = state;
    proc->cmd = clone(cmd);
    proc->opfs =  opfs;
    proc->opdev =  opdev;
    
    return proc;
}