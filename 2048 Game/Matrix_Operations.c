//
//  Matrix_Operations.c
//  2048 Game
//
//  Created by MELIKA on 1/17/25.
//

#include "Matrix_Operations.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>


void reset_board(matptr mat){
    for(int i = 0; i <N; i++) {
        for(int j = 0; j<N; j++){
            mat[i][j] = 0;
        }
    }
}
//************************************************************

void copy_board(matptr mat, matptr copy){
    for(int i = 0; i < N; i++) {
        for(int j = 0; j<N; j++){
            copy[i][j] = mat[i][j];
        }
    }
}
//************************************************************

void turn_clockwise(matptr mat, matptr copy){
    for(int i = 0; i < N; i++) {
        for(int j = 0; j<N; j++){
            copy[i][j] = mat[N-1-j][i];
        }
    }
}
//************************************************************

void turn_counter_clockwise(matptr mat, matptr copy){
    for(int i = 0; i < N; i++) {
        for(int j = 0; j<N; j++){
            copy[i][j] = mat[j][N-1-i];
        }
    }
}
//************************************************************

void flip_board(matptr mat, matptr copy){
    for(int i = 0; i < N; i++) {
        for(int j = 0; j<N; j++){
            copy[i][j] = mat[i][N-1-j];
        }
    }
}
//************************************************************

void merge_tiles(matptr mat, matptr copy){
    reset_board(copy);
    for(int i = 0; i < N; i++) {
        for(int j = 0, k = 0; k<N; k++, j++){
            if(mat[i][k] == 0){
                j--;
            }
            else if (k<N-1 && (mat[i][k]==mat[i][k+1])){
                copy[i][j] = mat[i][k] * 2;
                k++;
            }
            else
                copy[i][j] = mat[i][k];
        }
    }
}
//************************************************************

void print_space(int a){
    int copy = a;
    int count = 0;
    
    while (1) {//counting digits
        copy = copy/10;
        count++;
        if(copy==0)
            break;
    }
  
    int space  = (10-count)/2;
    
    printw("%.*s", space, "          ");
    printw("%d", a);
    if(count%2==0) space--; //making sure no extra space is added
    printw("%.*s", space, "          ");
    printw("|");
    
}
//************************************************************

void print_board (matptr mat){
    for(int i = 0; i < N; i++) {
        printw("----------------------------------------\n");
        for(int j = 0; j<N; j++){
            print_space(mat[i][j]);
        }
        printw("\n");
    }
    printw("----------------------------------------\n");
}
//************************************************************

int sum_of_tiles(matptr mat){
    int sum = 0;
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++){
            sum += mat[i][j];
        }
    }
    return sum;
}
//************************************************************

int is_board_different(matptr mat_1, matptr mat_2){
    for(int i = 0; i < N; i++) {
        for(int j = 0; j<N; j++){
            if(mat_1[i][j] != mat_2[i][j])
                return 1;
        }
    }
    return 0;
}
