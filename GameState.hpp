#ifndef _GAMESTATE_HPP_
    #define _GAMESTATE_HPP_

#include "Game.hpp"

class CGameState
{
    public:
        virtual void Init(SDL_Renderer* pRenderer) = 0;
        virtual void Cleanup() = 0;

        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void HandleEvents(CGame* game) = 0;
        virtual void Update(CGame* game) = 0;
        virtual void Render(CGame* game) = 0;

        void ChangeState(CGame* game, CGameState* state) {game->ChangeState(state);}

    protected:
        CGameState() { }
};

#endif

