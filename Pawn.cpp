#include <iostream>
#include "Pawn.h"
using namespace std;

Pawn::Pawn(bool col):Piece(col)
{
    hasMoved = false;
}

char Pawn::getSymbol()const
{
    char symbol;
            
    if(getColour())
    	symbol = 'P';
    else
	symbol = 'p';

    return symbol;
}

bool Pawn::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{
    bool tof = false;
        
    if(isVertical(fromX,fromY,toX,toY))
    {
	if(!(b.isOccupied(toX,toY)))
	{
	    if(fromX == MAXROWS - 2 || fromX == 1)
	    {
		if(vertDistance(fromX,toX) <= 2 && !hasMoved)
		{
		    hasMoved = true;
		    tof = true;
		}
	    }
	    else 
	    {
		if(getColour() == isForward(fromX,toX))
		{
		    if(vertDistance(fromX,toX) == 1)
			tof = true;
		}	    
	    }	    
	}
    }
    else if(isDiagonal(fromX,fromY,toX,toY))
    {
	if(vertDistance(fromX,toX) == 1 && horizDistance(fromY,toY) == 1)
	{
	    if(b.isOccupied(toX,toY))
	    {
		tof = true;
	    }
	}
    }
    return tof;
}

PiecePtr Pawn::clone() const
{
    Pawn* p;
    p = new Pawn(getColour());
    p -> hasMoved = this -> hasMoved;
    
    return(static_cast<Pawn*>(p));
}
