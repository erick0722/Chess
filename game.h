#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "ioutil.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"

using namespace std;

const char enterX[25] = "Enter a X coordinate: ",
    enterY[25] = "Enter a Y coordinate: ",
    confirmQuit[25] = "Do you want to quit?: ";

void initGame(Board &b);
bool detectKing(Board &b);
#endif
