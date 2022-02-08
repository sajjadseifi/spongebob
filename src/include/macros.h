#ifndef MACROS_H
#define MACROS_H

#define LEN(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

#endif