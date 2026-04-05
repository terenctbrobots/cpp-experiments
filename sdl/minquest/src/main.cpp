
 #include "Game.h"

int main(int argc, char*argv[])
{
    Game game;

    game.Init();

    game.Main();

    game.Cleanup();

    return 0;
}