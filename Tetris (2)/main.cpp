#include <conio.h> // for _kbhit and _getch
#include <Windows.h> // for sleep 
#include "game.h"
#include <iostream>
#include "general.h"


int main()
{
    //TETRIS opening logo
    std::cout << " /$$$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$  /$$$$$$  /$$$$$$ " << std::endl;
    std::cout << "|__  $$__/| $$_____/|__  $$__/| $$__  $$|_  $$_/ /$$__  $$" << std::endl;
    std::cout << "   | $$   | $$         | $$   | $$  \\ $$  | $$  | $$  \\__/" << std::endl;
    std::cout << "   | $$   | $$$$$      | $$   | $$$$$$$/  | $$  |  $$$$$$ " << std::endl;
    std::cout << "   | $$   | $$__/      | $$   | $$__  $$  | $$   \\____  $$" << std::endl;
    std::cout << "   | $$   | $$         | $$   | $$  \\ $$  | $$   /$$  \\ $$" << std::endl;
    std::cout << "   | $$   | $$$$$$$$   | $$   | $$  | $$ /$$$$$$|  $$$$$$/" << std::endl;
    std::cout << "   |__/   |________/   |__/   |__/  |__/|______/ \\______/ " << std::endl;

    Sleep(1500);
    clear_screen();

   
	Game newGame;  
    //game status returns true when the player want to quit the game
    while (!newGame.getGameStatus()) 
    { 
	    newGame.menu((int)gameOption::STARTGAME);
    }

	return 0;
}
