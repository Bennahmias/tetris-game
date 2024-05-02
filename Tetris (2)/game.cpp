#include "game.h"
#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<Windows.h>
#include "general.h"
#include <conio.h>
#include "human.h"
#include "computer.h"


// base of the different shapes, according to the first board.
Point sShape[(int)gameOption::SHAPE_SIZE] = { Point(5,1),Point(6,0),Point(7,0) ,Point(6,1) };
Point plusShape[(int)gameOption::SHAPE_SIZE] = { Point(5,1),Point(6,0),Point(7,1),Point(6,1) };
Point lShape[(int)gameOption::SHAPE_SIZE] = { Point(5,1),Point(6,0),Point(7,0),Point(5,0) };
Point iShape[(int)gameOption::SHAPE_SIZE] = { Point(4,0),Point(6,0),Point(7,0) ,Point(5,0) };
Point zShape[(int)gameOption::SHAPE_SIZE] = { Point(5,0),Point(6,0),Point(7,1),Point(6,1) };
Point jShape[(int)gameOption::SHAPE_SIZE] = { Point(5,0),Point(6,0),Point(7,1),Point(7,0) };
Point oShape[(int)gameOption::SHAPE_SIZE] = { Point(6,0),Point(5,1),Point(6,1),Point(5,0) };
Point bombShape[(int)gameOption::SHAPE_SIZE] = { Point(6,0),Point(6,0),Point(6,0),Point(6,0) };



Board board0(33, 20, 18, (int)gameOption::BOARD1);
Board board1(53, 40, 18, (int)gameOption::BOARD2);

Game::Game() :boards{ &board0, &board1 }
{

	L_Shape.setData(lShape);
	L_Shape.setType((int)shapeTypes::L_SHAPE);

	S_Shape.setData(sShape);
	S_Shape.setType((int)shapeTypes::S_SHAPE);

	PLUS_Shape.setData(plusShape);
	PLUS_Shape.setType((int)shapeTypes::PLUS_SHAPE);

	O_Shape.setData(oShape);
	O_Shape.setType((int)shapeTypes::O_SHAPE);

	Z_Shape.setData(zShape);
	Z_Shape.setType((int)shapeTypes::Z_SHAPE);

	J_Shape.setData(jShape);
	J_Shape.setType((int)shapeTypes::J_SHAPE);

	I_Shape.setData(iShape);
	I_Shape.setType((int)shapeTypes::I_SHAPE);

	Bomb_Shape.setData(bombShape);
	Bomb_Shape.setType((int)shapeTypes::BOMB_SHAPE);

	someoneWon = false;
	endGame = false;

	srand(static_cast<unsigned>(time(nullptr)));//in order for rand to be reall random 

}

bool Game::getGameStatus()const
{
	return endGame;
}

Shape Game::GenerateNewShape()const
{
	switch (rand()% (int)gameOption::BOMB_CAHNCE) // 5% chance, bomb is selected
	{
	case 1:
		return Bomb_Shape;

	default:
		break;
	}

	switch (rand() % (int)gameOption::NUM_OF_SHAPES) //random between 7 shapes
	{
	case (int)shapeTypes::S_SHAPE:
		return S_Shape;

		break;
	case (int)shapeTypes::PLUS_SHAPE:
		return PLUS_Shape;

	case (int)shapeTypes::Z_SHAPE:
		return Z_Shape;

	case (int)shapeTypes::I_SHAPE:
		return I_Shape;

	case (int)shapeTypes::J_SHAPE:
		return J_Shape;

	case (int)shapeTypes::L_SHAPE:
		return L_Shape;

	case (int)shapeTypes::O_SHAPE:
		return O_Shape;
	}
	return S_Shape;  //if something went wrong in rand, just generate S (prob wont happend)
}

