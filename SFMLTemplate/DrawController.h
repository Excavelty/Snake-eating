#pragma once
#include "Segment.h"
#include "Fruit.h"

class DrawController
{
public:
	DrawController() = default;
	void updateDrawings(sf::RenderWindow& window, const std::vector<Segment* > segments, Fruit* fruit);
};

