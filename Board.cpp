#include <iostream>
#include "Board.h"
#include "Piece.h"
using namespace std;

Board::Board()
{
    initBoard();
}
Board::Board(const Board& other)
{
    copyBoard(other);
}
Board::~Board()
{
    clearBoard();
}

PiecePtr Board::getPiece (int x, int y) const
{
    PiecePtr p = NULL;
            
    if(isOccupied(x,y))
    {
	p = grid[x][y] -> clone();
    }
    
    return p;
}

bool Board::isOccupied (int x, int y) const
{
    bool occupied = false;

    if(grid[x][y] != NULL)
	occupied = true;

    return occupied;
}

bool Board::move(bool colour,int fromX,int fromY, int toX, int toY)
{
    bool tof = false;
    PiecePtr p,q;

    p = grid[fromX][fromY];
    if(p -> canMove(*this,fromX, fromY, toX, toY))
    {
	if(isOccupied(toX,toY))
	{
	    q = grid[toX][toY];
	    	    
	    if(colour != q -> getColour())
	    {
		if(remove(toX,toY))
		{
		    grid[toX][toY] = grid[fromX][fromY];
		    grid[fromX][fromY] = NULL;
		    tof = true;
		}
	    }	    
	}
	else
	{
	    grid[toX][toY] = grid[fromX][fromY];
	    grid[fromX][fromY] = NULL;
	    tof = true;
	}
    }

    return tof;
}

bool Board::place(const PiecePtr& p, int x, int y)
{
    bool tof = false;

    if(!isOccupied(x,y))
    {
	grid[x][y] = p;
	tof = true;
    }

    return tof;
}

bool Board::remove(int x, int y)
{
    bool tof = false;

    if(isOccupied(x,y))
    {
	delete grid[x][y];
	grid[x][y] = NULL;
	tof = true;
    }
    return tof;
}

void Board::write(ostream &out)const
{
    int x = 0;
    int y = 0;
    PiecePtr p;

    out << ' ';
    while(y < MAXCOLS)
    {
	out << "   " << y;
	y++;
    }
    out << endl;
    
    while(x < MAXROWS)
    {
	out << "  ";
	for(int i = 0;i < MAXCOLS;i++)
	{	   
	    out << "+---";
       
	}
	out << '+' << endl;

	out << x;
	for(int j = 0;j < MAXCOLS;j++)
	{
	    if(isOccupied(x,j))
	    {
		p = grid[x][j];
		out << " | " << p -> getSymbol();
	    }
	    else
	    {
		out << " |  ";
	
	    }
	}
	out << " |" << endl;
	x++;
    
    }
    out << "  ";
    for(int i = 0;i < MAXROWS;i++)
    {	   
	out << "+---";
	
	if(i == MAXROWS - 1)
	{
	    out << '+';
	}
    }
    out << endl;
    
}

Board& Board::operator= (const Board& other)
{
    if(this != &other)
    {
	clearBoard();
	copyBoard(other);
    }
    
    return(*this); 
}

void Board::initBoard()
{
    int x;
    int y;
    
    for(x = 0;x < MAXROWS;x++)
    {
	for(y = 0;y < MAXCOLS;y++)
	{
	    grid[x][y] = NULL;
	}
    }
}
void Board::clearBoard()
{
    int x;
    int y;
   
    for(x = 0;x < MAXROWS;x++)
    {
	for(y = 0;y < MAXCOLS;y++)
	{
	    if(isOccupied(x,y))
	    {
		delete grid[x][y];
		grid[x][y] = NULL;
	    }	
	}	
    } 
}

void Board::copyBoard(const Board& other)
{
    int x;
    int y;
    
    for(x = 0;x < MAXROWS;x++)
    {
	for(y = 0;y < MAXCOLS;y++)
	{
	    if(other.grid[x][y] != NULL)
	    {
		grid[x][y] = other.grid[x][y] -> clone();
	    }
	} 
    }    
}

ostream& operator<< (ostream& out, const Board& b)
{
    b.write(out);
    
    return out;
}

