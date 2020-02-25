#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "DrawController.h"
#include "LogicController.h"
#include "Segment.h"
#include "Player.h"
#include "Fruit.h"

class Game
{
public:
	Game(double initWidth, double initHeight, const std::string& initTitle);
	~Game();
	void run();

private:
	void initSegments();
	void initEnvironment();
	void initController();

private:
	const float divider = 30.f;
	double width;
	double height;
	float length;
	const std::string title;
	sf::RenderWindow window;
	std::vector<Segment* > segmentArray; 
	DrawController drawController;
	Player* player = nullptr;
	Fruit* fruit = nullptr;
	LogicController* logicController = nullptr;
};

