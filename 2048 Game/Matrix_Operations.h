//
//  Matrix_Operations.h
//  2048 Game
//
//  Created by MELIKA on 1/17/25.
//

#ifndef Matrix_Operations_h
#define Matrix_Operations_h

#include <stdio.h>

#define N 4
typedef  int(*matptr)[N] ;
void turn_clockwise(matptr mat, matptr copy);
void turn_counter_clockwise(matptr mat, matptr copy);
void flip_board(matptr mat, matptr copy);
void merge_tiles(matptr mat, matptr copy);
void print_board (matptr mat);
void copy_board(matptr mat, matptr copy);
void reset_board(matptr mat);
int sum_of_tiles(matptr mat);
int is_board_different(matptr mat_1, matptr mat_2);
void print_space(int a);


#endif /* Matrix_Operations_h */
