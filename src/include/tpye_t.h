#ifndef TYPET_H
#define TYPET_H
#include <stdbool.h>
#define NOT 0
#define BIT 1 
#define NOTC '0'
#define BITC '1' 
#define BYTE (8 * BIT)
#define HALF_BYTE ( BYTE / 2)
#define BYTE8 (8 * BYTE)
#define BYTE4 (4 * BYTE)

typedef bool bit_t;

#endif