#include "life.h"

int idx(int x, int y, t_game* game)
{
    return y * game->width + x;
}

t_game* init_struct(char** argv)
{  // @param initialize the game
    t_game* game = malloc(sizeof(t_game));
    if (!game)
        exit(1);

    game->width     = atoi(argv[1]);
    game->height    = atoi(argv[2]);
    game->iteration = atoi(argv[3]);
    game->size      = game->width * game->height;
    game->cell      = '\0';
    game->draw      = 0;  // set default to OFF
    game->x         = 0;
    game->y         = 0;

    game->board = calloc(game->size, sizeof(char));
    if (!game->board)
        exit(1);
    return game;
}

void free_game(t_game* game)
{                       // @param free the game
    free(game->board);  // delete the son mem
    free(game);         // delete the father mem
    game = NULL;
}

void print_board(t_game* game)
{
    for (int y = 0; y < game->height; ++y)
    {
        for (int x = 0; x < game->width; ++x)
            write(1, &game->board[idx(x, y, game)], 1);
        write(1, "\n", 1);
    }
}

void init_board(t_game* game)
{
    for (int i = 0; i < game->size; ++i)
        game->board[i] = ' ';
}

void draw_board(t_game* game)
{
    while (read(0, &game->cell, 1) > 0)
    {                           // read until you hit EOF
        if (game->cell == 'x')  // upon hitting x toggel draw
            game->draw = !game->draw;

        if (game->cell == 'w' && game->y > 0)
            --game->y;
        if (game->cell == 's' && game->y < game->height - 1)
            ++game->y;
        if (game->cell == 'a' && game->x > 0)
            --game->x;
        if (game->cell == 'd' && game->x < game->width - 1)
            ++game->x;

        if (game->draw)
            game->board[idx(game->x, game->y, game)] = 'O';
    }
}
