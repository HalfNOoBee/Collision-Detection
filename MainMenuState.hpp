#ifndef _MAINMENUSTATE_HPP_
    #define _MAINMENUSTATE_HPP_

#include "SDL.h"
#include "GameState.hpp"
#include "Sprite.hpp"
#include "Button.hpp"
#include "Checkbox.hpp"
#include <iostream>

class CMainMenuState : public CGameState
{
    public:
        void Init(SDL_Renderer* pRenderer);
        void Cleanup();

        void Pause();
        void Resume();

        void HandleEvents(CGame* game);
        void Update(CGame* game);
        void Render(CGame* game);

        static CMainMenuState* Instance() {return &m_CMainMenuState;}

    protected:
        CMainMenuState() { }

    private:
        static CMainMenuState m_CMainMenuState;

        CSprite BackgroundSprite;
        SDL_Texture* Background;
        CSprite MarioSprite;
        SDL_Texture* Mario;

        CButton* PlayButton;
        CButton* OptionsButton;
        CButton* QuitButton;
};

#endif


