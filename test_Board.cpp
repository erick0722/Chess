#include <iostream>
#include <gtest/gtest.h>
#include <sstream>
#include "Board.h"
#include "Piece.h"
#include "Pawn.h"

using namespace std;

class test_Board : public testing::Test {
protected:
    virtual void SetUp()
    {
	
    }
    virtual void TearDown()
    {
	
    }
    Board game;       
    PiecePtr p;
};

TEST_F(test_Board,testOccupied)
{
    bool t = true;
   
    p = new Pawn(t);
    game.place(p,3,2);
    p = new Pawn(t);
    game.place(p,7,6);
    p = new Pawn(t);
    game.place(p,0,2);
    
    EXPECT_EQ(t,game.isOccupied(3,2));
    
    EXPECT_EQ(t,game.isOccupied(7,6));
    
    EXPECT_EQ(t,game.isOccupied(0,2));
    
    EXPECT_EQ(!t,game.isOccupied(2,2));
    
    EXPECT_EQ(!t,game.isOccupied(5,3));

    EXPECT_EQ(!t,game.isOccupied(4,3));
}

TEST_F(test_Board,testMove)
{
    bool t = true;
    bool colour = false;
    
    p = new Pawn(t);
    game.place(p,1,1);
    EXPECT_EQ(t,game.move(colour,1,1,2,1));
    EXPECT_EQ(!t,game.move(colour,2,1,4,1));
   
    p = new Pawn(t);
    game.place(p,6,1);
    EXPECT_EQ(!t,game.move(colour,6,1,2,2));
   
    p = new Pawn(t);
    game.place(p,1,2);
    EXPECT_EQ(!t,game.move(colour,1,2,6,5));

    p = new Pawn(t);
    game.place(p,2,3);
    EXPECT_EQ(t,game.move(colour,1,2,2,3));

    p = new Pawn(t);
    game.place(p,3,4);
    EXPECT_EQ(!t,game.move(colour,3,4,4,5));
    
    
}

TEST_F(test_Board,testPlace)
{
    bool t = true;

    p = new Pawn(t);
    EXPECT_EQ(t,game.place(p,1,1));
    
    p = new Pawn(t);
    EXPECT_EQ(t,game.place(p,2,7));
    
    p = new Pawn(t);
    EXPECT_EQ(t,game.place(p,6,1));

    p = new Pawn(t);
    EXPECT_EQ(!t,game.place(p,6,1));

    p = new Pawn(t);
    EXPECT_EQ(t,game.place(p,5,4));
    
} 
   
TEST_F(test_Board,testRemove)
{
    bool t = true;
    
    p = new Pawn(t);
    game.place(p,1,1);
    EXPECT_EQ(t,game.remove(1,1));
    
    p = new Pawn(t);
    game.place(p,7,1);
    EXPECT_EQ(t,game.remove(7,1));

    p = new Pawn(t);
    game.place(p,1,0);
    EXPECT_EQ(!t,game.remove(5,0));

    p = new Pawn(t);
    game.place(p,1,2);
    EXPECT_EQ(!t,game.remove(6,0));

    p = new Pawn(t);
    game.place(p,5,2);
    EXPECT_EQ(!t,game.remove(7,0));
}

TEST_F(test_Board,testWrite)
{
    stringstream actual;
    stringstream expect("    0   1   2   3   4   5   6   7\n  +---+---+---+---+---+---+---+---+\n0 |   |   |   |   |   |   |   |   |\n  +---+---+---+---+---+---+---+---+\n1 |   |   |   |   |   |   |   |   |\n  +---+---+---+---+---+---+---+---+\n2 |   |   |   |   |   |   |   |   |\n  +---+---+---+---+---+---+---+---+\n3 |   |   |   |   |   |   |   |   |\n  +---+---+---+---+---+---+---+---+\n4 |   |   |   |   |   |   |   |   |\n  +---+---+---+---+---+---+---+---+\n5 |   |   |   |   |   |   |   |   |\n  +---+---+---+---+---+---+---+---+\n6 |   |   |   |   |   |   |   |   |\n  +---+---+---+---+---+---+---+---+\n7 |   |   |   |   |   |   |   |   |\n  +---+---+---+---+---+---+---+---+\n");

    game.write(actual);

    EXPECT_EQ(expect.str(),actual.str());
}
