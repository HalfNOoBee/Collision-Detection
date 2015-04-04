#ifndef _HIGHSCORESTATE_HPP_
    #define _HIGHSCORESTATE_HPP_

#include "SDL.h"
#include "SDL_mixer.h"
#include "GameState.hpp"
#include "Sprite.hpp"
#include "TTF.hpp"
#include <iostream>


class CHighScoreState : public CGameState
{
    public:
        void Init(SDL_Renderer* pRenderer);
        void Cleanup();

        void Pause();
        void Resume();

        void HandleEvents(CGame* game);
        void Update(CGame* game);
        void Render(CGame* game);

        static CHighScoreState* Instance() {return &m_HighScoreState;}

    protected:
        CHighScoreState() { }

    private:
        static CHighScoreState m_HighScoreState;

        int m_CurrentFrame;

        /*CSprite DancingMarioSprite;
        SDL_Texture* DancingMarioTexture;*/

        Mix_Music* Soundtrack;

        CTTF* TitleField;

};

#endif //_HIGHSCORESTATE_HPP_



