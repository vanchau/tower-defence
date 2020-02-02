#ifndef TITLESTATE_HPP
#define TITLESTATE_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class TitleState
{
public:
	TitleState();
	void start();
	void processEvents();
	void render();

private:
	sf::Music titleMusic;
	sf::RenderWindow mWindow;
	sf::Sprite title;
	sf::Texture titleTexture;
};

#endif