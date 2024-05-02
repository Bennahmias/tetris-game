#ifndef _GAME_H
#define _GAME_H
#include "board.h"

class Game
{
private:
	Shape L_Shape;
	Shape S_Shape;
	Shape PLUS_Shape;
	Shape O_Shape;
	Shape Z_Shape;
	Shape J_Shape;
	Shape I_Shape;
	Shape Bomb_Shape;

	bool someoneWon;
	bool endGame;


	Board* boards[(int)gameOption::NUM_OF_BOARDS]; 
	char key1[5] = { 'a','d','s','x','w' };
	char key2[5]= { 'j','l','k','m','i' };
	
public: 

	Game();
	Shape GenerateNewShape()const; //select a random shape and get a copy of it
	void start(); //more details inside the function
	void presentTheKeys()const; //print the keys options to the player
	void menu(int whichGame);//open the menu and the player will decide which option to select

	void printMenuWithPause()const; 
	void printMenuWithoutPause()const;
	void goDown(Board& currBoard, bool& cant_move);
	bool getGameStatus()const; // return true if the player wanted to quit the game
	int  whatPlayer(char ch)const; //check which player got the correct key
	void checkAndUpdateIfSomeoneLost(); 
	void PrintEndGame(int whichBoard)const;
	void printCountDown()const;
	void printBordersForSomeBoards(int numOfBoards)const;
	void printSomeBoards(int numOfBoards)const;
	void playerChoice(char choice); 
	void resetBoards();
	void whatDifficulty(Board* b0,int i);
	void whatDifficulty(Board* b0,Board*b1);

};


#endif


