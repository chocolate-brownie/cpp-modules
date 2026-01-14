#include "life.h"

t_game* game = NULL;

int get_live_cells(int x, int y)
{
    return 1;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
        return 0;

    init_game(argv);
    init_board();

    draw_board();
    print_board();
    free_game();
    return 0;
}
