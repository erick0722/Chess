/*
 =======================================================================

  The "Bishop" class: represents a bishop in chess
 
  Public Method Specification:

        Bishop(bool col): represents a bishop with a specific colour.

	getSymbol: returns the symbol represented by the bishop.

	canMove: returns a boolean value indicating whether the 
	         movement of a bishop is valid. Will only return true
		 if it is moving diagonally and if there is no piece
		 in its way.

	clone: returns a pointer to a duplicate copy of a bishop.

 ======================================================================= 
 */
#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(bool col);
    
    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
    PiecePtr clone() const;
};

#endif
