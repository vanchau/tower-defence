#include "TitleState.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

TitleState::TitleState() : mWindow(sf::VideoMode(1920, 1080), "Title", sf::Style::None), title(), titleTexture()
{
	if (!titleTexture.loadFromFile("./Resources/title.png"))
		std::cout << "Opening title.png failed" << std::endl;
	title.setTexture(titleTexture);
	if (!titleMusic.openFromFile("./Resources/TitleMusic.wav"))
		std::cout << "Failed to load main music" << std::endl;
	titleMusic.setVolume(3);
	titleMusic.play();

}

void TitleState::start()
{
	while (mWindow.isOpen())
	{
		processEvents();
		render();
	}
}

void TitleState::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
		if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
		{
			titleMusic.stop();
			mWindow.close();
		}
}

void TitleState::render()
{
	mWindow.clear();
	mWindow.draw(title);
	mWindow.display();
}