void Game::printCountDown()const
{
	std::cout << " $$$$$$\\  $$$$$$$\\  $$$$$$$$\\       $$\\     $$\\  $$$$$$\\  $$\\   $$\\ " << std::endl;
	std::cout << "$$  __$$\\ $$  __$$\\ $$  _____|      \\$$\\   $$  |$$  __$$\\ $$ |  $$ |" << std::endl;
	std::cout << "$$ /  $$ |$$ |  $$ |$$ |             \\$$\\ $$  / $$ /  $$ |$$ |  $$ |" << std::endl;
	std::cout << "$$$$$$$$ |$$$$$$$  |$$$$$\\            \\$$$$  /  $$ |  $$ |$$ |  $$ |" << std::endl;
	std::cout << "$$  __$$ |$$  __$$< $$  __|            \\$$  /   $$ |  $$ |$$ |  $$ |" << std::endl;
	std::cout << "$$ |  $$ |$$ |  $$ |$$ |                $$ |    $$ |  $$ |$$ |  $$ |" << std::endl;
	std::cout << "$$ |  $$ |$$ |  $$ |$$$$$$$$\\           $$ |     $$$$$$  |\\$$$$$$  |" << std::endl;
	std::cout << "\\__|  \\__|\\__|  \\__|\\________|          \\__|     \\______/  \\______/ " << std::endl;
	std::cout << "                                                                    " << std::endl;
	std::cout << "                                                                    " << std::endl;
	std::cout << "                                                                    " << std::endl;
	std::cout << "      $$$$$$$$\\  $$$$$$$$\\  $$$$$$\\  $$$$$$$\\  $$\\     $$\\  $$$$\\    " << std::endl;
	std::cout << "      $$  __$$\\ $$  _____|$$  __$$\\ $$  __$$\\ \\$$\\   $$  |$$  $$\\   " << std::endl;
	std::cout << "      $$ |  $$ |$$ |      $$ /  $$ |$$ |  $$ | \\$$\\ $$  / \\__/$$ |  " << std::endl;
	std::cout << "      $$$$$$$  |$$$$$\\    $$$$$$$$ |$$ |  $$ |  \\$$$$  /     $$  |  " << std::endl;
	std::cout << "      $$  __$$< $$  __|   $$  __$$ |$$ |  $$ |   \\$$  /     $$  /   " << std::endl;
	std::cout << "      $$ |  $$ |$$ |      $$ |  $$ |$$ |  $$ |    $$ |      \\__/    " << std::endl;
	std::cout << "      $$ |  $$ |$$$$$$$$\\ $$ |  $$ |$$$$$$$  |    $$ |      $$\\     " << std::endl;
	std::cout << "      \\__|  \\__|\\________|\\__|  \\__|\\_______/     \\__|      \\__|    " << std::endl;
	Sleep(800);
	clear_screen();

	std::cout << " $$$$$$\\  " << std::endl;
	std::cout << "$$ ___$$\\ " << std::endl;
	std::cout << "\\_/   $$ |" << std::endl;
	std::cout << "  $$$$$ / " << std::endl;
	std::cout << "  \\___$$\\ " << std::endl;
	std::cout << "$$\\   $$ |" << std::endl;
	std::cout << "\\$$$$$$  |" << std::endl;
	std::cout << " \\______/ " << std::endl;

	Sleep(600);
	clear_screen();

	std::cout << " $$$$$$\\  " << std::endl;
	std::cout << "$$  __$$\\ " << std::endl;
	std::cout << "\\__/  $$ |" << std::endl;
	std::cout << " $$$$$$  |" << std::endl;
	std::cout << "$$  ____/ " << std::endl;
	std::cout << "$$ |      " << std::endl;
	std::cout << "$$$$$$$$\\ " << std::endl;
	std::cout << "\\________|" << std::endl;

	Sleep(600);
	clear_screen();

	std::cout << "  $$\\   " << std::endl;
	std::cout << "$$$$ |  " << std::endl;
	std::cout << "\\_$$ |  " << std::endl;
	std::cout << "  $$ |  " << std::endl;
	std::cout << "  $$ |  " << std::endl;
	std::cout << "  $$ |  " << std::endl;
	std::cout << "$$$$$$\\ " << std::endl;
	std::cout << "\\______|" << std::endl;

	Sleep(600);
	clear_screen();
}

void Game::printBordersForSomeBoards(int numOfBoards)const
{
	for (int i = 0; i < numOfBoards; i++)
	{
		boards[i]->printBorders();
	}
}

void Game::printSomeBoards(int numOfBoards)const
{
	for (int i = 0; i < numOfBoards; i++)
	{
		boards[i]->printBoard();
	}
}

