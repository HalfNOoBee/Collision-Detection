#ifndef _TTF_HPP_
    #define _TTF_HPP_

#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>
#include <string>


class CTTF
{
    public:
        CTTF(int x, int y);

        void Load(SDL_Renderer* pRenderer, const char* cPath, int FontSize);
        void Render(SDL_Renderer* pRenderer, std::string Text, int R, int G, int B);
        void CleanUp();

        bool NeedsUpdate(bool hasChanged);
        void SetAlpha(Uint8 Alpha);
        void SetBlendMode(SDL_BlendMode BlendMode);

    private:
        int m_PosX;
        int m_PosY;
        int m_Width;
        int m_Height;

        bool m_bNeedsUpdate;

        TTF_Font* Font;
        SDL_Texture* Texture;
        SDL_Rect textRect;
        SDL_Color textColor;
        std::string Text;
};



#endif
