//
//  Game_logic.h
//  2048 Game
//
//  Created by MELIKA on 1/17/25.
//

#ifndef Game_logic_h
#define Game_logic_h
#include "Matrix_Operations.h"
#include <stdio.h>
void move_left(matptr mat, matptr copy);
void move_right(matptr mat, matptr copy);
void move_up(matptr mat, matptr copy);
void move_down(matptr mat, matptr copy);
void add_tile(matptr mat);
#endif /* Game_logic_h */
