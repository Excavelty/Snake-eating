#pragma once
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <ctime>

class Fruit
{
public:
	Fruit(float length, int limitX, int limitY, const sf::Color& color);
	~Fruit();
	void draw(sf::RenderWindow& window);
	const sf::Vector2i getPos();
	void newPos();

private:
	sf::Vector2i pos;
	float length;
	int limitX;
	int limitY;
	sf::Color color;
	sf::RectangleShape* square;
};

