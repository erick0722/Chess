#include <gtest/gtest.h>
#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"

using namespace std;

class test_Piece : public testing::Test {
protected:
    virtual void SetUp()
    {

    }
    virtual void TearDown()
    {

    }
    Board b;
    PiecePtr p;
};

TEST_F(test_Piece,testGetSymbol)
{
  
    p = new Pawn(WHITE);
    EXPECT_EQ('P',p->getSymbol());

    p = new Rook(WHITE);
    EXPECT_EQ('R',p->getSymbol());

    p = new Bishop(WHITE);
    EXPECT_EQ('B',p->getSymbol());

    p = new Knight(WHITE);
    EXPECT_EQ('N',p->getSymbol());

    p = new Queen(WHITE);
    EXPECT_EQ('Q',p->getSymbol());

    p = new King(WHITE);
    EXPECT_EQ('K',p->getSymbol());

    p = new Pawn(BLACK);
    EXPECT_EQ('p',p->getSymbol());

    p = new Rook(BLACK);
    EXPECT_EQ('r',p->getSymbol());

    p = new Bishop(BLACK);
    EXPECT_EQ('b',p->getSymbol());

    p = new Knight(BLACK);
    EXPECT_EQ('n',p->getSymbol());
    
    p = new Queen(BLACK);
    EXPECT_EQ('q',p->getSymbol());

    p = new King(BLACK);
    EXPECT_EQ('k',p->getSymbol());
}

TEST_F(test_Piece,testGetColour)
{
    bool f = false;

    p = new Pawn(WHITE);
    EXPECT_EQ(WHITE,p->getColour());

    p = new Rook(WHITE);
    EXPECT_EQ(WHITE,p->getColour());

    p = new Bishop(WHITE);
    EXPECT_EQ(WHITE,p->getColour());
   
    p = new Knight(WHITE);
    EXPECT_EQ(WHITE,p->getColour());
   
    p = new Queen(WHITE);
    EXPECT_EQ(WHITE,p->getColour());
   
    p = new King(WHITE);
    EXPECT_EQ(WHITE,p->getColour());
   
    p = new Pawn(f);
    EXPECT_EQ(f,p->getColour());

    p = new Rook(f);
    EXPECT_EQ(f,p->getColour());

    p = new Bishop(f);
    EXPECT_EQ(f,p->getColour());

    p = new Knight(f);
    EXPECT_EQ(f,p->getColour());
    
    p = new Queen(f);
    EXPECT_EQ(f,p->getColour());

    p = new King(f);
    EXPECT_EQ(f,p->getColour());
    
}

TEST_F(test_Piece,testCanMovePawn)
{
    bool t = true;    
    
    p = new Pawn(t);
    b.place(p,6,0);

    p = new Pawn(t);
    b.place(p,7,5);

    p = new Pawn(t);
    b.place(p,0,0);

    p = new Pawn(t);
    b.place(p,5,0);

    p = new Pawn(t);
    b.place(p,3,3);
    
    p = new Pawn(!t);
    b.place(p,3,1);

    p = new Pawn(!t);
    b.place(p,6,1);

    p = new Pawn(!t);
    b.place(p,3,6);

    p = new Pawn(!t);
    b.place(p,1,3);

    p = new Pawn(!t);
    b.place(p,2,2);
    
    EXPECT_EQ(t,p->canMove(b,6,0,4,0));
    
    EXPECT_EQ(!t,p->canMove(b,5,0,3,0));
    
    EXPECT_EQ(!t,p->canMove(b,7,5,7,6));

    EXPECT_EQ(!t,p->canMove(b,0,0,0,2));

    EXPECT_EQ(!t,p->canMove(b,3,3,2,3));

    EXPECT_EQ(!t,p->canMove(b,2,3,3,3));

    EXPECT_EQ(!t,p->canMove(b,4,0,5,0));

    EXPECT_EQ(t,p->canMove(b,3,6,4,6));
    
    EXPECT_EQ(!t,p->canMove(b,3,1,2,3));
    
    EXPECT_EQ(!t,p->canMove(b,2,2,2,3));

    EXPECT_EQ(!t,p->canMove(b,1,3,2,3));

    EXPECT_EQ(!t,p->canMove(b,6,1,7,1));

    EXPECT_EQ(!t,p->canMove(b,2,3,3,3));

    EXPECT_EQ(!t,p->canMove(b,4,0,5,0));

}

