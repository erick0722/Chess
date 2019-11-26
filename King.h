/*
 =======================================================================

  The "King" class: represents a king in chess
 
  Public Method Specification:

        King(bool col): represents a king with a specific colour.

	getSymbol: returns the symbol represented by the king.

	canMove: returns a boolean value indicating whether the 
	         movement of a king is valid. Will only return true
		 if it is moving only one space either veritically,
		 horizontally, or diagonally.

	clone: returns a pointer to a duplicate copy of a king.

 ======================================================================= 
 */

#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
public:
    King(bool col);

    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
    PiecePtr clone() const;
};

#endif
