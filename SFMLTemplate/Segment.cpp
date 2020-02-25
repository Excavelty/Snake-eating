#include "Segment.h"
#include <iostream>

Segment::Segment(float length, const sf::Vector2i& initPos, const sf::Color& color) : sizes{length, length}, pos{ initPos }
{
	square = new sf::RectangleShape{ sf::Vector2f{length, length} };
	setPosition(pos);
	square->setFillColor(color);
}

Segment::~Segment()
{
	delete square;
}

void Segment::move(const sf::Vector2i& moveVector)
{
	previousPos = pos;
	pos += moveVector;
	std::cout << moveVector.x << " "<<moveVector.y << "\n";
	square->move(sf::Vector2f{ moveVector.x * sizes.x, moveVector.y * sizes.y });
}

void Segment::draw(sf::RenderWindow& window)
{
	window.draw(*square);
}


void Segment::setPosition(const sf::Vector2i& newPos)
{
	previousPos = pos;
	pos = newPos;
	square->setPosition(sf::Vector2f{ newPos.x * sizes.x, newPos.y * sizes.y });
}

const sf::Vector2i Segment::getPos()
{
	return pos;
}

const sf::Vector2i Segment::getPreviousPos()
{
	return previousPos;
}

const float Segment::getLength()
{
	return sizes.x;
}
