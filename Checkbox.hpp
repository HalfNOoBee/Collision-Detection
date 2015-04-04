#ifndef _CHECKBOX_HPP_
    #define _CHECKBOX_HPP_


#include "Sprite.hpp"


enum {BOX_NOT_ON = 0,
      MOUSE_OVER_BOX = 1,
      BOX_IS_ON = 2};


class CCheckBox
{
    public:
        CCheckBox(int x, int y, bool isTicked);

        void Load(SDL_Renderer* pRenderer);
        void Update();
        void Render(SDL_Renderer* pRenderer);
        void CleanUp();

        bool MouseOver();
        bool IsClicked();

        int GetWidth() { return m_Width; }
        int GetHeight() { return m_Height; }

        bool IsOn;
        bool IsOff;


    private:
        int m_PosX;
        int m_PosY;
        int m_Width;
        int m_Height;

        int MousePosX;
        int MousePosY;



        int CurrentState;
        SDL_Texture* m_tCheckBox;
        CSprite CheckBoxSprite;
};


#endif

