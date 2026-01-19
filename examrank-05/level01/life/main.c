#include "life.h"
#include <string.h>

int live_neighbors(int x, int y, t_game* ptr)
{
    int live_neighbors = 0;
    for (int dy = -1; dy <= 1; ++dy)
    {
        for (int dx = -1; dx <= 1; ++dx)
        {
            if (dx == 0 && dy == 0)  // dont check the current cell
                continue;

            int nx = x + dx;
            int ny = y + dy;

            if ((nx >= 0 && nx < ptr->width) && (ny >= 0 && ny < ptr->height))
            {
                if (ptr->board[idx(nx, ny, ptr)] == 'O')
                    live_neighbors++;
            }
        }
    }

    return live_neighbors;
}

void game_of_life(t_game* g)
{
    char* next_board = calloc(g->size, sizeof(char));
    for (int row = 0; row < g->height; ++row)
    {
        for (int col = 0; col < g->width; ++col)
        {
            int neighbors = live_neighbors(col, row, g);
            int i         = idx(col, row, g);

            switch (neighbors)
            {
                case 2:  // Rule: Stay the same
                    next_board[i] = g->board[i];
                    break;
                case 3:  // Rule: Become/Stay alive
                    next_board[i] = 'O';
                    break;
                default:  // Rule: Die
                    next_board[i] = ' ';
                    break;
            }
        }
    }

    memcpy(g->board, next_board, g->size);
    free(next_board);
}

int main(int argc, char* argv[])
{
    if (argc != 4)
        return 0;

    t_game* g = NULL;

    g = init_struct(argv);
    init_board(g);

    draw_board(g);

    for (int i = 0; i < g->iteration; ++i)
        game_of_life(g);

    print_board(g);

    free_game(g);
    return 0;
}
