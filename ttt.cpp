#include <iostream>

void printBoard(int board[3][3], bool player1Turn, std::string player1token, std::string player2token);
int checkWin(int board[3][3]);
int sumRow(int row[3]);
int sumCol(int board[3][3], int column);
void phrasePyramid(std::string phrase);

int main() {
	bool player1Turn = true;
	std::string player1token;
	std::string player2token;
	int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int row, col, result = 0;
	std::cout << "Player 1, enter a symbol to represent your token" << std::endl;
	std::cin >> player1token;
	std::cout << "Player 2, enter a symbol to represent your token" << std::endl;
	std::cin >> player2token;
	while(checkWin(board) == 0) {
		printBoard(board, player1Turn, player1token, player2token);
		std::cout << "Enter a row and a column: ";
		std::cin >> row >> col;
		
		while(board[row-1][col-1] != 0) {
			std::cout <<"Enter a valid, empty row and column choice: ";
			std::cin >> row >> col;
		}
		
		board[row-1][col-1] = player1Turn ? 1 : -1;
		//Switch players
		player1Turn = !player1Turn;
	}

	printBoard(board, player1Turn, player1token, player2token);

	std::cout << std::endl << "Player " ;
	if (checkWin(board) == 1){
		phrasePyramid("1 won!");
	}else {
		phrasePyramid("2 won!");
	}
  std::cout << "Lol you lost. GIT gud you scrub";

	return 0;
}

void printBoard(int board[3][3], bool player1Turn, std::string player1token, std::string player2token) {
	if(player1Turn) {
		std::cout << "Player 1's Turn" << std::endl;
	} else {
		std::cout << "Player 2's Turn" << std::endl;
	}
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			switch(board[i][j]) {
				case 0:
					std::cout << "   ";
					break;
				case 1:
					std::cout << " " << player1token << " ";
					break;
				case -1:
					std::cout << " " << player2token << " ";
					break;
			}
		}
		std::cout << std::endl;
	}
}

int checkWin(int board[3][3]) {
	int result = 0;
	
	
	//Check rows and cols for wins
	for(int i = 0; i < 3; i++) {
		int rowSum = sumRow(board[i]), colSum = sumCol(board, i);
		if(rowSum > 2 || colSum > 2) {
			result = 1;
		} else if(rowSum < -2 || colSum < -2) {
			result = -1;
		}
	}
	
	//Check diagonals for wins
	int diagTop = board[0][0] + board[1][1] + board[2][2],
		diagBot = board[2][0] + board[1][1] + board[0][2];
			
	if(diagTop > 2 || diagBot > 2) {
		result = 1;
	} else if(diagTop < -2 || diagBot < -2) {
		result = -1;
	}
	
	return result;
}

int sumRow(int row[3]) {
	return row[0] + row[1] + row[2];
}

int sumCol(int board[3][3], int column) {
	return board[0][column] + board[1][column] + board[2][column];
}

void phrasePyramid(std::string phrase) {
	std::string output;
	for(int i = 0; i < phrase.size(); i++) {
		output += phrase[i];
		std::cout << output << std::endl;
	}
	for(int i = phrase.size() - 1; i >= 0; i--) {
		output.erase(i);
		std::cout << output << std::endl;
	}
}