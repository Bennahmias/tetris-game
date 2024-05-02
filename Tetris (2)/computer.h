#ifndef _COMPUTER_H
#define _COMPUTER_H
#include "key_identifier.h"
#include "board.h"

class Computer :public Board
{
private:
	char difficultyLvl=(char)(difficulty::GOOD);
public:
	Computer(const Board & board) : Board(board) {} //constractor

	virtual void findTheBestpath(int& BestRotation, int& xTarget); //algorithm to find the best position
	virtual void move(bool& cant_move, char ch, const int& bestRotation, const int& xTarget, int k)override;
	void moveTheShape(const int& BestRotation, const int& xTarget, bool& cant_move,int k);
	virtual void setDifficultyLvl(char ch)override;
	char getDifficultyLvl()const;
	


};

#endif