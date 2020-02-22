#pragma once
#include "SFML/Graphics.hpp"
#include "Directions.h"
#include "Segment.h"
#include <vector>

class Player
{
public:
	Player(std::vector<Segment* >* ptr);
	void updateLogic();
	void move(unsigned x, unsigned y);

private:
	std::vector<Segment* >* vectPtr;
	Direction dir = Direction::RIGHT;
};

