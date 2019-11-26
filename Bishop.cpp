#include <iostream>
#include "Bishop.h"
using namespace std;

Bishop::Bishop(bool col):Piece(col)
{
}
char Bishop::getSymbol()const
{
    char symbol;
            
    if(getColour())
    	symbol = 'B';
    else
	symbol = 'b';

    return symbol;
}

bool Bishop::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{
    bool tof = false;
    
    if(isDiagonal(fromX,fromY,toX,toY))
    {
	if(isPathClear(b,fromX,fromY,toX,toY))
	    tof = true;
    }
    else
	tof = false;

    return tof;
}

PiecePtr Bishop::clone() const
{
    PiecePtr p;

    p = new Bishop(getColour());

    return p;
}
