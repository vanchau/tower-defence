#include <iostream>
#include "GameState.hpp"
#include "GraphTD.hpp"
#include "TitleState.hpp"

int main()
{
	std::cout << "Game started" << std::endl;
	TitleState title;
	title.start();
	GameState game;
	game.Start();
	std::cout << "Quit" << std::endl;
}