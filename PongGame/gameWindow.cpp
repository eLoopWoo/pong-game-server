#include "gameWindow.h"
#include "ball.h"
#include "paddle.h"


gameWindow::gameWindow()
{
	window.setSize(sf::Vector2u(width, length));
	window.setTitle("PongOnline");


	border_top.setSize(sf::Vector2f(width*(4/5), borderSize));
	border_top.setPosition(sf::Vector2f(width/10, length/10));
	border_bottom.setSize(sf::Vector2f(width*(4 / 5), borderSize));
	border_bottom.setPosition(sf::Vector2f(width / 10, length*(9/10)));

	border_left.setSize(sf::Vector2f(borderSize, length*(5/4)));
	border_left.setPosition(sf::Vector2f(width/10, length/10));
	border_right.setSize(sf::Vector2f(borderSize, length*(5 / 4)));
	border_right.setPosition(sf::Vector2f(width/10, length/10));

	paddle1.settings(&window, width/5, length/2);
	paddle2.settings(&window, width*(4/5), length / 2);

	ball1.settings(&window, width/2, length*(5/8));

	fonts.loadFromFile("C:\\abc.ttf");
	texts.setString("Created by eLoopWoo");
	texts.setFont(fonts);
	texts.setCharacterSize(30);
	texts.setStyle(sf::Text::Bold);
	texts.setPosition(sf::Vector2f(width/2, length-50));
}


gameWindow::~gameWindow()
{
}
