#include "human.h"

void Human::move(bool& cant_move, char ch, const int& bestRotation, const int& xTarget, int k)
{
	

	//im board 1
	if (getID() == (int)gameOption::BOARD1)
	{

		switch (ch)
		{
		case 'a':
			if (canMove((int)charkeys::LEFT))
			{
				getCurrShape()->move((int)charkeys::LEFT);
			}
			break;


		case 'd':
			if (canMove((int)charkeys::RIGHT))
			{
				getCurrShape()->move((int)charkeys::RIGHT);
			}
			break;

		case 'x':

			for (int i = 0; i < 18; i++)
			{
				if (canMove((int)charkeys::DOWN))
				{
					getCurrShape()->move((int)charkeys::DOWN);
				}
			}
			cant_move = true;

			break;

		case 's':
			if (canRotate((int)charkeys::CLOCKWISE))
			{
				getCurrShape()->rotate((int)charkeys::CLOCKWISE);
			}
			break;

		case 'w':
			if (canRotate((int)charkeys::COUNTERCLOCKWISE))
			{
				getCurrShape()->rotate((int)charkeys::COUNTERCLOCKWISE);
			}
			break;

		default:
			break;
		}
	}

	else //im on board 2 
	{
		switch (ch)
		{

		case 'j':
			if (canMove((int)charkeys::LEFT))
			{
				getCurrShape()->move((int)charkeys::LEFT);
			}
			break;

		case 'l':
			if (canMove((int)charkeys::RIGHT))
			{
				getCurrShape()->move((int)charkeys::RIGHT);
			}
			break;

		case 'm':
			for (int i = 0; i < 18; i++)
			{
				if (canMove((int)charkeys::DOWN))
				{
					getCurrShape()->move((int)charkeys::DOWN);
				}
			}
			cant_move = true;

			break;

		case 'k':
			if (canRotate((int)charkeys::CLOCKWISE))
			{
				getCurrShape()->rotate((int)charkeys::CLOCKWISE);
			}
			break;

		case 'i':
			if (canRotate((int)charkeys::COUNTERCLOCKWISE))
			{
				getCurrShape()->rotate((int)charkeys::COUNTERCLOCKWISE);
			}
			break;

		default:
			break;

		}
	}


}
