#pragma once
#include "Segment.h"

class DrawController
{
public:
	DrawController() = default;
	void updateDrawings(sf::RenderWindow& window, const std::vector<Segment* > segments);
};

