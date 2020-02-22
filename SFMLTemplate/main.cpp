#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    const double length = 600.;
    Game game(length, length, "Template title");
    game.run();

    return 0;
}