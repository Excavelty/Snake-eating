#pragma once
#include "SFML/Graphics.hpp"

class Segment
{
public:
	Segment(float length, const sf::Vector2u& initPos, const sf::Color& color);
	~Segment();
	void move(const sf::Vector2u& newPos);
	void setPos(const sf::Vector2f& newPos);
	void draw(sf::RenderWindow& window);
	const sf::Vector2u getPos();
	const sf::Vector2u getPreviousPos();

private:
	sf::Vector2u pos;
	sf::Vector2u previousPos;
	sf::RectangleShape* square;
};

