#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Fruit.h"

class LogicController
{
public:
	LogicController(Player* player, Fruit* fruit);
	void updateLogic();

	void reactToCollision();

private:
	Player* player;
	Fruit* fruit;
};

