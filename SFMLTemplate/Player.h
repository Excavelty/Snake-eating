#pragma once
#include "SFML/Graphics.hpp"
#include "Directions.h"
#include "Segment.h"
#include <vector>

class Player
{
public:
	Player(std::vector<Segment* >* ptr);
	const sf::Vector2i getHeadPos();
	void updateLogic();
	void move(int x, int y);
	void reactToInput(int key);
	void addSegment();

private:
	std::vector<Segment* >* vectPtr;
	Direction dir = Direction::NONE;
};

