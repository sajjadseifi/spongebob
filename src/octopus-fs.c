#include <string.h>
#include "include/octopus-fs.h"
#include "include/bob-time.h"
#include "include/conv.h"

oct_FS* octfs_init(long block,long offset,int uid,int gid,long oid,
                     long poid,char *name,bit_t status[STATUS_SIZE])
{
    time_t cur =  time_cur();
    oct_FS *ofs = malloc(sizeof(oct_FS));
    btob(ofs->status,status,0,10);
    ofs->block = block;
    ofs->offset = offset;
    ofs->oid = oid;
    ofs->poid = poid;
    ofs->uid = uid;
    ofs->gid = gid;
    ofs->create_at = cur;
    ofs->modified_at = cur;

    return ofs;
}

oct_FS* octfs_init_str(char *data)
{
    int end = 0;
    bit_t *bins = bchtob(data,BLOCK_INODE_SIZE);
    oct_FS *ofs = malloc(sizeof(oct_FS));
    end = btob(ofs->status,bins,end,STATUS_SIZE);
    end = btod(&ofs->oid,bins,end,BYTE8);
    end = btod(&ofs->poid,bins,end,BYTE8);
    end = btod(&ofs->uid,bins,end,BYTE4);
    end = btod(&ofs->gid,bins,end,BYTE4);
    end = btod(&ofs->create_at,bins,end,BYTE8);
    end = btod(&ofs->modified_at,bins,end,BYTE8);
    int bf_zs = 20;
    end = bintochars(ofs->name,bf_zs,bins,end,BYTE4 * bf_zs);
    end = btod(&ofs->block_inode_address,bins,end,BYTE8);

    return ofs;
}

size_t octfs_update(oct_FS* ofs,MEM *mem)
{
    int end = 0;
    bit_t *bins = malloc(BLOCK_INODE_SIZE * sizeof(bit_t));
    end = btob(bins,ofs->status,end,STATUS_SIZE);
    end = dtob(bins,ofs->oid,end,BYTE8);
    
    end = dtob(bins,ofs->poid,end,BYTE8);
    end = dtob(bins,ofs->uid,end,BYTE4);
    end = dtob(bins,ofs->gid,end,BYTE4);
    end = dtob(bins,ofs->create_at,end,BYTE8);
    end = dtob(bins,ofs->modified_at,end,BYTE8);
    end = charstobin(bins,ofs->name,end,BYTE4 * NAME_COUNT);
    end = dtob(bins,ofs->block_inode_address,end,BYTE8);
    long phy_addr = (ofs->block * BLOCK_SIZE) + ofs->offset;

    write_range(mem,bins,0,BLOCK_INODE_SIZE,
                  phy_addr,BLOCK_INODE_SIZE);
    
    return end;
}

