#ifndef _GAME_HPP_
    #define _GAME_HPP_

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDLGameObject.hpp"

#include <iostream>
#include <vector>


class CGameState;

class CGame
{
    public:
        CGame();

        void Init();
        void Cleanup();

        void ChangeState(CGameState* state);
        void PushState(CGameState* state);
        void PopState();

        void HandleEvents();
        void Update();
        void Render();

        bool Running() { return m_running; }
        void Quit() { m_running = false; }

        SDL_Surface* MainWindowSurface;
        SDL_Window* MainWindow;
        SDL_Renderer* MainRenderer;
        SDL_Event* MainEvent;
        SDL_Surface* MainIcon;

        int GetWindowWidth() { return Screen_Width; }
        int GetWindowHeight() { return Screen_Height; }

    private:
        std::vector<CGameState*> StateList;
        std::vector<CSDLGameObject*> ObjectList;

        int Screen_Width;
        int Screen_Height;

        bool m_running;
        bool m_fullscreen;
};

#endif
