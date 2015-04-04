#ifndef _PLAYSTATE_HPP_
    #define _PLAYSTATE_HPP_

#include "SDL.h"
#include "GameState.hpp"
#include "Button.hpp"
#include "TTF.hpp"
#include "Player.hpp"
#include "Goombas.hpp"
#include "Map.hpp"
#include "Timer.hpp"
#include <iostream>
#include <sstream>
#include <vector>


class CPlayState : public CGameState
{
    public:
        void Init(SDL_Renderer* pRenderer);
        void Cleanup();

        void Pause();
        void Resume();

        void HandleEvents(CGame* game);
        void Update(CGame* game);
        void Render(CGame* game);

        static CPlayState* Instance() {return &m_PlayState;}

        CPlayer Player;
        CGoombas Goombas;

        int GetPlayTime() { return m_PlayTime; }


    protected:
        CPlayState() { }

    private:
        static CPlayState m_PlayState;

        CButton* PauseButton;

        CMap Map;
        Mix_Music* Soundtrack;

        CTimer PlayTime;
        int m_PlayTime;

        CTTF* LivesField;
        CSprite LivesSprite;
        SDL_Texture* LivesTexture;

        CTTF* CoinsField;
        CSprite CoinsSprite;
        SDL_Texture* CoinsTexture;

        CTTF* TimeField;

        CTTF* ScoreField;

        int CurrentFrame;
};

#endif
