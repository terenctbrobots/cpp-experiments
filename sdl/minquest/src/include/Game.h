#pragma once

#include <SDL3/SDL.h>

class Game 
{
    public:
        int Init();
        int Main();


        ~Game();
    private:
        SDL_Window* m_Window = NULL;
        SDL_Renderer* m_Renderer = NULL;
        float m_MainScale;
        const char* m_GlslVersion;
        SDL_GLContext m_GlContext;

        int InitSDL();
        int InitIMGUI();

};