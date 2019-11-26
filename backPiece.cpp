#include "Piece.h"
using namespace std;

Piece::Piece(bool col)
{
    colour = col;
}
Piece::~Piece()
{
}

char Piece::getSymbol() const
{
    return 'A';
}

bool Piece::getColour() const
{
      return colour;
}

bool Piece::canMove(const Board& b, int fromX, int fromY, 
		    int toX, int toY)
{
    return false;
}

PiecePtr Piece::clone()const
{
    PiecePtr p = NULL;
    
    return p;
}

bool Piece::isPathClear (const Board& b, int fromX, int fromY,
			 int toX, int toY)const
{
    bool clear = true;
    PiecePtr p;
    if(isVertical(fromX,fromY,toX,toY))
    {
	if(isForward(fromX,toX))
	{
	    while(fromX != toX + 1 && clear)
	    {
		fromX--;
		p = b.getPiece(fromX,fromY);
		if(p != NULL)
		{
		    clear = false;
		    delete p;
		}
	    }
	}
	else
	{
	    while(fromX < toX - 1 && clear)
	    {
		fromX++;
		p = b.getPiece(fromX,fromY);
		if(p != NULL)
		{
		    clear = false;
		    delete p;
		}
	    }
	}
    }
    else if(isHorizontal(fromX,fromY,toX,toY))
    {
	if(fromY < toY)
	{
	    while(clear && fromY < toY - 1)
	    {
		fromY++;
		p = b.getPiece(fromX,fromY);
		if(p != NULL)
		{
		    clear = false;
		    delete p;
		}
	    }
	}
	else
	{
	    while(clear && fromY != toY + 1)
	    {
		fromY--;
		p = b.getPiece(fromX,fromY);
		if(p != NULL)
		{
		    clear = false;
		    delete p;
		}
	    }	
	}
    }
    else if(isDiagonal(fromX,fromY,toX,toY))
    {
	if(fromX > toX && fromY > toY)
	{
	    while(fromY != toY + 1 && fromX != toX + 1 && clear)
	    {
		 fromX--;
		 fromY--;
		 p = b.getPiece(fromX,fromY);
		 if(p != NULL)
		 {
		     clear = false;
		     delete p;
		 }
	    }
	}
	else if(fromX < toX && fromY < toY)
	{
	    while(fromY < toY - 1 && fromX < toX - 1 && clear)
	    {
		fromX++;
		fromY++;
		p = b.getPiece(fromX,fromY);
		if(p != NULL)
		{
		    clear = false;
		    delete p;
		}
	    }
	}
	else if(fromX < toX && fromY > toY)
	{
	    while(fromY != toY + 1 && fromX < toX - 1 && clear)
	    {
		fromX++;
		fromY--;
		p = b.getPiece(fromX,fromY);
		if(p != NULL)
		{
		    clear = false;
		    delete p;
		}
	    }
	}
	else
	{
	    while(fromY < toY - 1 && fromX != toX + 1 && clear)
	    {
		fromX--;
		fromY++;
		p = b.getPiece(fromX,fromY);
		if(p != NULL)
		{
		    clear = false;
		    delete p;
		}
	    }
	}
    }
    return clear;
}

bool Piece::isVertical (int fromX, int fromY, int toX, int toY) const
{
    bool tof = false;
    
    if(fromY == toY)
    {
	if(fromX != toX)
	    tof = true;
    }
  
    return tof;
}

bool Piece::isHorizontal (int fromX, int fromY, int toX, int toY) const
{
    bool tof = false;
    
    if(fromX == toX)
    {
	if(fromY != toY)
	    tof = true;
    }
        
    return tof;
}

bool Piece::isDiagonal (int fromX, int fromY, int toX, int toY) const
{
    bool tof = false;

    if(vertDistance(fromX,toX) == horizDistance(fromY,toY))
	tof = true;

    return tof;
}

bool Piece::isForward (int fromX, int toX) const
{
    bool forward = false;
    
    if(fromX > toX)
	forward = true;
    
    return forward;
}

int Piece::vertDistance (int fromX, int toX) const
{
    double vDistance;
        
    vDistance = toX - fromX;
    
    return static_cast<int>(abs(vDistance));
}

int Piece::horizDistance (int fromY, int toY) const
{
    double hDistance;
    
    hDistance = toY - fromY;
    
    return static_cast<int>(abs(hDistance));
}


