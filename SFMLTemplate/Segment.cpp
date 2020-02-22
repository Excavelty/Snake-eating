#include "Segment.h"
#include <iostream>

Segment::Segment(float length, const sf::Vector2u& initPos, const sf::Color& color) : pos { initPos }
{
	square = new sf::RectangleShape{ sf::Vector2f{length, length} };
	setPos(sf::Vector2f{ pos });
	square->setFillColor(color);
}

Segment::~Segment()
{
	delete square;
}

void Segment::move(const sf::Vector2u& newPos)
{
	std::cout << "Hello!\n";
	previousPos = pos;
	pos = newPos;
	newPos.move{ pos * sf::Vector2f{} }
}

void Segment::setPos(const sf::Vector2f& newPos)
{
	square->setPosition(newPos);
}

void Segment::draw(sf::RenderWindow& window)
{
	window.draw(*square);
}

const sf::Vector2u Segment::getPos()
{
	return pos;
}

const sf::Vector2u Segment::getPreviousPos()
{
	return previousPos;
}
