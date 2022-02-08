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
#define BIT 1 //bit
#define BYTE (8 * BIT)
#define HALF_BYTE ( BYTE / 2)
#define BYTE8 (8 * BIT)
#define BYTE4 (4 * BYTE)
#define MAX_INODE (BLOCK_NUMBER_INODE * BLOCK_SIZE /BLOCK_INODE_SIZE)
#define MAX_FILE_INODE (BLOCK_SIZE / BLOCK_INODE_ADDR_SIZE)

/*
   first row 64 bit is block details
   [free][...any]
   [1   ][63    ]
   
   inode
   [status][oid][poid][uid][gid][create at][mod at][name][inodes block address]
   [10    ][64 ][64  ][32 ][32 ][64       ][64    ][640 ][64                 ?]
   name = (192 bit) / (4 char) * (8 bit) =  
   [data]
   [64]
    
   row size = 1024
*/

typedef struct octopus_file_system
{
   int node_block_pos;//wrapper block address
   bit_t status[10];/* d[rwx:all,rwx:group,rwx:user]*/ 
   long oid;// octopus file system id
   long poid;//parrent id
   int uid;// user id created this file
   int gid;// file group id
   time_t create_at;//create file time
   time_t modified_at;//modified file time
   char name[20];//inode name
   int  block_inode_address; // address of block inodes
} oct_FS;

oct_FS* octfs_init(size_t block_pos,int uid,int gid,int oid,
                     size_t poid,char *name,bit_t status[10]);

oct_FS* octfs_init_str(char *data);

size_t octfs_update(oct_FS* ofs,MEM *mem);

#endif