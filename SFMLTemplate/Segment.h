#pragma once
#include "SFML/Graphics.hpp"

class Segment
{
public:
	Segment(float length, const sf::Vector2i& initPos);
	~Segment();
	void move(const sf::Vector2i& moveVector);
	void draw(sf::RenderWindow& window);
	void setPosition(const sf::Vector2i& newPos);
	const sf::Vector2i getPos();
	const sf::Vector2i getPreviousPos();
	const float getLength();

private:
	static int counter;
	const sf::Color colors[2] = { sf::Color::Red, sf::Color::Magenta };
	const sf::Vector2f sizes;
	sf::Vector2i pos;
	sf::Vector2i previousPos;
	sf::RectangleShape* square;
};

