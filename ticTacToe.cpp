/*
File: ticTacToe.cpp
Author: Cody Gilbert
Date: 01/31/2026

Description:

This program runs a 2-player game of tic-tac-toe by prompting
the players to enter a row selection and column selection,
then printing the selections to a 3 x 3 grid. The grid is 
generated using a 2d grid array, nested 'for' loops
and 'if' conditions. 

For char input in row and col int variables:
https://www.geeksforgeeks.org/cpp/how-to-handle-wrong-data-type-input-in-cpp/

*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int ROWS = 3;
const int COLS = 3;
const string DEFAULT_STRING = " _ ";


void printGreeting() {
/*
 Prints a welcome message
*/
  cout << "XOXOXOXOXOXOXOXOXOXOXOXOX" << endl;
  cout << "WELCOME TO TIC-TAC-TOE!!!" << endl;
  cout << "XOXOXOXOXOXOXOXOXOXOXOXOX" << endl;
}

void boardMaker(string board[ROWS][COLS]) {
/*
   Creates a 3 x 3 tic-tac-toe board with
   underscores as placeholders

   Input: char board[ROWS][COLS]
   Output: None
*/  
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = DEFAULT_STRING;
    }
  }
} 


void boardPrinter(string board[ROWS][COLS]) {
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

bool isValidMove (string board[ROWS][COLS], 
                  int row, int col, 
                  bool rowFail, bool colFail) {
/*
   Handles all validation checks, and returns false if
   any are true, or true if none are true
  
   Input:board, row and col inputs, 
      rowFail and colFail bools
   
   Output: boolean
*/

  // Clears the cin error flags and removes invalid char
  if (rowFail) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  }
  
  else if (colFail) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  }
  
  // Input range checks
  else if ((row < 1) && (row > ROWS)) {
    return false;    
  }

  else if ((col < 1) && (col > COLS)) {
    return false;
  }

  else if (!(board[row][col] == DEFAULT_STRING)) {
    return false;
  }
  
  return true;
}

int decideWinner(string board[ROWS][COLS], 
    string player, int moveCount) {

/*
  Returns 1, 2, or 3 depending on game state  
*/
    // Checks for a completed row
    for (int i = 0; i < ROWS; i++) {
      if (board[i][0] == player &&
        board[i][1] == player &&
        board[i][2] == player) {          
        return 1;
    }
  }
    // Checks for a completed column
    for (int i = 0; i < COLS; i++) {     
      if (board[0][i] == player &&
        board[1][i] == player &&
        board[2][i] == player) {        
        return 1;
     }
   }
    // Checks for complete diagonal
    // (Top left to bottom right)
    if(board[0][0] == player &&
       board[1][1] == player &&
       board[2][2] == player) {
       return 1;
     }     
    // Checks for diagonal
    // (Bottom left to top right)
    if(board[2][0] == player &&
       board[1][1] == player &&
       board[0][2] == player) {
       return 1;
     }
    // Checks if board is full (draw)
    if (moveCount == 9) return 2;
       return 0;
}



void playerMove(string board[ROWS][COLS], string player) {
/*
   Prompts the user for row and column input and updates
   the game board with the assigned player string 
*/ 

  int row, col;
  bool invalidMove = true;

  // Loops until a valid move is entered
  while (invalidMove) {
    boardPrinter(board);
    cout << "Player" << player << "make your move!" << endl;

    // Assigns fail state to bool variable if not an int
    cout << "Enter row number: ";
    bool rowFail = !(cin >> row); 
    cout << "Enter column number: ";
    bool colFail = !(cin >> col);
    row--; col--;
    
    // Calls isValidMove function as condtion and breaks loop if true
     if ((isValidMove(board, row, col, rowFail, colFail)) == true) { 
        board[row][col] = player;
        invalidMove = false;
    } else {
        cout << "Invalid Move! Try again!" << endl;
    }
     
  }  
}

void playGame(string board[ROWS][COLS]) {
/*
   Initializes default board, gameOver flag with 
   false, and currentPlayer with X.

   Calls playerMove, and then switches player in a loop
   until an end of game condition is reached
*/
  
  bool playAgain = true;  
  char restart;
  
  // Loops until player quits the game
  while(playAgain) {
  
  // Initialized variables reset at game start 
  printGreeting();
  boardMaker(board);
  bool gameOver = false;
  string currentPlayer = " X ";
  int moveCount = 0;
    
    // Loops until winner or draw is decided
    while (!gameOver) {
      playerMove(board, currentPlayer);
      moveCount++;
      
      // Calls decideWinner and assigns gameState with result
      int gameState = decideWinner(board, currentPlayer, moveCount);
      
      // Declares winner or draw or switches players and
      // continues the loop depending on gameState
      if (gameState == 1) {
        boardPrinter(board);
        cout << "Player" << currentPlayer << "wins!" << endl;
        gameOver = true;
      }
      else if (gameState == 2) {
        boardPrinter(board);
        cout << "It's a draw!" << endl;
        gameOver = true; 
      } 
      else {
       if (currentPlayer == " X ") {
        currentPlayer = " O ";
      } else {
        currentPlayer = " X ";
       }       
     }
   }
    
    // Continues or ends the game
    cout << "Play again? (Y/N): ";
    cin >> restart;
    if (restart == 'y' || restart == 'Y') {
    playAgain = true;      
    } else {
        cout << "Thanks for playing!" << endl;
        playAgain = false;
    }
  }
}

int main() {
  string gameBoard[ROWS][COLS];
  playGame(gameBoard);
  return 0;

}
