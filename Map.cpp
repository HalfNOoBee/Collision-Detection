#include "Map.hpp"
#include "Camera.hpp"

CMap::CMap()
{
    MAP_WIDTH = 0;
    MAP_HEIGHT = 0;

    m_Completed = false;
}

bool CMap::Load(SDL_Renderer* pRenderer, char* File, int MapWidth, int MapHeight)
{
    MAP_WIDTH = MapWidth;
    MAP_HEIGHT = MapHeight;
    MAP_WIDTH_IN_TILES = MapWidth / Tile.GetSize();
    MAP_HEIGHT_IN_TILES = MapHeight / Tile.GetSize();

    TileList.clear();

    FILE* FileHandle = fopen(File, "r");

    if(FileHandle == NULL)
    {
        return false;
    }

    for(int Y = 0; Y < MAP_HEIGHT; Y++)
    {
        for(int X = 0; X < MAP_WIDTH; X++)
        {
            CTile tempTile;
            int _TempTileID = 0;
            int _TempTypeID = 0;

            fscanf(FileHandle, "%d:%d ", &_TempTileID, &_TempTypeID);

            tempTile.SetTileID(_TempTileID);
            tempTile.SetTypeID(_TempTypeID);

            TileList.push_back(tempTile);
        }
        fscanf(FileHandle, "\n");
    }

    fclose(FileHandle);

    TileSheet.Load(pRenderer, "data/imgs/tiles/Tileset-Blocks.png", 255, 0, 255);

    return true;
}

void CMap::Render(SDL_Renderer* pRenderer)
{

    int ID = 0;

    for(int Y = 0; Y < MAP_HEIGHT_IN_TILES; Y++)
    {
        for(int X = 0; X < MAP_WIDTH_IN_TILES; X++)
        {
            if (TileList[ID].IsOnScreen(X * Tile.GetSize(),Y * Tile.GetSize()) == false)
            {
                ID++;
                continue;
            }
            else
            {
                if(TileList[ID].GetTileID() == 0) //No Tile
                {
                    ID++;
                    continue;
                }

                else if (TileList[ID].GetTileID() == 1) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 0, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }

                else if (TileList[ID].GetTileID() == 2) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 1, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }

                else if (TileList[ID].GetTileID() == 3) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 2, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 4) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 3, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 5) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 4, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 6) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 5, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 7) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 6, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 8) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize() * 7, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 9) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 8, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 10) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 9, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 11) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 0, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 12) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 1, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 13) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 2, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 14) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 3, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 15) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 4, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 16) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 5, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 17) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 6, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 18) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 7, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 19) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 0, Tile.GetSize() * 2, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 20) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 1, Tile.GetSize() * 2, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 21) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 2, Tile.GetSize() * 2, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 22) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 3, Tile.GetSize() * 2, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 23) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 4, Tile.GetSize() * 2, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 24) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 5, Tile.GetSize() * 2, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 25) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 6, Tile.GetSize() * 2, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 26) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 7, Tile.GetSize() * 2, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 27) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 0, Tile.GetSize() * 3, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 28) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 1, Tile.GetSize() * 3, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 29) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 2, Tile.GetSize() * 3, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 30) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 3, Tile.GetSize() * 3, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 31) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 4, Tile.GetSize() * 3, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 32) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 5, Tile.GetSize() * 3, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 33) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 6, Tile.GetSize() * 3, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 34) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 7, Tile.GetSize() * 3, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 35) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 0, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 36) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 1, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 37) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 2, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 38) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 3, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 39) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 4, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 40) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 5, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 41) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 6, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 42) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 7, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 43) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 8, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 44) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 9, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 45) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 10, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 46) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 11, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 47) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 12, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 48) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 13, Tile.GetSize() * 4, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 49) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 0, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 50) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 1, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 51) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 2, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 52) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 3, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 53) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 4, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 54) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 5, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 55) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 6, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 56) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 7, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 57) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 8, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 58) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 9, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 59) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 10, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 60) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 11, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 61) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 12, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 62) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 13, Tile.GetSize() * 5, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 63) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 0, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 64) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 1, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 65) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 2, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 66) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 3, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 67) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 4, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 68) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 5, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 69) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 6, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 70) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 7, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 71) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 8, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 72) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 9, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 73) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 10, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 74) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 11, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 75) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 12, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 76) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 13, Tile.GetSize() * 6, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 77) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 0, Tile.GetSize() * 7, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 78) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()* 1, Tile.GetSize() * 7, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 90) //Question Block
                {
                    TileList[ID].SetMaxFrames(2);
                    TileList[ID].Animate();
                    TileSheet.SetSourceRect(Tile.GetSize()* TileList[ID].GetCurrentFrame(), Tile.GetSize() * 8, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 91) //Coins
                {
                    TileList[ID].SetMaxFrames(2);
                    TileList[ID].Animate();
                    TileSheet.SetSourceRect(Tile.GetSize()* TileList[ID].GetCurrentFrame() + 96, Tile.GetSize() * 8, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
            }
        }
    }
}

int CMap::GetTypeOfTileAtPos(int X, int Y)
{
    return TileList[Y*MAP_WIDTH_IN_TILES + X].GetTypeID();
}

void CMap::SetTileAtPos(int X, int Y, int NewTile, int NewType)
{
    int IDtoOverwrite = Y * MAP_WIDTH_IN_TILES + X;

    TileList[IDtoOverwrite].SetTypeID(NewType);
    TileList[IDtoOverwrite].SetTileID(NewTile);

    "Overwritten...\n";
}