TEST_F(test_Piece,testCanMoveRook)
{
    bool t = true;    
    
    p = new Rook(t);
    b.place(p,7,0);
    
    p = new Rook(t);
    b.place(p,0,2);
    
    p = new Rook(t);
    b.place(p,1,4);
    
    p = new Rook(t);
    b.place(p,5,6);

    p = new Rook(!t);
    b.place(p,3,0);
    
    p = new Rook(!t);
    b.place(p,2,2);
    
    p = new Rook(!t);
    b.place(p,6,6);
    
    p = new Rook(!t);
    b.place(p,5,7);

    EXPECT_EQ(!t,p->canMove(b,7,0,0,0));

    EXPECT_EQ(!t,p->canMove(b,0,0,0,6));
    
    EXPECT_EQ(t,p->canMove(b,0,2,1,2));

    EXPECT_EQ(t,p->canMove(b,1,4,0,4));

    EXPECT_EQ(t,p->canMove(b,5,6,5,2));

    EXPECT_EQ(t,p->canMove(b,3,0,0,0));

    EXPECT_EQ(t,p->canMove(b,2,2,2,4));
    
    EXPECT_EQ(!t,p->canMove(b,6,6,2,6));
    
    EXPECT_EQ(!t,p->canMove(b,2,6,2,1));
    
    EXPECT_EQ(t,p->canMove(b,5,7,5,6));
}

TEST_F(test_Piece,testCanMoveKnight)
{
    bool t = true;    

    p = new Knight(t);
    b.place(p,7,1);
    
    p = new Knight(t);
    b.place(p,3,1);
    
    p = new Knight(t);
    b.place(p,1,3);
    
    p = new Knight(t);
    b.place(p,3,6);

    p = new Knight(!t);
    b.place(p,0,1);
    
    p = new Knight(!t);
    b.place(p,2,5);
    
    p = new Knight(!t);
    b.place(p,6,4);
    
    EXPECT_EQ(!t,p->canMove(b,7,1,5,3));
    
    EXPECT_EQ(!t,p->canMove(b,7,1,5,1));

    EXPECT_EQ(t,p->canMove(b,7,1,5,2));

    EXPECT_EQ(t,p->canMove(b,3,1,4,3));

    EXPECT_EQ(t,p->canMove(b,3,6,1,7));

    EXPECT_EQ(!t,p->canMove(b,1,3,0,2));

    EXPECT_EQ(t,p->canMove(b,0,1,1,3));

    EXPECT_EQ(!t,p->canMove(b,1,3,2,3));

    EXPECT_EQ(!t,p->canMove(b,2,5,4,3));

    EXPECT_EQ(t,p->canMove(b,2,5,0,6));

    EXPECT_EQ(t,p->canMove(b,6,4,7,6));
}

TEST_F(test_Piece,testCanMoveBishop)
{
    bool t = true;

    p = new Bishop(t);
    b.place(p,4,3);

    p = new Bishop(t);
    b.place(p,5,6);
    
    p = new Bishop(!t);
    b.place(p,3,0);

    p = new Bishop(!t);
    b.place(p,3,4);

    EXPECT_EQ(!t,p->canMove(b,4,3,1,3));

    EXPECT_EQ(!t,p->canMove(b,4,3,6,6));

    EXPECT_EQ(t,p->canMove(b,4,3,1,0));

    EXPECT_EQ(t,p->canMove(b,1,0,0,1));

    EXPECT_EQ(t,p->canMove(b,5,6,7,4));
    
    EXPECT_EQ(!t,p->canMove(b,3,0,2,0));

    EXPECT_EQ(t,p->canMove(b,3,4,0,1));

    EXPECT_EQ(t,p->canMove(b,3,0,6,3));

    EXPECT_EQ(!t,p->canMove(b,6,3,6,0));

    EXPECT_EQ(t,p->canMove(b,6,3,7,4));    
}

TEST_F(test_Piece,testCanMoveQueen)
{
    bool t = true;

    p = new Queen(t);
    b.place(p,2,2);

    p = new Queen(t);
    b.place(p,0,6);

    p = new Queen(!t);
    b.place(p,6,5);
    
    p = new Queen(!t);
    b.place(p,4,6);

    EXPECT_EQ(t,p->canMove(b,2,2,2,7));
	      
    EXPECT_EQ(!t,p->canMove(b,2,7,0,6));
    
    EXPECT_EQ(t,p->canMove(b,0,6,0,2));

    EXPECT_EQ(!t,p->canMove(b,0,2,4,5));
    
    EXPECT_EQ(!t,p->canMove(b,6,5,7,3));

    EXPECT_EQ(t,p->canMove(b,4,6,3,6));
    
    EXPECT_EQ(t,p->canMove(b,3,6,0,6));
}

TEST_F(test_Piece,testCanMoveKing)
{
    bool t = true;

    p = new King(t);
    b.place(p,0,3);
    
    p = new King(!t);
    b.place(p,4,5);

    p = new King(t);
    b.place(p,2,6);

    EXPECT_EQ(!t,p->canMove(b,0,3,0,5));
    
    EXPECT_EQ(!t,p->canMove(b,0,3,2,2));
    
    EXPECT_EQ(t,p->canMove(b,0,3,0,4));
    
    EXPECT_EQ(t,p->canMove(b,0,4,1,4));
    
    EXPECT_EQ(t,p->canMove(b,4,5,3,6));
    
    EXPECT_EQ(t,p->canMove(b,2,6,3,6));
    
    EXPECT_EQ(t,p->canMove(b,3,6,3,5));
}

