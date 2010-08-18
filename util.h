#ifndef util_h_INCLUDED
#define util_h_INCLUDED

#include <stdio.h>
#define FAIL(...) {                             \
    fprintf(stderr, __VA_ARGS__);               \
    exit(1);                                    \
  }  

#endif
