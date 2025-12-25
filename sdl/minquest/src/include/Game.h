#pragma once

#include <SDL3/SDL.h>

class Game 
{
    public:
        int Initialize();
        ~Game();
    private:
        SDL_Window* m_Window = NULL;
        SDL_Renderer* m_Renderer = NULL;

};