#ifndef _OPTIONSSTATE_HPP_
    #define _OPTIONSSTATE_HPP_

#include "SDL.h"
#include "GameState.hpp"
#include "Button.hpp"
#include "Checkbox.hpp"
#include <iostream>

class COptionsState : public CGameState
{
    public:
        void Init(SDL_Renderer* pRenderer);
        void Cleanup();

        void Pause();
        void Resume();

        void HandleEvents(CGame* game);
        void Update(CGame* game);
        void Render(CGame* game);

        static COptionsState* Instance() {return &m_OptionsState;}

        static COptionsState m_OptionsState;

    protected:
        COptionsState() { }

    private:
        CSprite BackgroundSprite;
        SDL_Texture* Background;

        CButton* BackButton;
        CCheckBox* SoundCheckBox;
};

#endif
