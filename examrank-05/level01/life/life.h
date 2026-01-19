#ifndef life_hpp
#define life_hpp

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

enum status { DEAD, ALIVE };

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

int idx(int x, int y, t_game* game);

t_game* init_struct(char** argv);

void free_game(t_game* g);
void print_board(t_game* g);
void init_board(t_game* g);
void draw_board(t_game* g);

#endif
