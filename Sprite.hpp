#ifndef _SPRITE_HPP_
    #define _SPRITE_HPP_

#include "SDL.h"
#include "SDL_image.h"


#include <iostream>


class CSprite
{
    public:
        CSprite();

    public:
        SDL_Texture* Load(SDL_Renderer* pRenderer, const char* cPath, int R, int G, int B);
        SDL_Texture* LoadGIF(SDL_Renderer* pRenderer, const char* cPath, int R, int G, int B);
        void Render(SDL_Renderer* pRenderer);
        void CleanUp();

        void SetSourceRect(int x, int y, int width, int height);
        void SetDestinationRect(int x, int y, int width, int height);

    private:
        SDL_Rect rcSrc;
        SDL_Rect rcDst;

        SDL_Texture* tImage;
};


#endif

