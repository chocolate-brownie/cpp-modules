#ifndef life_hpp
#define life_hpp

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_game {
    int width;
    int height;
    int iteration;

    int   size;
    int   draw;
    int   x;
    int   y;
    char* board;
    char  cell;

} t_game;

extern t_game* game;

void init_game(char** argv);
int  idx(int x, int y);
void free_game(void);
void print_board(void);
void init_board(void);
void draw_board(void);

#endif
