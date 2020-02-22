#include "DrawController.h"

void DrawController::updateDrawings(sf::RenderWindow& window, const std::vector<Segment* > segments)
{
	for (auto segment : segments)
	{
		segment->draw(window);
	}
}
