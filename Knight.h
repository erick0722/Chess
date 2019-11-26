/*
 =======================================================================

  The "Knight" class: represents a knight in chess
 
  Public Method Specification:

        Knight(bool col): represents a knight with a specific colour.

	getSymbol: returns the symbol represented by the knight.

	canMove: returns a boolean value indicating whether the 
	         movement of the knight is valid. Will only return true
		 if it is moving two spaces horizontally and one space
		 vertically or the other way around.

	clone: returns a pointer to a duplicate copy of a knight.

 ======================================================================= 
 */
#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(bool col);

    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
    PiecePtr clone() const;
};

#endif
