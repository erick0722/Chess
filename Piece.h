/*
 =======================================================================

  The "Piece" class: represents a piece in chess
 
  Public Method Specification:

        Piece(bool col): represents a piece with a specific colour.

	getColour: returns the colour of a piece(in terms of a boolean).

	getSymbol: returns the symbol represented by the piece.

	canMove: returns a boolean value indicating whether  the 
	         movement of a piece is valid.

	clone: returns a pointer to a duplicate copy of a piece.

 ======================================================================= 
 */

#ifndef PIECE_H
#define PIECE_H

class Piece;
#include "Board.h"
#include <iostream>
#include <cmath>
using namespace std;


#define WHITE true
#define BLACK false

typedef Piece* PiecePtr;

class Piece
{
public:
   Piece (bool col);
   virtual ~Piece();

   bool getColour() const;

   virtual char getSymbol() const = 0;
   virtual bool canMove(const Board& b, int fromX, int fromY,
			int toX, int toY) = 0;
   virtual PiecePtr clone()const = 0;
   
private:
   bool colour;
   
protected:
   bool isPathClear (const Board& b, int fromX, int fromY,
		     int toX, int toY)const;
   bool isVertical (int fromX, int fromY, int toX, int toY) const;
   bool isHorizontal (int fromX, int fromY, int toX, int toY) const;
   bool isDiagonal (int fromX, int fromY, int toX, int toY) const;
   bool isForward (int fromX, int toX) const;
   int vertDistance (int fromX, int toX) const;
   int horizDistance (int fromY, int toY) const;
   
};

#endif
