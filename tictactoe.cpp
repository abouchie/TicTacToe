/* Adrienne Bouchie
 * May 12th 2014
 * Objective: Create a program that allows 2 people to play the game Tic Tac Toe using functions
 * tictactoe.cpp
 *
 */


#include <iostream>
using namespace std;


const int ROW = 3;
const int COL = 3;
int board[ROW][COL] = {{-2, -2, -2}, {-2, -2, -2}, {-2, -2, -2}};


main () {

	
	char playerAnswer;
	int playerX = 3;
	int playerO = -3;
	const int WINNER_X = 9;
	const int WINNER_O = -9;
	bool winner = false;
	int counter = 0;
	void displayBoard( int&, int& );
	bool checkForWinner( int, int );
	void makeMove( int );

	cout << "Would you like to play Tic Tac Toe (Y or N)?" << endl;
	cin >> playerAnswer;	

	if ( playerAnswer == 'y' || playerAnswer == 'Y' ) { 

		do {
			displayBoard( playerX, playerO );
			cout << "Player O your turn" << endl;
			makeMove( playerO );
			counter++;
			displayBoard( playerX, playerO );
			winner = checkForWinner( WINNER_X, WINNER_O );
	
			if ( !winner && counter < ROW*COL ) {
				cout << "Player X your turn" << endl;
				makeMove( playerX );
				counter++;
				winner = checkForWinner( WINNER_X, WINNER_O );
  				
			}

		} while ( !winner && counter < ROW*COL );	

		displayBoard( playerX, playerO );
		
		if ( winner == true && counter == 9 ) {
			cout << "You have a tie!" << endl;
		}
	}	
	else
		cout << "Okay you're no fun, bye!" << endl;
}

//function that the values of playerX and playerO are passed by reference to display the board and their marked positions
void displayBoard( int&playerX, int&playerO ) {
	
	for ( int r = 0; r < ROW; r++ ) {
		
		cout << "---------" << endl ;
		
		for ( int c = 0; c < COL; c++ ) {
								
			if ( board[r][c] == -2 ) {
				cout <<  "  |";
			}
			else if ( board[r][c] == playerO ) {
				cout <<  "O |";
			}
			else if ( board[r][c] == playerX ) {
				cout <<  "X |";
			}
			if ( c == 2 ) {
				cout << endl;
			} 
		}
	}
	cout << "---------" << endl;
}


// function that current player is passed to in order to mark which position on the board the player is marking
void makeMove( int player ) {

	int rowVal = -1;
	int colVal = -1;	
	bool full = false;

	do {
	
		cout << "What row?" << endl;
		cin >> rowVal;
	
		if ( rowVal-1 >= 0 && rowVal-1 < ROW ) {
			cout << "What column?" << endl;
			cin >> colVal;
		
			if ( colVal-1 >= 0 && colVal-1 < COL ) {
			
				if ( board[rowVal-1][colVal-1] == -2 ) {
					board[rowVal-1][colVal-1] = player;
					full = true;
				}	
				else {
					cout << "Try again!" << endl;
				}	
			}
		}	
	
	} while ( !full );

}

// function that checks to see if there is a winner by adding the values of the rows, columns, and diagonals
bool checkForWinner( int WINNER_X, int WINNER_O  ) {

	int sum = 0;
	bool win = false; 

	for ( int r = 0; r < ROW; r++ ) {
		sum = 0;
		
		for ( int c = 0; c < COL; c++ ) {
			sum += board[r][c];
		}
		if ( sum == WINNER_X ) {
			win = true;
			cout << "Congrats! Player X has won!" << endl;
		}
		else if ( sum == WINNER_O ) {
			win = true;
			cout << "Congrats! Player O has won!" << endl;
		}
	}

	for ( int r = 0; r < ROW; r++ ) {
		sum = 0;

		for ( int c = 0; c < COL; c++ ) {
			sum += board[c][r];
		}
		if ( sum == WINNER_X  ) {
			win = true;
			cout << "Congrats! Player X has won!" << endl;
		}
		else if ( sum == WINNER_O ) {
			win = true;
			cout << "Congrats! Player O has won!" << endl;
		}
	}

	sum = 0;
	for ( int r = 0; r < ROW; r++ ) {
		for ( int c = 0; c < COL; c++ ) {
            	if ( r == c ) {
					sum += board[r][c];
				}
		}
	
		if ( sum == WINNER_X  ) {
            	win = true;
            	cout << "Congrats! Player X has won!" << endl;
		}
		else if ( sum == WINNER_O ) {
            	win = true;
           	 	cout << "Congrats! Player O has won!" << endl;
		}
	}
	
	sum = 0;
	for ( int r = 0; r < ROW; r++ ) {
		for ( int c = 0; c < COL; c++ ) {
                if ( r + c == 2 ) {
        	    	sum += board[r][c];
			    }
		}
	
	 	if ( sum == WINNER_X  ) {
                win = true;
			    cout << "Congrats! Player X has won!" << endl;
        }        
        else if ( sum == WINNER_O ) {
             	win = true;
                cout << "Congrats! Player O has won!" << endl;
		}
	}

	return ( win );
}



