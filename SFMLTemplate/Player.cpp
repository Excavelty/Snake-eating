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

void Player::move(int x, int y)
{
	(*vectPtr)[0]->move(sf::Vector2i(x, y));
	unsigned size = vectPtr->size();

	for (unsigned i = 1; i < size; ++i)
	{
		(*vectPtr)[i]->setPosition((*vectPtr)[i - 1]->getPreviousPos());
	}
}

void Player::reactToInput(int key)
{
	if (dir != Direction::DOWN && (key == sf::Keyboard::W || key == sf::Keyboard::Up))
		dir = Direction::UP;
	else if (dir != Direction::UP && (key == sf::Keyboard::S || key == sf::Keyboard::Down))
		dir = Direction::DOWN;
	else if (dir != Direction::RIGHT && (key == sf::Keyboard::A || key == sf::Keyboard::Left))
		dir = Direction::LEFT;
	else if (dir != Direction::LEFT && (key == sf::Keyboard::D || key == sf::Keyboard::Right))
		dir = Direction::RIGHT;
}

void Player::addSegment()
{
	unsigned size = vectPtr->size();
	vectPtr->push_back(new Segment{ (*vectPtr)[size - 1]->getLength(), (*vectPtr)[size - 1]->getPreviousPos(), sf::Color::White } );
}

const sf::Vector2i Player::getHeadPos()
{
	return (*vectPtr)[0]->getPos();
}
