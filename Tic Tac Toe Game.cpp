#include <iostream>
using namespace std;

char gameBoardGridNumber[10] = { 'o','1','2','3','4','5','6','7','8','9' };
// char 'o' is a dummy char so that gameBoardGridNumber[n] = n

int checkIfAnyPlayerMeetsWinningCriteria();
void drawGameBoardAtConsole();

/*******************************************************************
	 FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS LEGEND
********************************************************************/

void drawGameBoardAtConsole()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << gameBoardGridNumber[1] << "  |  " << gameBoardGridNumber[2] << "  |  " << gameBoardGridNumber[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameBoardGridNumber[4] << "  |  " << gameBoardGridNumber[5] << "  |  " << gameBoardGridNumber[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameBoardGridNumber[7] << "  |  " << gameBoardGridNumber[8] << "  |  " << gameBoardGridNumber[9] << endl;

	cout << "     |     |     " << endl << endl;
}

/*********************************************
	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT (GAME DRAW)
**********************************************/

int checkIfAnyPlayerMeetsWinningCriteria()
{
	if (gameBoardGridNumber[1] == gameBoardGridNumber[2] && gameBoardGridNumber[2] == gameBoardGridNumber[3])

		return 1;
	else if (gameBoardGridNumber[4] == gameBoardGridNumber[5] && gameBoardGridNumber[5] == gameBoardGridNumber[6])

		return 1;
	else if (gameBoardGridNumber[7] == gameBoardGridNumber[8] && gameBoardGridNumber[8] == gameBoardGridNumber[9])

		return 1;
	else if (gameBoardGridNumber[1] == gameBoardGridNumber[4] && gameBoardGridNumber[4] == gameBoardGridNumber[7])

		return 1;
	else if (gameBoardGridNumber[2] == gameBoardGridNumber[5] && gameBoardGridNumber[5] == gameBoardGridNumber[8])

		return 1;
	else if (gameBoardGridNumber[3] == gameBoardGridNumber[6] && gameBoardGridNumber[6] == gameBoardGridNumber[9])

		return 1;
	else if (gameBoardGridNumber[1] == gameBoardGridNumber[5] && gameBoardGridNumber[5] == gameBoardGridNumber[9])

		return 1;
	else if (gameBoardGridNumber[3] == gameBoardGridNumber[5] && gameBoardGridNumber[5] == gameBoardGridNumber[7])

		return 1;
	else if (gameBoardGridNumber[1] != '1' && gameBoardGridNumber[2] != '2' && gameBoardGridNumber[3] != '3'
		&& gameBoardGridNumber[4] != '4' && gameBoardGridNumber[5] != '5' && gameBoardGridNumber[6] != '6'
		&& gameBoardGridNumber[7] != '7' && gameBoardGridNumber[8] != '8' && gameBoardGridNumber[9] != '9')

		return 0;
	else
		return -1;
}

int main()
{
	int indexPlayer = 1, winningCriteriaBit, whereToPlaceChess;

	char placeChess;

	do
	{
		drawGameBoardAtConsole();
		indexPlayer = (indexPlayer % 2) ? 1 : 2; // player is aucillating with either 1 or 2

		cout << "Player " << indexPlayer << ", enter a number:  ";
		cin >> whereToPlaceChess;

		placeChess = (indexPlayer == 1) ? 'X' : 'O';

		if (whereToPlaceChess == 1 && gameBoardGridNumber[1] == '1')

			gameBoardGridNumber[1] = placeChess;
		else if (whereToPlaceChess == 2 && gameBoardGridNumber[2] == '2')

			gameBoardGridNumber[2] = placeChess;
		else if (whereToPlaceChess == 3 && gameBoardGridNumber[3] == '3')

			gameBoardGridNumber[3] = placeChess;
		else if (whereToPlaceChess == 4 && gameBoardGridNumber[4] == '4')

			gameBoardGridNumber[4] = placeChess;
		else if (whereToPlaceChess == 5 && gameBoardGridNumber[5] == '5')

			gameBoardGridNumber[5] = placeChess;
		else if (whereToPlaceChess == 6 && gameBoardGridNumber[6] == '6')

			gameBoardGridNumber[6] = placeChess;
		else if (whereToPlaceChess == 7 && gameBoardGridNumber[7] == '7')

			gameBoardGridNumber[7] = placeChess;
		else if (whereToPlaceChess == 8 && gameBoardGridNumber[8] == '8')

			gameBoardGridNumber[8] = placeChess;
		else if (whereToPlaceChess == 9 && gameBoardGridNumber[9] == '9')

			gameBoardGridNumber[9] = placeChess;
		else
		{
			cout << "Invalid move";
			//system("pause");
			indexPlayer--; // post-decrement returns value BEFORE calculation
			cin.ignore();
			cin.get();
		}

		winningCriteriaBit = checkIfAnyPlayerMeetsWinningCriteria();
		indexPlayer++;
	} while (winningCriteriaBit == -1);

	drawGameBoardAtConsole();
	if (winningCriteriaBit == 1)
		cout << "==>\aPlayer " << --indexPlayer << " win "; // \a is an alarm
		// pre-decrement returns value AFTER calculation
	else
		cout << "==>\aGame draw";

	cin.ignore();
	cin.get();
}