void Game::start()
{

	bool isPlaying[(int)gameOption::NUM_OF_BOARDS] = { false };
	Shape shapes[(int)gameOption::NUM_OF_BOARDS];
	bool cant_move[(int)gameOption::NUM_OF_BOARDS] = { false };
	char ch = (int)charkeys::NO_CHAR;
	bool remove = false;
	int whatRow, bestRotation[2] = { 0 }, xTarget[2] = { 0 };

	printCountDown();
	printBordersForSomeBoards((int)gameOption::NUM_OF_BOARDS);


	//play until one player lost or click '9' (escape the game)
	while (!endGame && !boards[0]->getLostTheGame() && !boards[1]->getLostTheGame())
	{
		for (int i = 0; i < (int)gameOption::NUM_OF_BOARDS; i++) //check if player is playing and than create new shape from top
		{
			if (!isPlaying[i])
			{
				shapes[i] = GenerateNewShape();
				boards[i]->setCurrShape(&(shapes[i]));
				isPlaying[i] = !isPlaying[i]; //  (true<=>false)

				boards[i]->findTheBestpath(bestRotation[i], xTarget[i]);

			}
		}

		for (int k = 0; k < 10; k++) //let the player click more than one key
		{
			if (_kbhit())//check if player click on a key
			{
				ch = _getch();
				if (ch == (int)charkeys::ESC) //go to the menu
				{
					this->menu((int)gameOption::MIDDLEGAME); //menu of a middle game is with option 2 (continue a paused game)
					if (endGame == true) //if the player click '9' go out 
						return;
					else if (boards[0]->getLostTheGame() || boards[1]->getLostTheGame()) //check if someone already lost the game 
						return;

					printBordersForSomeBoards((int)gameOption::NUM_OF_BOARDS);
					printSomeBoards((int)gameOption::NUM_OF_BOARDS);

				}

			}
			
			shapes[0].del_draw(boards[0]->getLeftBerier()); //delete the current
			boards[0]->move(cant_move[0], tolower(ch), bestRotation[0], xTarget[0], k);
			shapes[0].draw(boards[0]->getLeftBerier()); //print it

			shapes[1].del_draw(boards[1]->getLeftBerier()); //delete the current
			boards[1]->move(cant_move[1], tolower(ch), bestRotation[1], xTarget[1], k);
			shapes[1].draw(boards[1]->getLeftBerier()); //print it
			ch = (int)charkeys::NO_CHAR;

		}
		Sleep(5);

		for (int i = 0; (i < (int)gameOption::NUM_OF_BOARDS) && (!endGame); i++)
		{

			shapes[i].del_draw(boards[i]->getLeftBerier());
			goDown(*boards[i], cant_move[i]);
			shapes[i].draw(boards[i]->getLeftBerier());

			if (cant_move[i]) //check if the player cant move 
			{
				isPlaying[i] = false;
				cant_move[i] = false;

				remove = true;
				
				if (boards[i]->getCurrShape()->getType() == (int)shapeTypes::BOMB_SHAPE)
					boards[i]->expload(); 
				
				else
					boards[i]->updateBoard();

				while (remove) //will happend as many times as needed to delete rows. 
				{
					remove = boards[i]->fullLineCheck(whatRow);
					boards[i]->removeARow(remove, whatRow);
					boards[i]->printBoard();
				}
			}
		}
		//check if someone won or tie
		checkAndUpdateIfSomeoneLost();

		Sleep(400);
	}
}

