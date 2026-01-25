#include "life.h"
#include <stdlib.h>
#include <unistd.h>

void free_struct(t_life* life)
{
    free(life->board);
    free(life);
}

int idx(int x, int y, t_life* life)
{
    return y * life->width + x;
}

t_life* init_struct(char** argv)
{
    t_life* life = malloc(sizeof(t_life));
    if (!life)
        exit(0);

    life->width     = atoi(argv[1]);
    life->height    = atoi(argv[2]);
    life->iteration = atoi(argv[3]);

    if (life->width <= 0 && life->height <= 0 && life->iteration < 0)
    {
        free(life);
        exit(0);
    }

    life->size  = life->width * life->height;
    life->board = calloc(life->size, sizeof(char));
    if (!life->board)
    {
        free(life);
        exit(0);
    }

    return life;
}

void init_board(t_life* life)
{
    for (int i = 0; i < life->size; ++i)
        life->board[i] = ' ';

    char cell = '\0';
    int  draw = 0;
    int  x    = 0;
    int  y    = 0;

    while (read(0, &cell, 1) > 0)
    {
        switch (cell)
        {
            case 'x':
                draw = !draw;
                break;
            case 'w':
                if (y > 0)
                    --y;
                break;
            case 'a':
                if (x > 0)
                    --x;
                break;
            case 's':
                if (y < life->height - 1)
                    ++y;
                break;
            case 'd':
                if (x < life->width - 1)
                    ++x;
                break;
        }

        if (draw)
            life->board[idx(x, y, life)] = 'O';
    }
}

void print_board(t_life* life)
{
    for (int y = 0; y < life->height; ++y)
    {
        for (int x = 0; x < life->width; ++x)
            write(1, &life->board[idx(x, y, life)], 1);
        write(1, "\n", 1);
    }
}

int find_live_neighbors(int x, int y, t_life* life)
{
    int live_neighbors = 0;
    for (int dy = -1; dy <= 1; ++dy)
    {
        for (int dx = -1; dx <= 1; ++dx)
        {
            if (dx == 0 && dy == 0)
                continue;

            int nx = dx + x;
            int ny = dy + y;

            if ((nx >= 0 && nx < life->width) && (ny >= 0 && ny < life->height))
                if (life->board[idx(nx, ny, life)] == 'O')
                    live_neighbors++;
        }
    }

    return live_neighbors;
}

void game_of_life(t_life* life)
{
    char* temp_board = calloc(life->size, sizeof(char));
    for (int y = 0; y < life->height; ++y)
    {
        for (int x = 0; x < life->width; ++x)
        {
            int neighbors = find_live_neighbors(x, y, life);
            int i         = idx(x, y, life);

            switch (neighbors)
            {
                case 2:
                    temp_board[i] = life->board[i];
                    break;
                case 3:
                    temp_board[i] = 'O';
                    break;
                default:
                    temp_board[i] = ' ';
                    break;
            }
        }
    }

    memcpy(life->board, temp_board, life->size);
    free(temp_board);
}

int main(int argc, char* argv[])
{
    if (argc != 4)
        return 0;

    t_life* life = NULL;

    life = init_struct(argv);
    init_board(life);

    for (int i = 0; i < life->iteration; ++i)
        game_of_life(life);

    print_board(life);
    free_struct(life);
}
