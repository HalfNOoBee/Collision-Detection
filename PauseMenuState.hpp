#ifndef _PAUSEMENUSTATE_HPP_
    #define _PAUSEMENUSTATE_HPP_

#include "SDL.h"
#include "GameState.hpp"
#include "Button.hpp"
#include <iostream>

class CPauseMenuState : public CGameState
{
    public:
        void Init(SDL_Renderer* pRenderer);
        void Cleanup();

        void Pause();
        void Resume();

        void HandleEvents(CGame* game);
        void Update(CGame* game);
        void Render(CGame* game);

        static CPauseMenuState* Instance() {return &m_PauseMenuState;}

        static CPauseMenuState m_PauseMenuState;

    protected:
        CPauseMenuState() { }

    private:
        CButton* ContinueButton;
        CButton* QuitButton;

};

#endif