void Game::presentTheKeys()const
{
	std::cout << "************************INSTRUCTIONS************************" << std::endl;
	std::cout << "Tetris is a classic puzzle game where the player manipulates" << std::endl;
	std::cout << "falling 4X4 blocks to create complete horizontal lines." << std::endl;


	std::cout << "************************THE KEYS***********************" << std::endl;
	std::cout << "|-----------------------------------------------------|" << std::endl;
	std::cout << "|                        | LEFT PLAYER | RIGHT PLAYER |" << std::endl;
	std::cout << "|------------------------|-------------|--------------|" << std::endl;
	std::cout << "|LEFT                    |   a or A    |    j or J    |" << std::endl;
	std::cout << "|------------------------|-------------|--------------|" << std::endl;
	std::cout << "|RIGHT                   |   d or D    |    l or L    |" << std::endl;
	std::cout << "|------------------------|-------------|--------------|" << std::endl;
	std::cout << "|ROTATE CLOCKWISE        |   s or S    |    k or K    |" << std::endl;
	std::cout << "|------------------------|-------------|--------------|" << std::endl;
	std::cout << "|ROTATE COUNTERCLOCKWISE |   w or W    |    i or I    |" << std::endl;
	std::cout << "|------------------------|-------------|--------------|" << std::endl;
	std::cout << "|DROP                    |   x or X    |    m or M    |" << std::endl;
	std::cout << "|-----------------------------------------------------|" << std::endl;
	std::cout << "|              press any key to continue...           |" << std::endl;
	std::cout << "|-----------------------------------------------------|" << std::endl;



}

void Game::printMenuWithPause()const
{
	std::cout << "*******************THE MENU********************" << std::endl;
	std::cout << "* (1) Start a new game - Human vs Human       *" << std::endl;
	std::cout << "* (2) Start a new game - Human vs Computer    *" << std::endl;
	std::cout << "* (3) Start a new game - Computer vs Computer *" << std::endl;
	std::cout << "* ------------------------------------------- *" << std::endl;
	std::cout << "* (4) Continue a paused game                  *" << std::endl;
	std::cout << "* (8) Present instructions and keys           *" << std::endl;
	std::cout << "* (9) EXIT                                    *" << std::endl;
	std::cout << "***********************************************" << std::endl;
	std::cout << "Please write your choice here:  " << std::endl;

}

void Game::printMenuWithoutPause()const
{
	std::cout << "*******************THE MENU********************" << std::endl;
	std::cout << "* (1) Start a new game - Human vs Human       *" << std::endl;
	std::cout << "* (2) Start a new game - Human vs Computer    *" << std::endl;
	std::cout << "* (3) Start a new game - Computer vs Computer *" << std::endl;
	std::cout << "* ------------------------------------------- *" << std::endl;
	std::cout << "* (8) Present instructions and keys           *" << std::endl;
	std::cout << "* (9) EXIT                                    *" << std::endl;
	std::cout << "***********************************************" << std::endl;
	std::cout << "Please write your choice here:  " << std::endl;
}

void Game::playerChoice(char choice)
{
	//playerChoice(choice);
	switch (choice)
	{
	case '1'://HUMAN vs HUMAN
		clear_screen();
		resetBoards(); //this check the address, if its different, that means we allocated memory, 
									//else, we didnot and its the start of the game
		boards[0]->setLostTheGame(false);
		boards[1]->setLostTheGame(false);

		boards[0] = new Human(*boards[0]);
		boards[1] = new Human(*boards[1]);

		start();
		break;
	case '2'://HUMAN vs COMPUTER
		clear_screen();
		resetBoards(); //this check the address, if its different, that means we allocated memory, 
									//else, we didnot and its the start of the game
		boards[0]->setLostTheGame(false);
		boards[1]->setLostTheGame(false);

		boards[0] = new Human(*boards[0]);
		boards[1] = new Computer(*boards[1]);

		whatDifficulty(boards[1], 1);
		start();
		break;


	case '3'://COMPUTER vs COMPUTER
		clear_screen();
		resetBoards(); //this check the address, if its different, that means we allocated memory, 
									//else, we didnot and its the start of the game
		boards[0]->setLostTheGame(false);
		boards[1]->setLostTheGame(false);

		boards[0] = new Computer(*boards[0]);
		boards[1] = new Computer(*boards[1]);

		whatDifficulty(boards[0], boards[1]);
		start();
		break;

	case '4'://pause the game
		clear_screen();
		break;

	case '8'://presentTheKeys
		clear_screen();
		presentTheKeys();
		choice = _getch();
		clear_screen();
		break;

	case '9'://escape
		//quitGame = true;
		this->endGame = true;
		boards[0]->setLostTheGame(false);
		boards[1]->setLostTheGame(false);
		resetBoards();
		break;

	default: //never happends
		break;
	}
}

