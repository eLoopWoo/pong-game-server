#pragma once
#include <SFML\Graphics.hpp>
#include <ball.h>
#include <paddle.h>
class gameWindow
{
private:

	int width = 640;
	int length = 480;
	int borderSize = 10;

	sf::RenderWindow window;
	sf::Event event;
	sf::RectangleShape border_top;
	sf::RectangleShape border_bottom;
	sf::RectangleShape border_left;
	sf::RectangleShape border_right;
	paddle paddle1;
	paddle paddle2;
	ball ball1;
	sf::Font fonts;
	sf::Text texts;






public:
	gameWindow();
	~gameWindow();
};

