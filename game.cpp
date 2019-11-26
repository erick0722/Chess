
/*
 =======================================================================
  Name:        Erick Yip
  Email:       eyip256@mtroyal.ca
  Course:      comp1633-001
  Instructor:  Paul Pospisil
  Assignment:  5
  Source file: game.cpp
  Due date:    April 9,2018 11:59pm
 =======================================================================
  Purpose:     This program is a two-player chess program that will allow
               the user(s) to take turns moving the pieces like on a 
	       normal chess board.
  
  Details:     When the program starts, it will guide the user through
               many checks until they have selected a valid piece that
               can be moved, then the program will run through another
	       series of checks until the user have made a valid move.
	       The game will continue until one of the king is captured
	       or if the coordinates is (-1,-1).

  Assumptions: The user have some knowledge about chess and how each
               pieces can move. And all coordinate has to be positive
	       integers, or -1,-1 if they wish to quit.

  Known Bugs:  The confirmation of quitting after the user entered -1,-1
               only shows up for the first coordinate they entered.
	       Which means that the program will only ask the user for
	       confirmation and everywhere else it will just stop
	       without asking.
	       I also did not test the copyBoard function because I
	       didn't know how to...
 =======================================================================
 */

#include <iostream>
#include "game.h"
using namespace std;

int main()
{
    Board b;
    int fromX;
    int fromY;
    int toX;
    int toY;
    PiecePtr piece = NULL;
    bool moved = false;
    bool colour = true;
    bool validPiece = false;
    bool pieceColour = false;
    bool eof = false;
    bool quit = false;
    bool gameOver = false;

    initGame(b);
    cout << b;
    
    cout << "Game Start! White goes first!" << endl;
        
    do
    {
	fromX = readInt(enterX,eof);
    }while(eof);
    
    do
    {
	fromY = readInt(enterY,eof);
    }while(eof);
    
    if(fromX == -1 && fromY == -1)
    {
	do
	{
	    quit = readBool(confirmQuit,eof);
	    
	}while(eof);
	
    }
    
    while (fromX != -1 && fromY != -1)
    {   
	while(!validPiece)
	{
	    if(!(b.isOccupied(fromX,fromY)))
	    {
		cout << "No piece found at given location" << endl;
		do
		{
		    fromX = readInt(enterX,eof);
		}while(eof);
		
		do
		{
		    fromY = readInt(enterY,eof);
		}while(eof);

		validPiece = false;
	    }
	    else if(fromX > MAXROWS - 1 || fromY > MAXCOLS - 1)
	    {
		cout << "Going out of the board, select a different piece: ";
		do
		{
		    fromX = readInt(enterX,eof);
		}while(eof);
		
		do
		{
		    fromY = readInt(enterY,eof);
		}while(eof);
		
		validPiece = false;
	    }
	    else
	    {
		piece = b.getPiece(fromX,fromY);
		
		pieceColour = piece->getColour();
				
		if(pieceColour != colour)
		{
		    cout << "Do not move your opponent's piece!" << endl;
		    
		    do
		    {
			fromX = readInt(enterX,eof);
		    }while(eof);
		    
		    do
		    {
			fromY = readInt(enterY,eof);
		    }while(eof);
		}
		else
		{
		    validPiece = true;
		}
	    }
	}
       
	cout << "Enter the coordinate of its destination" << endl;
	do
	{
	    toX = readInt(enterX,eof);
	}while(eof);
	
	do
	{
	    toY = readInt(enterY,eof);
	}while(eof);
	
	while(toX > MAXROWS - 1 || toY > MAXCOLS - 1)
	{
	    cout << "Going out of the board, try again!" << endl;
	    do
	    {
		toX = readInt(enterX,eof);
	    }while(eof);
	    
	    do
	    {
		toY = readInt(enterY,eof);
	    }while(eof);
	}
	
	moved = b.move(colour,fromX,fromY,toX,toY);
	    
	while(!moved)
	{
	    cout << "Cannot move this way,try a different piece!" << endl;
	    do
	    {
		fromX = readInt(enterX,eof);
	    }while(eof);
	    
	    do
	    {
		fromY = readInt(enterY,eof);
	    }while(eof);
	    	
	    cout << "Enter the coordinate of its destination" << endl;
	    do
	    {
		toX = readInt(enterX,eof);
	    }while(eof);
	    
	    do
	    {
		toY = readInt(enterY,eof);
	    }while(eof);
	    
	    moved = b.move(colour,fromX,fromY,toX,toY);
	}
	
	cout << b;
	
	gameOver = detectKing(b);
	if(gameOver)
	{
	    cout << endl <<  "  **** Game over! ****" << endl;
	    fromX = -1;
	    fromY = -1;
	    if(colour)
		cout << "*** White side wins! ***" << endl;
	    else
		cout << "*** Black side wins! ***" << endl;
	    delete piece;
	}
	else
	{
	    colour = !colour;
	 
	    if(colour == false)
		cout << "Black's turn!" << endl;
	    else
		cout << "White's turn!" << endl;
		
	    cout << "Enter a piece you wish to move: " << endl;
	    do
	    {
		fromX = readInt(enterX,eof);
	    }while(eof);
		
	    do
	    {
		fromY = readInt(enterY,eof);
	    }while(eof);

	    delete piece;
	    
	    validPiece = false;
	    
	}
    }    
    cout << endl << "Game Ending.." << endl;
    cout << "Have a nice day!" << endl;
    
    return 0;
}

