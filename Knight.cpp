#include <iostream>
#include "Knight.h"
using namespace std;

Knight::Knight(bool col):Piece(col)
{
}
char Knight::getSymbol()const
{
    char symbol;
            
    if(getColour())
    	symbol = 'N';
    else
	symbol = 'n';

    return symbol;
}

bool Knight::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{
    bool tof = false;

    if(vertDistance(fromX,toX) == 1 && horizDistance(fromY,toY) == 2)
    {
	tof = true;
    }
    else if(vertDistance(fromX,toX) == 2 && horizDistance(fromY,toY) == 1)
    {
	tof = true;
    }

    return tof;
}

PiecePtr Knight::clone() const
{
    PiecePtr p;

    p = new Knight(getColour());

    return p;
}