void Game::menu(int whichGame)
{

	char choice; //choice is the player input
	clear_screen();
	if (whichGame == (int)gameOption::STARTGAME)
		printMenuWithoutPause();//print without the pause option
	else
		printMenuWithPause(); //print with the pause option

	//the input is valid
	choice = _getch();

	//checks if the player want the start menu or middle game menu
	if (choice == '4' && whichGame == (int)gameOption::STARTGAME)
		choice = '10';
	while (choice != '1' && choice != '2' && choice != '3' && choice != '8' && choice != '9'&& choice!= '4')
	{
		if (choice == '4' && whichGame == (int)gameOption::STARTGAME)
			choice = '10';
		Sleep(100);
		std::cout << std::endl << "invalid option please try again: ";
		choice = _getch();
	}
	playerChoice(choice); //do what the player choose

}

void Game::goDown(Board& currBoard, bool& cant_move)
{
	if (currBoard.canMove((int)charkeys::DOWN))
	{
		currBoard.getCurrShape()->move((int)charkeys::DOWN);
	}
	else
	{
		cant_move = true;
	}
}

int Game::whatPlayer(char ch)const
{
	for (int i = 0; i < (int)gameOption::KYES_PER_PLAYER; i++)
	{
		if (ch == key1[i])
			return (int)gameOption::BOARD1;
		if (ch == key2[i])
			return (int)gameOption::BOARD2;
	}
	return (int)gameOption::NO_BOARD;
}

void Game::PrintEndGame(int whichGame)const
{
	char buff;

	clear_screen();

	switch (whichGame)
	{
	case (int)gameOption::TIE:
		std::cout << "******************************************" << std::endl;
		std::cout << "*               It's A Tie!              *" << std::endl;
		std::cout << "*                                        *" << std::endl;
		std::cout << "******************************************" << std::endl;
		break;
	case (int)gameOption::BOARD1:

		std::cout << "******************************************" << std::endl;
		std::cout << "*             Player 2 Won!!             *" << std::endl;
		std::cout << "*            Congratulations!            *" << std::endl;
		std::cout << "******************************************" << std::endl;

		break;
	case (int)gameOption::BOARD2:
		std::cout << "******************************************" << std::endl;
		std::cout << "*             Player 1 Won!!             *" << std::endl;
		std::cout << "*            Congratulations!            *" << std::endl;
		std::cout << "******************************************" << std::endl;

		break;
	default:
		break;
	}

	std::cout << "press eny key to return the menu: ";
	Sleep(1500);
	buff = _getch();

	clear_screen();

}

void Game::checkAndUpdateIfSomeoneLost()
{
	if (boards[0]->getLostTheGame() == true && boards[1]->getLostTheGame() == true) //tie
	{
		PrintEndGame((int)gameOption::TIE);
		// if someone won, that means you played the game. 
		// for that reasone we have to delete the memory that we allocated when the game starts 
		resetBoards();
		boards[0]->setLostTheGame(true);
		boards[1]->setLostTheGame(true);

	}
	else if (boards[0]->getLostTheGame() == true) //same explanation as the later 
	{
		PrintEndGame((int)gameOption::BOARD1);
		resetBoards();
		boards[0]->setLostTheGame(true);


	}
	else if (boards[1]->getLostTheGame() == true) //same explanation as the later 
	{
		PrintEndGame((int)gameOption::BOARD2);
		resetBoards();
		boards[1]->setLostTheGame(true);

	}

}




