#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    const double length = 600.;
    Game game(length, length, "Snake game");
    game.run();

    return 0;
}