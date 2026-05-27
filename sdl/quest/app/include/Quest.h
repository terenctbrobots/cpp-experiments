#include "Game.h"

class Quest : public Game
{
    public:
        int Init() override final;
        int Cleanup() override final;
};