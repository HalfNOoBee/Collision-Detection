#ifndef _TILE_HPP_
    #define _TILE_HPP_

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Sprite.hpp"


enum {TILE_TYPE_NONE = 0,
      TILE_TYPE_SOLID = 1,
      TILE_TYPE_PLATFORM = 2,
      TILE_TYPE_DMG = 3,
      TILE_TYPE_CLIMBABLE = 4,
      TILE_TYPE_COLLECTABLE = 5,
      TILE_TYPE_LEVEL_END = 6,
      TILE_TYPE_QUESTION_BLOCK = 7};


class CTile
{
    public:
        CTile();

        int GetTileID();
        int GetTypeID();
        void SetTileID(int TempTileID);
        void SetTypeID(int TempTypeID);


        int GetSize();
        void Animate();

        bool IsOnScreen(int X, int Y);
        int GetCurrentFrame() { return CurrentFrame; }

        void SetMaxFrames(int MaxFrames);

    private:
        int TileID;
        int TypeID;

        int CurrentFrame;
        int m_MaxFrames;

        static const int TILE_SIZE = 32;
};


#endif // _TILE_HPP_

