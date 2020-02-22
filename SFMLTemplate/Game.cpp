#include "Game.h"

Game::Game(double initWidth, double initHeight, const std::string& initTitle) : width{initWidth}, height{initHeight}, 
length { static_cast<float> (width) / divider }, title{initTitle}, 
    window{sf::VideoMode(static_cast<unsigned> (width),  static_cast<unsigned> (height)), title, sf::Style::Close | sf::Style::Titlebar}
{

}

Game::~Game()
{
    for (auto segment : segmentArray)
    {
        delete segment;
    }

    delete player;
    delete fruit;
    delete logicController;
}

void Game::run()
{
    initSegments();
    initEnvironment();
    initController();

    const int framerateLimit = 60;
    window.setFramerateLimit(framerateLimit);

    while (window.isOpen())
    {
        logicController->updateLogic();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawController.updateDrawings(window, segmentArray);
        window.display();
    }
}

void Game::initSegments()
{
    Segment* head = new Segment(length, sf::Vector2u{0, 0}, sf::Color::White);
    segmentArray.push_back(head);
}

void Game::initEnvironment()
{
    player = new Player{&segmentArray};
    fruit = new Fruit;
}

void Game::initController()
{
    logicController = new LogicController{ player, fruit };
}