/*
 =======================================================================
 Function: void initGame(Board& b)
 
 Purpose:  This function initialize the chess game by placing all the 
           required pieces onto the board.

 Details:  Pieces are created dynamically and gets places onto the board
           using Board class' place function,
 =======================================================================
*/

void initGame(Board& b)
{
    PiecePtr piece;
    bool tof;

    for(int i = 0;i < MAXCOLS;i++)
    {
	piece = new Pawn(WHITE);
	tof = b.place(piece,6,i);
	piece = new Pawn(BLACK);
	tof = b.place(piece,1,i);
    }
    
    piece = new Rook(WHITE);
    tof = b.place(piece,7,0);
    piece = new Rook(WHITE);
    tof = b.place(piece,7,7);
    
    piece = new Rook(BLACK);
    tof = b.place(piece,0,0);
    piece = new Rook(BLACK);
    tof = b.place(piece,0,7);

    piece = new Knight(WHITE);
    tof = b.place(piece,7,1);
    piece = new Knight(WHITE);
    tof = b.place(piece,7,6);
    
    piece = new Knight(BLACK);
    tof = b.place(piece,0,1);
    piece = new Knight(BLACK);
    tof = b.place(piece,0,6);
    
    piece = new Bishop(WHITE);
    tof = b.place(piece,7,2);
    piece = new Bishop(WHITE);
    tof = b.place(piece,7,5);
    
    piece = new Bishop(BLACK);
    tof = b.place(piece,0,2);
    piece = new Bishop(BLACK);
    tof = b.place(piece,0,5);
    
    piece = new Queen(WHITE);
    tof = b.place(piece,7,3);
    piece = new Queen(BLACK);
    tof = b.place(piece,0,3);

    piece = new King(WHITE);
    tof = b.place(piece,7,4);
    piece = new King(BLACK);
    tof = b.place(piece,0,4);    
    
}

/*
 =======================================================================
 Function: bool detectKing(Board &b)
 
 Purpose:  This function goes through the board and see if there is still
           two kings on the board.

 Details:  The white king and the black king are being searched inside
           different loops, the search is done by using the board class'
	   getSymbol function which will return the character that 
	   correspond to a specific piece. If one of the king is being
	   captured (missing from the board), a bool will be returned
	   that indicates the end of the game.
 =======================================================================
*/
bool detectKing(Board &b)
{

    bool whiteExist = false;
    bool blackExist = false;
    bool gameOver = false;
    int x;
    int y;
    PiecePtr p;

    for(x = 0;x < MAXROWS && !whiteExist;x++)
    {
	for(y = 0;y < MAXCOLS && !whiteExist;y++)
	{
	    if(b.isOccupied(x,y))
	    {
		p = b.getPiece(x,y);
		if(p -> getColour())
		{
		    if(p -> getSymbol() == 'K')
		    {
			whiteExist = true;
		    }
		}
		delete p;
	    }
	    
	} 
    }
    for(x = 0;x < MAXROWS && !blackExist;x++)
    {
	for(y = 0;y < MAXCOLS && !blackExist;y++)
	{
	    if(b.isOccupied(x,y))
	    {
		p = b.getPiece(x,y);
		if(!(p -> getColour()))
		{
		    if(p -> getSymbol() == 'k')
		    {
			blackExist = true;
		    }		
		}
		delete p;
	    }
	} 
    }

    if(!whiteExist || !blackExist)
    {
	gameOver = true;
    }
 
    return gameOver;

}


