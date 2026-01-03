#pragma once

#include "Config.h"

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

#ifdef PLATFORM_UNIX
        float m_MainScale;
        const char* m_GlslVersion;
        SDL_GLContext m_GlContext;
#endif

        int InitSDL();
        void InitIMGUI();

        bool InputEvents();
        int RenderGame();
        int RenderGui(); // Right we assume the GUI is over the game
};