#include "Player.h"

Player::Player(std::vector<Segment* >* ptr) : vectPtr{ ptr }
{
}

void Player::updateLogic()
{
	switch (dir)
	{
		case Direction::RIGHT: move(1, 0); break;
		case Direction::LEFT: move(-1, 0); break;
		case Direction::UP: move(0, -1); break;
		case Direction::DOWN: move(0, 1); break;
	}
}

void Player::move(unsigned x, unsigned y)
{
	(*vectPtr)[0]->move(sf::Vector2u(x, y));
	unsigned size = vectPtr->size();

	for (unsigned i = 1; i < size; ++i)
	{
		(*vectPtr)[i]->move((*vectPtr)[i - 1]->getPreviousPos());
	}
}
