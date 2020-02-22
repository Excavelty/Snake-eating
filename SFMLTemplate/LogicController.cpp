#include "LogicController.h"

LogicController::LogicController(Player* player, Fruit* fruit)
{
	this->player = player;
	this->fruit = fruit;
}

void LogicController::updateLogic()
{
	player->updateLogic();
}