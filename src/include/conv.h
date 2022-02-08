#ifndef BOB_CONVERTOR_H
#define BOB_CONVERTOR_H
#include <stdio.h>
#include <stdbool.h>
#include "tpye_t.h"
/**
 * @brief 
 * convert chars string to binary array of bit 
 * @param bins 
 * @param str 
 * @param offset 
 * @param limit 
 * @return * int 
 */
int charstobin(bit_t *bins,char *str,int offset,int limit);
/**
 * @brief 
 * convert binary array of bit to string chars
 * @param buf 
 * @param buf_sz 
 * @param bins 
 * @param offset 
 * @param limit 
 * @return int 
 */
int bintochars(char *buf,int buf_sz,bit_t *bins,int offset,int limit);
/**
 * @brief 
 * convert digit numeric value to binary code of bit array
 * @param bins 
 * @param digit 
 * @param offset 
 * @param limit 
 * @return int 
 */
int dtob(bit_t *bins,long digit,int offset,int limit);
/**
 * @brief 
 * convert binary array of bit to digit number
 * @param data 
 * @param bins 
 * @param offset 
 * @param limit 
 * @return int 
 */
int btod(long *data,bit_t *bins,int offset,int limit);
/**
 * @brief 
 * maped array of binary character(0|1) to binary bit array
 * @param str 
 * @param sz 
 * @return bit_t* 
 */
bit_t *bchtob(char *str,int sz);

/**
 * @brief 
 * maped binary array arg 2 to binary array 1
 * with limit size at start offset 
 * @param b1 
 * @param b2 
 * @param offset 
 * @param limit 
 * @return int 
 */
int btob(bit_t *b1,bit_t *b2,int offset,int limit);

/**
 * @brief 
 * print array of bins
 * @param bins 
 * @return * void 
 */
void print_bins(bit_t *bins,int offset,int limit);

#endif