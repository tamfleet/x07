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

TEST(TicTacToeBoardTest, checktoggle)
{
	TicTacToeBoard board;
	board.placePiece(1,1);
	ASSERT_EQ(board.placePiece(2,1), 'O');
}

TEST(TicTacToeBoardTest, placeOutofBounds)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(3,3), '?');
}

TEST(TicTacToeBoardTest, getOutofBounds)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(3,3), '?');
}

TEST(TicTacToeBoardTest, loseTurn)
{
	TicTacToeBoard board;
	board.placePiece(3,3);
	ASSERT_EQ(board.placePiece(0,0), 'O');
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


//FIX THIS ONE
TEST(TicTacToeBoardTest, clearBoardTest)
{
	bool test = true;
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

//Case 1: row of 3
TEST(TicTacToeBoardTest, XrowWin)
{
	TicTacToeBoard board;
	board.placePiece(2,1);
	board.placePiece(0,0);
	board.placePiece(2,2);
	board.placePiece(0,2);
	board.placePiece(2,0);
	ASSERT_EQ(board.getWinner(), 'X');
}

TEST(TicTacToeBoardTest, OrowWin)
{
	TicTacToeBoard board;
	board.placePiece(2,1);
	board.placePiece(0,0);
	board.placePiece(1,2);
	board.placePiece(0,2);
	board.placePiece(2,0);
	board.placePiece(0,1);
	ASSERT_EQ(board.getWinner(), 'O');
}

//Case 2: column of 3
TEST(TicTacToeBoardTest, XcolWin)
{
	TicTacToeBoard board;
	board.placePiece(2,1);
	board.placePiece(0,0);
	board.placePiece(1,1);
	board.placePiece(0,2);
	board.placePiece(0,1);
	ASSERT_EQ(board.getWinner(), 'X');
}

//Case 3: diagonal of 3
TEST(TicTacToeBoardTest, OdiagonalWin)
{
	TicTacToeBoard board;
	board.placePiece(2,1);
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(2,2);
	board.placePiece(1,2);
	board.placePiece(1,1);
	ASSERT_EQ(board.getWinner(), 'O');
}

//Case 4: tie
TEST(TicTacToeBoardTest, noWinner)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(2,0);
	board.placePiece(1,1);
	board.placePiece(1,2);
	board.placePiece(2,1);
	board.placePiece(2,2);
	board.placePiece(1,0);
	ASSERT_EQ(board.getWinner(), ' ');
}

//Case 5: keep playing
TEST(TicTacToeBoardTest, noWinNotFinished)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(2,0);
	board.placePiece(1,1);
	board.placePiece(1,2);
	ASSERT_EQ(board.getWinner(), '?');
}

//Clear board, then check winner
TEST(TicTacToeBoardTest, ClearBoardnoWinner)
{
	TicTacToeBoard board;
	board.placePiece(2,1);
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(2,2);
	board.placePiece(1,2);
	board.placePiece(1,1);
	board.clearBoard();
	ASSERT_EQ(board.getWinner(), '?');
}

//TEST IF BOTH X and O wins???

