#include <iostream>
#include "Queen.h"
using namespace std;

Queen::Queen(bool col):Piece(col)
{
}
char Queen::getSymbol()const
{
    char symbol;
            
    if(getColour())
    	symbol = 'Q';
    else
	symbol = 'q';

    return symbol;
}

bool Queen::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{
    bool tof = false;
    
    if(isVertical(fromX,fromY,toX,toY) || isHorizontal(fromX,fromY,toX,toY) || isDiagonal(fromX,fromY,toX,toY))
    {
	if(isPathClear(b,fromX,fromY,toX,toY))
	{
	    tof = true;
	}
    }

    return tof;
}

PiecePtr Queen::clone() const
{
    PiecePtr p;

    p = new Queen(getColour());

    return p;
}
