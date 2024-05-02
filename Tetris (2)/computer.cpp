#include "computer.h"
#include "human.h"
#include "Windows.h"



void Computer::findTheBestpath(int& BestRotation, int& xTarget)
{
	
	if (rand() % (int)gameOption::NOVICE_RAND == 1 && getDifficultyLvl() == (char)difficulty::NOVICE)
	{
		xTarget = rand() % (int)matrix::COL;
	}
	else if (rand() % (int)gameOption::GOOD_RAND == 1 && getDifficultyLvl() == (char)difficulty::GOOD)
	{
		xTarget = rand() % (int)matrix::COL;
	}
	else
	{
		int  maxWieght = 0, temp1;
		bool DeletedARow = false, temp;

		Shape originalCopy(*(this->getCurrShape())); //get copy of the original shape


		if (!(canMove((int)charkeys::DOWN)))
		{
			xTarget = (this->getCurrShape()->getData())[0].getPoint_X();
			return; //lost the game, it has already updated the bool.
		}

		for (int rot = -1; rot < 3 && DeletedARow != true; ++rot) //loop for all the 4 rotation option
		{
			this->getCurrShape()->setData(originalCopy.getData()); //set the original shape
			this->getCurrShape()->setRotation(rot); //set the current rotation

			bool badRotation = false;

			while (!(canRotate((int)charkeys::CLOCKWISE)))
			{
				if (canMove((int)charkeys::DOWN))
					this->getCurrShape()->move((int)charkeys::DOWN);
				else
				{
					badRotation = true;
					break;
				}
			}

			if (!badRotation) //this rotation is not good. skip it 
			{
				//this->getCurrShape()->setRotation(rot); //set the current rotation
				this->getCurrShape()->rotate((int)charkeys::CLOCKWISE); //rotate
				Shape rotCopy(*(this->getCurrShape())); //copy of the rotation shape
				for (int steps = 0; steps < (int)matrix::COL; ++steps)
				{
					this->getCurrShape()->setData(rotCopy.getData());
					for (int i = 0; i < 10; ++i) //stick to the left border
					{
						if (this->canMove((int)charkeys::LEFT))
							this->getCurrShape()->move((int)charkeys::LEFT);
					}
					for (int k = 0; k < steps; ++k)//move right until steps (the current col)
					{
						if (this->canMove((int)charkeys::RIGHT))
							this->getCurrShape()->move((int)charkeys::RIGHT);
					}
					for (int j = 0; j < 18; j++)//go down to the floor border 
					{
						if (this->canMove((int)charkeys::DOWN))
							this->getCurrShape()->move((int)charkeys::DOWN);
					}

					this->updateBoard();
					

					if (this->fullLineCheck(temp1)) //this is the best option so go out
					{
						this->DeleteCurrShape();

						xTarget = (this->getCurrShape()->getData())[0].getPoint_X();
						BestRotation = this->getCurrShape()->getRotation();
						this->getCurrShape()->setData(originalCopy.getData());
						DeletedARow = true;
						break;

					}
					//sum the sum 'y' coordinates of the shape and the best position is the biggest weight
					int weight = this->getCurrShape()->getWeight();

					if (maxWieght < weight)
					{
						maxWieght = weight;
						xTarget = (this->getCurrShape()->getData())[0].getPoint_X();
						BestRotation = this->getCurrShape()->getRotation();

					}
					this->DeleteCurrShape();
				}
			}
			this->getCurrShape()->setData(originalCopy.getData());
			this->getCurrShape()->setRotation(0);
		}
	}

	
}

void Computer::moveTheShape(const int& BestRotation, const int& xTarget, bool& cant_move, int tic)
{
	if (tic != 9)
		return; //this makes sure that the computer does not play more than 1 move at a time. 

	if (!(getCurrShape()->getRotation() == BestRotation))
	{
		if (!canRotate((int)charkeys::CLOCKWISE))
		{
			if (canMove((int)charkeys::DOWN))
			{
				getCurrShape()->move((int)charkeys::DOWN);
			}
			else
				cant_move = true;
		}
		else
		{
			for (int i = 0; i < BestRotation; i++)
			{

			getCurrShape()->rotate((int)charkeys::CLOCKWISE);
			}
		}
	}
	else
	{
		//move the shape

		if ((getCurrShape()->getData())[0].getPoint_X() > xTarget)
		{
			if (canMove((int)charkeys::LEFT))
			{
				getCurrShape()->move((int)charkeys::LEFT);
			}
			//else do nothing
		}

		else if ((getCurrShape()->getData())[0].getPoint_X() < xTarget)
		{
			if (canMove((int)charkeys::RIGHT))
			{
				getCurrShape()->move((int)charkeys::RIGHT);
			}
			//else do nothing
		}
		else //IM IN THE RIGHT SPOT!
		{
			for (int i = 0; i < 18; i++)
			{
				if (canMove((int)charkeys::DOWN))
				{
					getCurrShape()->move((int)charkeys::DOWN);
				}
			}
			cant_move = true;
		}
	}
}


void Computer::move(bool& cant_move, char ch, const int& bestRotation, const int& xTarget, int tic)
{
	this->moveTheShape(bestRotation, xTarget, cant_move,tic);
}

void Computer::setDifficultyLvl(char ch)
{
	difficultyLvl = ch;
}


char Computer::getDifficultyLvl()const
{
	return difficultyLvl;
}
