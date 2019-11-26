/*
 =======================================================================

  The "Queen" class: represents a queen in chess
 
  Public Method Specification:

        Queen(bool col): represents a queen with a specific colour.

	getSymbol: returns the symbol represented by the queen.

	canMove: returns a boolean value indicating whether the 
	         movement of a pawn is valid. Will only return true
		 if the queen is either moving horizontally, vertically,
		 or diagonally, and there has to be no pieces in between
		 the starting point and the destiniation.

	clone: returns a pointer to a duplicate copy of a queen.

 ======================================================================= 
 */

#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(bool col);

    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
    PiecePtr clone() const;
};

#endif
