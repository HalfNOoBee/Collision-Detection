#ifndef _MAP_HPP_
    #define _MAP_HPP_


#include "SDL.h"
#include "SDL_image.h"

#include "Tile.hpp"
#include "Sprite.hpp"

#include <fstream>
#include <iostream>
#include <vector>



class CMap
{
    public:
        CMap();

    public:
        bool Load(SDL_Renderer* pRenderer, char* File, int MapWidth, int MapHeight);
        void Render(SDL_Renderer* pRenderer);

        int GetTypeOfTileAtPos(int X, int Y);
        void SetTileAtPos(int X, int Y, int NewTile, int NewType);

        bool IsCompleted() { return m_Completed; }

        std::vector<CTile> TileList;

        float GetWidth() { return MAP_WIDTH; }
        float GetHeight() { return MAP_HEIGHT; }

        int GetWidthInTiles() { return MAP_WIDTH_IN_TILES; }
        int GetHeightInTiles() { return MAP_HEIGHT_IN_TILES; }

    private:
        int MAP_WIDTH;
        int MAP_HEIGHT;

        int MAP_WIDTH_IN_TILES;
        int MAP_HEIGHT_IN_TILES;

        bool m_Completed;

        CSprite TileSheet;
        CSprite TileSheetPowerUps;
        CTile Tile;

};



#endif // _MAP_HPP_

