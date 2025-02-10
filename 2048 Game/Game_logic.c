//
//  Game_logic.c
//  2048 Game
//
//  Created by MELIKA on 1/17/25.
//

#include "Game_logic.h"
#include "Matrix_Operations.h"
#include <stdlib.h>
#include <time.h>



void move_left(matptr mat, matptr copy){
    merge_tiles(mat, copy);
    copy_board(copy, mat);
}
//************************************************************

void move_right(matptr mat, matptr copy){
    flip_board(mat, copy);
    copy_board(copy, mat);
    merge_tiles(mat, copy);
    flip_board(copy, mat);
}
//************************************************************

void move_up(matptr mat, matptr copy){
    turn_counter_clockwise(mat, copy);
    copy_board(copy, mat);
    merge_tiles(mat, copy);
    turn_clockwise(copy, mat);
}
//************************************************************

void move_down(matptr mat, matptr copy){
    turn_clockwise(mat, copy);
    copy_board(copy, mat);
    merge_tiles(mat, copy);
    turn_counter_clockwise(copy, mat);
}
//************************************************************

void add_tile(matptr mat){
    int i, j,k, count=0;
    int indexes[16][2];
    for (i=0; i<16; i++){
        for(j=0; j<2; j++){
            indexes[i][j] = -1;
        }
    }
    //find the indexes where value is 0
    for (i=0; i<n; i++) {
        for(j=0; j<n; j++){
            if(mat[i][j]==0){
                indexes[count][0] = i;
                indexes[count][1] = j;
                //printf("(%d, %d)" , indexes[count][0],indexes[count][1] );
                count++;
            }
        }
    }
    //printf("\nCount: %d\n", count);
    if(count>0){
        k = rand()%count;
       // printf("\nk: %d\n", k);
        i = indexes[k][0];
        j = indexes[k][1];
        printf("(i, j ) = (%d, %d)\n" , indexes[k][0], j);
        mat[i][j] = (rand()%100 > 10) ? 2: 4;
    }
    else{
       printf("Error! Attempting to add a tile where there arent any empty tiles!\n");
    }
}
