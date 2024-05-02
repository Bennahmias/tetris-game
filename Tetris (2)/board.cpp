#include "board.h"
#include<iostream>
#include"general.h"


Board::Board(int _right_berier, int _left_berier, int _floor_berier, int id) : board{ 0 }
{
	currShape = nullptr;

	ID = id;
	right_berier = _right_berier;
	left_berier = _left_berier;
	floor_berier = _floor_berier;
	lostTheGame = false;

}

bool Board::getLostTheGame() const
{
	return lostTheGame;
}

void Board::setLostTheGame(bool flag)
{
	lostTheGame = flag;
}

void Board::updateBoard()
{
	if (currShape != nullptr)
	{
		const Point* arr = currShape->getData();

		for (int i = 0; i < (int)gameOption::SHAPE_SIZE; i++)
		{
			board[arr[i].getPoint_Y()][arr[i].getPoint_X()] = 1;
		}
	}
}

	void Board::expload()
	{
		const int x = (this->getCurrShape()->getData())[0].getPoint_X();
		const int y = (this->getCurrShape()->getData())[0].getPoint_Y();

		int startY = y - 4;
		int endY = y + 4;
		int startX = x - 4;
		int endX = x + 4;

		if (startY < 0) startY = 0;
		if (endY >= (int)matrix::ROW) endY = (int)matrix::ROW - 1;
		if (startX < 0) startX = 0;
		if (endX >= (int)matrix::COL) endX = (int)matrix::COL - 1;

		for (int i = startY; i <= endY; ++i) {
			for (int j = startX; j <= endX; ++j) {
				board[i][j] = 0;
			}
		}

	}


	bool Board::canMove(int direction)
	{
		const Point* arr = currShape->getData();

		switch (direction)
		{
		case (int)charkeys::RIGHT:

			for (int i = 0; i < (int)gameOption::SHAPE_SIZE; i++)
			{
				if ((arr[i].getPoint_X() + 1 == (int)borders::LEFT_BORDER) ||
					(this->board[arr[i].getPoint_Y()][arr[i].getPoint_X() + 1] == 1)) //hit berier or another obj
					return false;
			}
			return true;

		case (int)charkeys::LEFT:

			for (int i = 0; i < (int)gameOption::SHAPE_SIZE; i++)
			{
				if ((arr[i].getPoint_X() - 1 == (int)borders::RIGHT_BORDER) ||
					(this->board[arr[i].getPoint_Y()][arr[i].getPoint_X() - 1] == 1))//hit berier or another obj
					return false;
			}
			return true;

		case (int)charkeys::DOWN:

			for (int i = 0; i < (int)gameOption::SHAPE_SIZE; i++)
			{
				if ((arr[i].getPoint_Y() + 1 == (int)borders::FLOOR_BORDER) ||
					(this->board[arr[i].getPoint_Y() + 1][arr[i].getPoint_X()] == 1))//hit the floor or another obj

				{
					if (board[0][arr[i].getPoint_X()] == 1)
					{
						lostTheGame = true; //update that the player reach the cieling
					}
					return false;
				}

			}
			return true;

		default: //probebly will not happen ever 
			return false;

		}
	}

	void Board::setCurrShape(Shape * curr)
	{
		currShape = curr;
	}

	void Board::printBorders()const
	{

		// Print top border
		for (int col = left_berier; col <= right_berier; col++)
		{
			gotoxy(col, floor_berier);
			std::cout << "-";

		}

		// Print side borders
		for (int row = 0; row <= floor_berier; row++)
		{
			gotoxy(left_berier - 1, row + 1);
			std::cout << "|";

			gotoxy(right_berier - 1, row + 1);
			std::cout << "|";
		}


		// Print top border
		for (int col = left_berier; col <= right_berier; col++)
		{
			gotoxy(col, floor_berier);
			std::cout << "=";

		}


		for (int row = 0; row <= floor_berier; row++)
		{
			// Left border
			gotoxy(left_berier - 1, row + 1);
			std::cout << "|";

			// Right border
			gotoxy(right_berier - 1, row + 1);
			std::cout << "|";

			// left side
			gotoxy(left_berier - 3, row + 1);
			std::cout << "<(";

			// right side
			gotoxy(right_berier, row + 1);
			std::cout << ")>";
		}



	}

	Shape* Board::getCurrShape()
	{
		return currShape;
	}

	int Board::getLeftBerier()const
	{
		return left_berier;
	}

	int Board::getID()const
	{
		return ID;
	}

	bool Board::canRotate(int direction)const
	{
		Shape tempShape(*currShape);

		if (direction == (int)charkeys::CLOCKWISE)
			tempShape.rotate((int)charkeys::CLOCKWISE);  // Rotate the temporary shape
		if (direction == (int)charkeys::COUNTERCLOCKWISE)
			tempShape.rotate((int)charkeys::COUNTERCLOCKWISE);

		for (int i = 0; i < (int)gameOption::SHAPE_SIZE; ++i) {
			int newX = tempShape.getData()[i].getPoint_X();
			int newY = tempShape.getData()[i].getPoint_Y();

			// Check if touch the board borders
			if (newX < 0 || newX >= 12 || newY < 0 || newY >= 18) {
				return false;  // Collision with borders, rotation not allowed
			}

			// Check if touch the block
			if (board[newY][newX] == 1) {
				return false;  // Collision with existing block, rotation not allowed
			}
		}

		return true;  // Rotation is allowed
	}

	//reset board to zoreos
	void Board::resetBoard()
	{
		for (int i = 0; i < (int)matrix::ROW; ++i)
		{
			for (int j = 0; j < (int)matrix::COL; ++j)
			{
				board[i][j] = 0;
			}
		}
	}

	void Board::removeARow(bool remove, int whatRow)
	{
		if (!remove) //if I dont need to remove the row, dont..
			return;

		for (int i = whatRow; i > 0; i--) // dont overstep the matrix 
		{
			for (int j = 0; j < (int)matrix::COL; j++)
			{
				board[i][j] = board[i - 1][j];
			}
		}
		for (int i = 0; i < (int)matrix::COL; i++) //update the first row
			board[0][i] = 0;

	}

	bool Board::fullLineCheck(int& rowToRemove)const
	{
		for (int i = 0; i < (int)matrix::ROW; i++)
		{
			bool flag = true;

			for (int k = 0; k < (int)matrix::COL; k++)
				if (board[i][k] != 1)
				{
					flag = false; //this row is not the one to delete.
					break;
				}

			if (flag == true)//if we found one to delete
			{
				rowToRemove = i; //update the row to remove 
				return true;
			}
		}

		return false; //if there is no one to remove.
	}

	void Board::printBoard()const
	{

		for (int i = 0; i < (int)matrix::ROW; ++i)
		{
			for (int j = 0; j < (int)matrix::COL; ++j)
			{
				gotoxy(j + (this->getLeftBerier()), i);

				if (board[i][j] == 0)
				{
					std::cout << " ";
				}
				else
					std::cout << "#";
			}
		}
	}

	void Board::DeleteCurrShape()
	{
		const Point* arr = currShape->getData();

		for (int i = 0; i < (int)gameOption::SHAPE_SIZE; i++)
		{
			board[arr[i].getPoint_Y()][arr[i].getPoint_X()] = 0;
		}

	}

	void Board::findTheBestpath(int& BestRotation, int& rightSteps) {}


	void Board::move(bool& cant_move, char ch, const int& bestRotation, const int& xTarget, int k) {}
	void Board::setDifficultyLvl(char ch) {}
