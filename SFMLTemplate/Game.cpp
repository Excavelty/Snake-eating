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

    const int framerateLimit = 15;
    window.setFramerateLimit(framerateLimit);

    while (window.isOpen())
    {
        logicController->updateLogic();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                player->reactToInput(event.key.code);
        }

        window.clear();
        drawController.updateDrawings(window, segmentArray, fruit);
        window.display();
    }
}

void Game::initSegments()
{
    const int limit = 7;
    const sf::Color colors[2] = { sf::Color::Yellow, sf::Color::Cyan };
    Segment* head = new Segment(length, sf::Vector2i{limit, 0}, sf::Color::Yellow);
    segmentArray.push_back(head);

    for (int i = 1; i < limit; ++i)
    {
        segmentArray.push_back(new Segment{ length, sf::Vector2i{limit - i, 0}, colors[i % 2] });
    }
}

void Game::initEnvironment()
{
    player = new Player{&segmentArray};
    fruit = new Fruit{ length, static_cast<int> (divider), static_cast<int> (divider), sf::Color{222, 109, 87} };
}

void Game::initController()
{
    logicController = new LogicController{ player, fruit };
}
