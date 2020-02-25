#include "Fruit.h"

Fruit::Fruit(float length, int limitX, int limitY, const sf::Color& color)
{
	srand(33524);
	this->length = length;
	this->limitX = limitX;
	this->limitY = limitY;
	this->color = color;

	square = new sf::RectangleShape{ sf::Vector2f{this->length, this->length} };
	square->setFillColor(this->color);
	newPos();
}

Fruit::~Fruit()
{
	delete square;
}

void Fruit::draw(sf::RenderWindow& window)
{
	window.draw(*square);
}

const sf::Vector2i Fruit::getPos()
{
	return pos;
}

void Fruit::newPos()
{
	pos.x = rand() % limitX;
	pos.y = rand() % limitY;
	square->setPosition(sf::Vector2f{ length * pos.x, length * pos.y });
}
