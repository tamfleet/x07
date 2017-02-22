/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, firstPieceIsX)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,0), 'X');

}

TEST(TicTacToeBoardTest, checkToggle)
{
	TicTacToeBoard board;
	board.placePiece(1,1);
	char turn = board.placePiece(2,1);
	ASSERT_EQ(turn, 'O');

}

TEST(TicTacToeBoardTest, placeOutofBounds)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(3,3), '?');
}

TEST(TicTacToeBoardTest, initBoardStartsBlank)
{
	bool test;
	TicTacToeBoard board;
	for (int r=0; r<3; r++){
		for (int c=0; c<3; c++){
			if(board.getPiece(r, c)==' ')
				test = true;
			else
				test = false;
		}
	}
	ASSERT_TRUE(test);	
}


TEST(TicTacToeBoardTest, clearBoardTest)
{
	bool test;
	TicTacToeBoard board;
	board.placePiece(2,1);
	board.placePiece(2,2);
	board.placePiece(0,2);
	board.clearBoard();
	for (int r=0; r<3; r++){
		for (int c=0; c<3; c++){
			if(board.getPiece(r, c)!=' ')
				test = false;
		}
	}
	ASSERT_TRUE(test);	
}
