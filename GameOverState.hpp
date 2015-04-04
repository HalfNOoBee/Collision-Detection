#ifndef _GAMEOVERSTATE_HPP_
    #define _GAMEOVERSTATE_HPP_

#include "SDL.h"
#include "GameState.hpp"
#include "TTF.hpp"
#include <iostream>


class CGameOverState : public CGameState
{
    public:
        void Init(SDL_Renderer* pRenderer);
        void Cleanup();

        void Pause();
        void Resume();

        void HandleEvents(CGame* game);
        void Update(CGame* game);
        void Render(CGame* game);

        static CGameOverState* Instance() {return &m_GameOverState;}

    protected:
        CGameOverState() { }

    private:
        static CGameOverState m_GameOverState;

        CTTF* GameOverField;

};

#endif //_GAMEOVERSTATE_HPP_


