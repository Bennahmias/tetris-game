#ifndef _HUMAN_H
#define _HUMAN_H


#include "board.h"
class Human : public Board
{
public:

	Human(const Board & board) : Board(board) {}

	virtual void move(bool& cant_move, char ch, const int& bestRotation, const int& xTarget, int k)override;


};

#endif