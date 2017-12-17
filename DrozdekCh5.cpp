/* Backtracking Recursion: nxn-Chessboard-Queen problem */

#include <iostream>
using namespace std;

class ChessBoard {

public:

	ChessBoard(int);
	void findSolutions();

private:

	const bool available;
	const int squares, norm;
	bool *column, *leftDiagonal, *rightDiagonal;
	int *positionInRow, howMany;
	void putQueen(int);
	void initializeBoard();
	void PrintSolutions();
};

ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(n - 1) {

	initializeBoard();

}

void ChessBoard::initializeBoard() {

	register int i;
	column = new bool[squares];
	positionInRow = new int[squares];
	leftDiagonal = new bool[2 * squares - 1];
	rightDiagonal = new bool[2 * squares - 1];

	for (i = 0; i < squares; i++) {

		positionInRow[i] = -1;
		column[i] = available;
	}

	for (i = 0; i < 2 * squares - 1; i++) {

		leftDiagonal[i] = available;
		rightDiagonal[i] = available;
	}

	howMany = 0;
}

void ChessBoard::PrintSolutions() {

	cout << "Solution (row, column)" << endl;

	for (int k = 0; k < squares; k++) {

		cout << "(" << k << "," << positionInRow[k] << ")" << endl;
	}

}

void ChessBoard::putQueen(int row) {

	for (int col = 0; col < squares; col++) {

		if ((column[col] == available) &&
			(leftDiagonal[row + col] == available) &&
			(rightDiagonal[row - col + norm] == available)) {

			positionInRow[row] = col;
			column[col] = !available;
			leftDiagonal[row + col] = !available;
			rightDiagonal[row - col + norm] = !available;

			if (row < squares - 1) {
				putQueen(row + 1);
			}

			else {
				PrintSolutions();
				howMany++;
			};

			column[col] = available;
			leftDiagonal[row + col] = available;
			rightDiagonal[row - col + norm] = available;
		}
	}
}

void ChessBoard::findSolutions() {

	putQueen(0);
	cout << howMany << " solutions found" << endl;
}

int main() {

	ChessBoard CH(8);
	CH.findSolutions();

	system("pause");
	return 0;
}