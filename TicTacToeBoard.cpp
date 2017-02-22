#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
  if(turn==X)
    turn=O;
  else
    turn=X;
}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  for(int r=0; r<3; r++)
  {
    for(int c=0; c<3; c++){
      board[r][c] = Blank;
    }
  }
  turn = X;
}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
  for(int r=1; r<=3; r++)
  {
    for(int c=1; c<=3; c++){
      board[r][c] = Blank;
    }
  }
 
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(row>2 || row<0 || column>2 || column<0)
    return Invalid;
  if(board[row][column]==Blank){
    board[row][column]=turn;
  }
  return board[row][column];
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row>2 || row<0 || column>2 || column<0)
    return Invalid;
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  for(int r=0; r<3; r++)
  {
    for(int c=0; c<3; c++){
      if(board[r][c] == Blank)
        return Invalid;
    }
  }
  return Blank;
}
