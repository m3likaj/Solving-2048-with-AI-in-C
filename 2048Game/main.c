//
//  main.c
//  2048 Game
//
//  Created by MELIKA on 1/17/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "matrix_operations.h"
#include "game_logic.h"
#include "neural_network.h"
int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int matrix[N][N] = {0};
    matptr copy = (matptr) calloc(N * N, sizeof(int));
    matptr copy2 = (matptr) calloc(N * N, sizeof(int));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    printw("Press arrow keys (ESC to quit):\n");
    int ch;
    add_tile(matrix);
    add_tile(matrix);
    print_board(matrix);
    while ((ch = getch()) != 27) { // ESC to quit
        clear();
        copy_board(matrix, copy2);
        switch (ch) {
            case KEY_UP:
                move_up(matrix, copy);
                break;
            case KEY_DOWN:
                move_down(matrix, copy);
                break;
            case KEY_LEFT:
                move_left(matrix, copy);
                break;
            case KEY_RIGHT:
                move_right(matrix, copy);
                break;
            default: printw("Unknown key\n"); break;
        }
        if(is_board_different(matrix, copy2)){
            add_tile(matrix);
        }
        
        print_board(matrix);
        
        
        refresh();
    }

    endwin();
    return 0;
}
