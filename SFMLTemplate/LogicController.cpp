#include "LogicController.h"

LogicController::LogicController(Player* player, Fruit* fruit)
{
	this->player = player;
	this->fruit = fruit;
}

bool LogicController::updateLogic()
{
	bool returnValue = player->updateLogic();
	reactToCollision();

	return returnValue;
}

void LogicController::reactToCollision()
{
	const sf::Vector2i headPos = player->getHeadPos();
	const sf::Vector2i fruitPos = fruit->getPos();

	if (headPos.x == fruitPos.x && headPos.y == fruitPos.y)
	{
		player->addSegment();
		fruit->newPos();
	}
}