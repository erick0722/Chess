#include <iostream>
#include "Rook.h"
using namespace std;

Rook::Rook(bool col):Piece(col)
{
}
char Rook::getSymbol()const
{
    char symbol;
            
    if(getColour())
    	symbol = 'R';
    else
	symbol = 'r';

    return symbol;
}

bool Rook::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{
    bool tof = false;
    
    if(isVertical(fromX,fromY,toX,toY) || isHorizontal(fromX,fromY,toX,toY))
    {
	if(isPathClear(b,fromX,fromY,toX,toY))
	{
	    tof = true;
	}

    }
    return tof;
}

PiecePtr Rook::clone() const
{
    PiecePtr p;

    p = new Rook(getColour());

    return p;
}
