#ifndef life_h
#define life_h

#include <string.h>
#include <stdlib.h>

typedef struct s_life {
    int   width;
    int   height;
    int   iteration;
    int   size;
    char* board;
} t_life;

#endif
