#ifndef _EXPLANATIONSTATE_HPP_
    #define _EXPLANATIONSTATE_HPP_

#include "SDL.h"
#include "GameState.hpp"
#include "TTF.hpp"
#include "Player.hpp"
#include <iostream>


class CExplanationState : public CGameState
{
    public:
        void Init(SDL_Renderer* pRenderer);
        void Cleanup();

        void Pause();
        void Resume();

        void HandleEvents(CGame* game);
        void Update(CGame* game);
        void Render(CGame* game);

        static CExplanationState* Instance() {return &m_ExplanationState;}

    protected:
        CExplanationState() { }

    private:
        static CExplanationState m_ExplanationState;

        std::string m_PlayerName;
        bool m_bHasConfirmedName;

        CSprite MarioSprite;
        SDL_Texture* Mario;
        CSprite PeachSprite;
        SDL_Texture* Peach;
        CSprite BowserSprite;
        SDL_Texture* Bowser;

        CTTF* ExplanationField;
        CTTF* ExplanationField2;
        CTTF* ExplanationField3;
        CTTF* EnterYourNameField;
        CTTF* GetPlayerNameField;
        CTTF* TaskField;
        CTTF* PressEnterToContinueField;

        Mix_Chunk* cTooManyChars;
};

#endif //_EXPLANATIONSTATE_HPP_

