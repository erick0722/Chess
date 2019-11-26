/*
 =======================================================================

  The "Pawn" class: represents a pawn in chess
 
  Public Method Specification:

        Pawn(bool col): represents a pawn with a specific colour.

	getSymbol: returns the symbol represented by the pawn.

	canMove: returns a boolean value indicating whether the 
	         movement of a pawn is valid. Will only return true
		 if the pawn is moving one space forward, or two if it
		 hasn't yet moved, or when there is a piece of opposing
		 colour on its diagonal.

	clone: returns a pointer to a duplicate copy of a pawn.

 ======================================================================= 
 */

#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Board.h"
class Pawn : public Piece
{
public:
    Pawn(bool col);

    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
    PiecePtr clone() const;

private:
   bool hasMoved;

};

#endif
