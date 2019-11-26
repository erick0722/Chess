/*
 =======================================================================

  The "Rook" class: represents a rook in chess
 
  Public Method Specification:

        Rook(bool col): represents a rook with a specific colour.

	getSymbol: returns the symbol represented by the rook.

	canMove: returns a boolean value indicating whether the 
	         movement of a rook is valid. Will only return true
		 if the rook is moving vertically or horizontally and
		 when there is no pieces of the same colour sitting on
		 its way.

	clone: returns a pointer to a duplicate copy of a rook.

 ======================================================================= 
 */

#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(bool col);

    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
    PiecePtr clone() const;
};

#endif
