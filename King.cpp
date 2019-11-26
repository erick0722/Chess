#include <iostream>
#include "King.h"
using namespace std;

King::King(bool col):Piece(col)
{
}
char King::getSymbol()const
{
    char symbol;
            
    if(getColour())
    	symbol = 'K';
    else
	symbol = 'k';

    return symbol;
}

bool King::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{
    bool tof = false;
    
    if(isVertical(fromX,fromY,toX,toY))
    {
	if(vertDistance(fromX,toX) == 1)
	{
	    tof = true;
	}
    }
    else if(isHorizontal(fromX,fromY,toX,toY))
    {
	if(horizDistance(fromY,toY) == 1)
	{
	    tof = true;
	}
    }
    else if(isDiagonal(fromX,fromY,toX,toY))
    {
	if(horizDistance(fromY,toY) == 1 && vertDistance(fromX,toX) == 1)
	{
	    tof = true;
	}
    }
    
    return tof;
}

PiecePtr King::clone() const
{
    PiecePtr p;

    p = new King(getColour());

    return p;
}
