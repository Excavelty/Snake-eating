#pragma once
#include "SFML/Graphics.hpp"
#include "Directions.h"
#include "Segment.h"
#include <vector>

class Player
{
public:
	Player(std::vector<Segment* >* ptr, const sf::Vector2i& limits);
	const sf::Vector2i getHeadPos();
	bool updateLogic();
	void move(int x, int y);
	void reactToInput(int key);
	void addSegment();

private:
	bool reactToIntersection();
	void reactIfBehindMap();

private:
	std::vector<Segment* >* vectPtr;
	sf::Vector2i mapLimits;
	Direction dir = Direction::NONE;
};