void Game::resetBoards()
{
	if (boards[0] != &board0)
		//if the addresses are different, that means we allocated memory, and we need to delete it 
	{
		delete boards[0];
		delete boards[1];

		//reset to defult if someone wants to start the game over again. 

		boards[0] = &board0;
		boards[1] = &board1;
	}

}
void Game::whatDifficulty(Board* b0,int i)
{
	clear_screen();


	std::cout << "************COMPUTER #"<<i<< "**************" << std::endl;
	std::cout << "**********SELECT DIFFICULTY**********" << std::endl;
	std::cout << "* (1) BEST                          *" << std::endl;
	std::cout << "* (2) GOOD                          *" << std::endl;
	std::cout << "* (3) NOVICE                        *" << std::endl;
	std::cout << "*************************************" << std::endl;
	std::cout << "Please write your choice here:  " << std::endl;

	char choice = _getch();

	while (choice != '1' && choice != '2' && choice != '3')
	{
		std::cout << std::endl << "invalid option please try again: ";
		choice = _getch();
	}
	clear_screen();

	switch (choice)
	{

		//1. BEST
	case '1':
		b0->setDifficultyLvl((char)difficulty::BEST);
		clear_screen();
		std::cout << "$$\\                             $$\\     " << std::endl;
		std::cout << "$$ |                            $$ |    " << std::endl;
		std::cout << "$$$$$$$\\   $$$$$$\\   $$$$$$$\\ $$$$$$\\   " << std::endl;
		std::cout << "$$  __$$\\ $$  __$$\\ $$  _____|\\_$$  _|  " << std::endl;
		std::cout << "$$ |  $$ |$$$$$$$$ |\\$$$$$$\\    $$ |    " << std::endl;
		std::cout << "$$ |  $$ |$$   ____| \\____$$\\   $$ |$$\\ " << std::endl;
		std::cout << "$$$$$$$  |\\$$$$$$$\\ $$$$$$$  |  \\$$$$  |" << std::endl;
		std::cout << "\\_______/  \\_______|\\_______/    \\____/ " << std::endl;
		std::cout << "                                        " << std::endl;
		std::cout << "                                        " << std::endl;
		Sleep(300);
		clear_screen();
		break;

		//2. GOOD
	case '2':
		b0->setDifficultyLvl((char)difficulty::GOOD);
		clear_screen();

		std::cout << " $$$$$$\\   $$$$$$\\   $$$$$$\\  $$$$$$$\\  " << std::endl;
		std::cout << "$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ " << std::endl;
		std::cout << "$$ /  \\__|$$ /  $$ |$$ /  $$ |$$ |  $$ |" << std::endl;
		std::cout << "$$ |$$$$\\ $$ |  $$ |$$ |  $$ |$$ |  $$ |" << std::endl;
		std::cout << "$$ |\\_$$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |" << std::endl;
		std::cout << "$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |" << std::endl;
		std::cout << "\\$$$$$$  | $$$$$$  | $$$$$$  |$$$$$$$  |" << std::endl;
		std::cout << " \\______/  \\______/  \\______/ \\_______/ " << std::endl;
		std::cout << "                                         " << std::endl;
		Sleep(300);
		clear_screen();
		break;

		//3. NOVICE
	case '3':
		b0->setDifficultyLvl((char)difficulty::NOVICE);
		clear_screen();
		std::cout << "$$\\   $$\\  $$$$$$\\  $$\\    $$\\ $$$$$$\\  $$$$$$\\  $$$$$$$$\\ " << std::endl;
		std::cout << "$$$\\  $$ |$$  __$$\\ $$ |   $$ |\\_$$  _|$$  __$$\\ $$  _____|" << std::endl;
		std::cout << "$$$$\\ $$ |$$ /  $$ |$$ |   $$ |  $$ |  $$ /  \\__|$$ |      " << std::endl;
		std::cout << "$$ $$\\$$ |$$ |  $$ |\\$$\\  $$  |  $$ |  $$ |      $$$$$\\    " << std::endl;
		std::cout << "$$ \\$$$$ |$$ |  $$ | \\$$\\$$  /   $$ |  $$ |      $$  __|   " << std::endl;
		std::cout << "$$ |\\$$$ |$$ |  $$ |  \\$$$  /    $$ |  $$ |  $$\\ $$ |      " << std::endl;
		std::cout << "$$ | \\$$ | $$$$$$  |   \\$  /   $$$$$$\\ \\$$$$$$  |$$$$$$$$\\ " << std::endl;
		std::cout << "\\__|  \\__| \\______/     \\_/    \\______| \\______/ \\________|" << std::endl;
		std::cout << "                                                            " << std::endl;
		std::cout << "                                                            " << std::endl;
		std::cout << "                                                            " << std::endl;

		Sleep(300);
		clear_screen();
		break;
	default:
		break;
	}
}
void Game::whatDifficulty(Board* b0, Board* b1)
{

	whatDifficulty(b0,1);

	whatDifficulty(b1,2);

}