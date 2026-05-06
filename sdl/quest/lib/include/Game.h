#pragma once

#include <cstddef>

// Forward declaration
struct SDL_Window;
struct SDL_Renderer;
typedef struct SDL_GLContextState *SDL_GLContext;

class Game 
{
    public:
        int Init();
        int Main();
        int Cleanup();

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