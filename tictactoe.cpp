// TicTacToe game, 2 players. By Anika Gupta, 9/11/23.

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

void TicTacToe();
void printBoard(int board[3][3]);
int checkWin(int player, int board[3][3]);
int checkTie(int board[3][3]);
int blank=0;
int x_move=1;
int o_move=2;
int x_turn=0;
int o_turn=1;



int main()
{
  /*
  
  int board[3][3];
  int turn=x_turn;
  int x_win=0;
  int o_win=0;
  int keepPlaying=1;

  */
  
  TicTacToe();
  return 0;
}

void TicTacToe()
{
	// initialising variables
  int board[3][3];
  int turn=x_turn;
  int x_win=0;
  int o_win=0;
  int keepPlaying=1;

  
  // cout << "reached tictactoe!!" << endl;

  while (keepPlaying==1) {
    for (int r=0; r<3; r++) {
      for (int c=0; c<3; c++) {
	// when game is restarted, make board blank and make turn x
	board[r][c]=blank;
	turn = x_turn;
      }
    }

    while (checkWin(x_move, board)==0 && checkWin(o_move, board)==0 && checkTie(board)==0) { // while no one has won

      printBoard(board);

	    // getting coordinates from user
      cout << "Type the coordinates of your next move." << endl;
      cout << " First type from a-c" << endl;
      
      char input;
      cin >> input;
      cout << "Now type a number from 1-3" << endl;
      int inpt;
      cin >> inpt;
      if (input != 'a' && input != 'b' && input != 'c') {
	cout << "Your first character should be a, b, or c" << endl;
      } // if input[0] isn't abc

      if (inpt != 1 && inpt != 2 && inpt != 3) {
	cout << "your second character should be 1, 2, or 3" << endl;
      } // if input[1] isn't 123

      else {
	int r;
	int c = inpt-1;
	if (input == 'a') {
	  r = 0;
	}
	else if (input == 'b') {
	  r=1;
	}
	else if (input == 'c') {
	  r=2;
	}

	if (board[r][c] != blank) {
	  cout << "that spot is already taken" << endl;
	}
	// setting the spot
	else {
	  cout << "r is: " << r << " c is: " << c << endl;
	  if (turn==x_turn) {
	    board[r][c]  = x_move;
	  
	    turn = o_turn;   
	  }
	  else {
	    board[r][c] = o_move;
	    turn = x_turn;
	  }


	}
	


      } // end of else

      
    } // end of while checking wins

    if (checkWin(x_move, board)==1 || checkWin(o_move, board)==1 || checkTie(board) ==1) {

      printBoard(board);
      if (checkWin(o_move, board)==1) {
	o_win++;
	cout << "O won! So far, o has: " << o_win << " wins and x has: " << x_win << " wins." << endl;
      } // end of if o won
      else if (checkWin(x_move, board)==1) {
	x_win++;
	cout << "X won! So far, x has: " << x_win << " wins and o has: " << o_win << " wins." << endl;
      } // end of if x won

      else if (checkTie(board)==1) {
	cout << "It was a tie! So far, x has: " << x_win << " wins and O has " << o_win << " wins." << endl;
      } // end of if it's a tie

      cout << "Do you want to keep playing? y for yes, n for no" << endl;
      char in = 'a';
      cin >> in;
      if (in=='y') {
	keepPlaying=1;
	for (int r=0; r<3; r++) {
	  for (int c=0; c<3; c++) {
	    board[r][c] = blank;
	  } // end of c<3 for loop
	} // end of r<3 for loop

	checkWin(x_move, board);
	checkWin(o_move, board);
	
      } // if input is yes
      else {
	keepPlaying=false;
	cout << "Okay, thanks for playing" << endl;
      } // elseif input is no
    } // end of if checkwin true
    
    
    
  } // end of while keep playing true


  
  printBoard(board);
}

void printBoard(int board[3][3]) 
{ // prints the board
  //cout << "printing board!" << endl;
  cout << "\t1\t2\t3" << endl;
  // char output[10] = {' '};
  for (int r=0; r<3; r++) {
    char output[10] = {' '};
    output[1] = char('a'+r);
    
    output[2] = '\t';
    
    int co=2;
    for (int c=0; c<3; c++) {
      co++;
      if (board[r][c]==blank) {
	//cout << "blank" << endl;
	output[co] = '\t';
      }
      else if (board[r][c]==x_move) {
	output[co] = 'x';
	co++;

	output [co] = '\t';
	
	//cout << "x move" << endl;
	//strcat(output, xout);
	//cout << "xmove" << endl;
	
      }
      else if (board[r][c] == o_move) {
	output[co] = 'o';
	co++;
	output[co] = '\t';
	
	//cout << "o move" << endl;
	//strcat(output, oout);
      }
      //co++;
      //output[co] = '\t';

      
      //cout << output << endl;
    } // for c
    
    cout << output << endl;
  } // for r
}

int checkWin(int player, int board[3][3])
{ // checks for wins by looking at every 3 in a row possibility
  // add this (long if statement for every tictactoe spot)
  if (board[0][0]==player && board[0][1]==player && board[0][2]==player || board[0][0]==player && board[1][0]==player && board[2][0]==player || board[0][0]==player && board [1][1]==player && board[2][2]==player || board [0][2]==player && board[1][1]== player && board[2][0]==player || board[1][0]==player && board[1][1]==player && board[1][2]==player || board[2][0]==player && board[2][1]==player && board[2][2]==player || board[0][1]==player && board[1][1]==player && board[2][1]==player || board[0][2]==player && board[1][2]==player && board[2][2]==player) {
    return 1;
  } //end if 
  return 0;
}

int checkTie(int board[3][3])
{ // checking for ties by checking if board is empty
  for (int r=0; r<3; r++) {
    for (int c=0; c<3; c++) {
      if (board[r][c]==blank) {
	return 0;
	//	cout << "still blank spots, not tie" << endl;
      } // end if blank
    } // end columns
  } // end rows

  //cout << "no blank spots..." << endl;
  
  return 1;
}
