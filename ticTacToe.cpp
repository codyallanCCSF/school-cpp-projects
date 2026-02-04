/*
File: ticTacToe.cpp
Author: Cody Gilbert
Date: 01/31/2026

Description:

This program runs a 2-player game of tic-tac-toe by prompting
the players to enter a row selection and column selection,
then printing the selections to a 3 x 3 grid. The grid is 
generated using a 2d grid array, nested 'for' loops
and 'if' conditions. The program finishes by displaying
the results of the game.

*/

#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

bool GAME_OVER = false;
char player = 'X';

void boardMaker(char board[ROWS][COLS]) {
/*
   Creates a 3 x 3 tic-tac-toe board with
   underscores as placeholders

   Input: char board[ROWS][COLS]
   Output: None
*/  
  // FIXME: INCREASE SIZE OF DEFAULT BOARD
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = '-';
    }
  }
} 


void boardPrinter(char board[ROWS][COLS]) {
/*
   Takes 2d grid array as input and prints
   the results of the boardMaker function,
   updated with results of playerMove()

   Input: char board[ROWS][COLS]
*/

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
} 


void playerMove(char board[ROWS][COLS], char player) {
  
  int row, col;
  bool invalidMove = true;

  while (invalidMove) {
    boardPrinter(board);
    cout << "Player " << player << " make your move!" << '\n';
    cout << "Enter row and column: (Ex: 1 2) ";
    cin >> row >> col;
    row--; col--;
// FIXME: No space between row and col input check
    if ((row >= 0) && (row < ROWS) && 
        (col >= 0) && (col < COLS) &&
        (board[row][col] == '-')) {
      
        board[row][col] = player;
        invalidMove = false;
    } else {
        cout << "Invalid Move! Try again!";
    }
  }  
}

void playGame(char board[ROWS][COLS]) {
  boardMaker(board);

  bool gameOver = false;
  char currentPlayer = 'X';
  
  while (!gameOver) {
    playerMove(board, currentPlayer);

    if (currentPlayer == 'X') {
      currentPlayer = 'O';
    } else {
      currentPlayer = 'X';
    }
  }
    
}


void printGreeting() {

}



void decideWinner(char board[ROWS][COLS]) {
  
}


int main() {
  char gameBoard[ROWS][COLS];
  playGame(gameBoard);
  return 0;

}
