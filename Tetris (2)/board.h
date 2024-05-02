#ifndef _BOARD_H
#define _BOARD_H

#include "shape.h"
#include "key_identifier.h"

class Board
{
private:
	Shape* currShape;
	int board[(int)matrix::ROW][(int)matrix::COL]; // will contain 0s and 1s

	int right_berier;
	int left_berier;
	int floor_berier;

	bool lostTheGame;
	int ID;


public: 
	Board(int _right_berier,int _left_berier,int _floor_berier,int id); //constructor
	void updateBoard();//update the prev board matrix with the new shape that got stuck
	bool canMove(int direction); //check if current shape can move
	void setCurrShape(Shape* curr);
	Shape* getCurrShape();
	int getLeftBerier()const; 
	int getID()const; //get the number of the board
	void printBorders()const; 
	void printBoard()const;
	bool canRotate(int direction)const; //check if a shape can rotate clockwise and counter clockwise
	void resetBoard(); //puts 0 in all the matrix 
	void removeARow(bool remove, int whatRow); //remove one row
	bool fullLineCheck(int& rowToRemove)const; //checks if one line in the matrix is full with 1's
	bool getLostTheGame()const;
	void setLostTheGame(bool flag);
	void DeleteCurrShape();

	void expload(); //update the board after a bomb exploded


	virtual void findTheBestpath(int& BestRotation, int& rightSteps); 
	virtual void move(bool& cant_move, char ch, const int& bestRotation, const int& xTarget,int k);
	virtual void setDifficultyLvl(char ch);
	virtual ~Board(){}

};



#endif