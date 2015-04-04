#ifndef _CBUTTON_HPP_
    #define _CBUTTON_HPP_


#include "Game.hpp"
#include "Sprite.hpp"


enum {BUTTON_NOT_CLICKED = 0,
      MOUSE_OVER_BUTTON = 1,
      BUTTON_IS_CLICKED = 2};


class CButton
{
    public:
        CButton(int x, int y, bool center_horizontal);

    public:
        void Load(SDL_Renderer* pRenderer, const char* cPath);
        void Update();
        void Render(SDL_Renderer* pRenderer);
        void CleanUp();

        bool MouseOver();
        bool IsClicked();

        int GetWidth() { return m_Width; }
        int GetHeight() { return m_Height; }


    private:
        int m_PosX;
        int m_PosY;
        int m_Width;
        int m_Height;

        int MousePosX;
        int MousePosY;

        int CurrentState;

        bool Centered_Hor;

        SDL_Texture* m_tButton;

        CSprite ButtonSprite;
        CGame Game;

};

#endif


