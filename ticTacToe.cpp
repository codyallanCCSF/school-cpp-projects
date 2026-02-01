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

const bool gameOver = false;


void initGameBoard(string board[][COLS]) {
  for(int row = 0; row < ROWS; row++) {
    for(int col = 0; col < COLS; col++) {
    board[row][col] = " _ ";
    }
  }
}

void boardPrinter(string board[][COLS]) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      cout << board[row][col];
    }
    cout << endl;
  }
}

void printGreeting() {

}

void getSelection() {

}

void printSelection() {

}

void declareWinner() {

}


int main() {
  string gameBoard[ROWS][COLS];
  initGameBoard(gameBoard);
  boardPrinter(gameBoard);
  return 0;

}
