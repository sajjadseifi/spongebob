#include "include/bob-time.h"
#include <time.h>

time_t time_cur()
{
  time_t t;
  time ( &t );

  return t;
}
