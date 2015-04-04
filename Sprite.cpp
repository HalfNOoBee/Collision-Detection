#include "Sprite.hpp"
#include "Game.hpp"
#include "SDL_RWops.h"

CSprite::CSprite()
{
    tImage = NULL;
}


SDL_Texture* CSprite::Load (SDL_Renderer* pRenderer, const char* cPath, int R, int G, int B)
{

    SDL_Surface* sImage = NULL;
    sImage = IMG_Load(cPath);
    if (sImage == NULL)
    {
        std::cout << "Fehler beim Laden von " << cPath << "! SDL_Error: " << SDL_GetError() << "\n";
    }
    else
    {
        SDL_SetColorKey(sImage, SDL_TRUE, SDL_MapRGB(sImage-> format, R, G, B));
        tImage = SDL_CreateTextureFromSurface(pRenderer, sImage);
        if (tImage == NULL)
        {
            std::cout << "Fehler beim Umwandeln von einer Surface in eine Textur der Grafik " << cPath << "! SDL_Error: " << SDL_GetError() <<"\n";
        }
        SDL_FreeSurface (sImage);
    }

    return tImage;
}

SDL_Texture* CSprite::LoadGIF (SDL_Renderer* pRenderer, const char* cPath, int R, int G, int B)
{
    //SDL_RWops

    SDL_Surface* sImage = NULL;
//    sImage = IMG_LoadGIF_RW(cPath);
    if (sImage == NULL)
    {
        std::cout << "Fehler beim Laden von " << cPath << "! SDL_Error: " << SDL_GetError() << "\n";
    }
    else
    {
        SDL_SetColorKey(sImage, SDL_TRUE, SDL_MapRGB(sImage-> format, R, G, B));
        tImage = SDL_CreateTextureFromSurface(pRenderer, sImage);
        if (tImage == NULL)
        {
            std::cout << "Fehler beim Umwandeln von einer Surface in eine Textur der Grafik " << cPath << "! SDL_Error: " << SDL_GetError() <<"\n";
        }
        SDL_FreeSurface (sImage);
    }

    return tImage;
}


void CSprite::Render(SDL_Renderer* pRenderer)
{
    SDL_RenderCopy (pRenderer,tImage,&rcSrc,&rcDst);
}

void CSprite::CleanUp()
{
    SDL_DestroyTexture(tImage);
}

void CSprite::SetSourceRect(int x, int y, int width, int height)
{
    rcSrc.x = x;
    rcSrc.y = y;
    rcSrc.w = width;
    rcSrc.h = height;
}

void CSprite::SetDestinationRect(int x, int y, int width, int height)
{
    rcDst.x = x;
    rcDst.y = y;
    rcDst.w = width;
    rcDst.h = height;
}


