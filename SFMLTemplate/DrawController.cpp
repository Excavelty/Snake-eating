#include "DrawController.h"
#include <iostream>

void DrawController::updateDrawings(sf::RenderWindow& window, const std::vector<Segment* > segments, Fruit* fruit)
{
	for (auto segment : segments)
	{
		segment->draw(window);
		fruit->draw(window);
		std::cout << segment->getPreviousPos().x << ' ' << segment->getPreviousPos().y << "\n";
	}
}
