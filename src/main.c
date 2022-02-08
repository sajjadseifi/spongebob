#include "include/conv.h"
#include "include/macros.h"
#include <stdlib.h>
#include <string.h>
void test()
{
    long data;
    btod(&data,bchtob("00000010",8),0,8);
    print_bins(bchtob("00000010",8),0,8);
    
}
int main(int argc,char *argv[])
{  
    test();  
    return 0;
}