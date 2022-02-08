#ifndef FILE_SYS_H
#define FILE_SYS_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "list.h"
#include "mem.h"
#include "tpye_t.h"
#define BLOCK_SIZE 65568 // 2 ^ 16
#define BLOCK_NUMBER_INODE 128 // 2 ^ 7
#define BLOCK_INODE_SIZE 1024 // 2 ^ 10
#define BLOCK_INODE_ADDR_SIZE 16 // 2 ^ 4
#define MAX_INODE (BLOCK_NUMBER_INODE * BLOCK_SIZE /BLOCK_INODE_SIZE)
#define MAX_FILE_INODE (BLOCK_SIZE / BLOCK_INODE_ADDR_SIZE)
#define STATUS_SIZE 10
#define NAME_COUNT 19
/*
   first row 64 bit is block details
   [free][...any]
   [1   ][63    ]
   
   inode
   [free][status][oid][poid][uid][gid][create at][mod at][name][inodes block address]
   [22  ][10    ][64 ][64  ][32 ][32 ][64       ][64    ][608 ][64                 ?]
   name = (192 bit) / (4 char) * (8 bit) =  
   [data]
   [64]
    
   row size = 1024
*/

typedef struct octopus_file_system
{
   long block;//wrapper block address
   long offset;//offset in block
   bit_t status[STATUS_SIZE];/* d[rwx:all,rwx:group,rwx:user]*/ 
   long oid;// octopus file system id
   long poid;//parrent id
   int uid;// user id created this file
   int gid;// file group id
   time_t create_at;//create file time
   time_t modified_at;//modified file time
   char name[NAME_COUNT];//inode name
   int  block_inode_address; // address of block inodes
} oct_FS;

oct_FS* octfs_init(long block,long offset,int uid,int gid,long oid,
                     long poid,char *name,bit_t status[10]);

oct_FS* octfs_init_str(char *data);

size_t octfs_update(oct_FS* ofs,MEM *mem);

#endif